#include "Graph.h"
#include <iostream>
#include <climits>
using namespace std;

#define WALL 1
#define SECRET_PASSAGE 2
#define EMPTY 0

#define PLAYER_COLOR "\033[38;5;46m"
#define ENEMY_COLOR "\033[38;5;160m"
#define END_COLOR "\033[38;5;82m"
#define WALL_COLOR "\033[38;5;240m"
#define EMPTY_COLOR "\033[38;5;255m"
#define RESET_COLOR "\033[0m"
//initialize maze 
Map::Map(int size) : n(size) {
    //dynmaic arrays for terrain and distance and previous tracking
    terrain = new int*[n];
    dist = new int*[n];
    prev = new Position*[n];
    //initalize each row of arrays
    for (int i = 0; i < n; ++i) {
        terrain[i] = new int[n];
        dist[i] = new int[n];
        prev[i] = new Position[n];
    }
    //starting positions
    playerPos = Position(1, 1);
    enemy1Pos = Position(3, 3);
    enemy2Pos = Position(11, 11);
    endPos = Position(n - 2, n - 2);
}
//deallocate dynamically allocated memory
Map::~Map() {
    for (int i = 0; i < n; ++i) {
        delete[] terrain[i];
        delete[] dist[i];
        delete[] prev[i];
    }
    delete[] terrain;
    delete[] dist;
    delete[] prev;
}
//initalize maze based on uzers choice
void Map::initializeMaze(int choice) {
    fillMazeWithEmpty(); //initaially empty maze
    addBoundaryWalls(); // create
    
    if (choice == 1) {
        terrain[2][2] = WALL; terrain[6][3] = WALL;terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][12] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[13][7] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[8][6] = WALL; terrain[9][6] = WALL;terrain[11][1] = WALL;terrain[8][13] = WALL;
        terrain[13][12] = WALL;terrain[8][1] = WALL;terrain[12][6] = WALL;terrain[11][9] = WALL;
        terrain[4][8] = WALL; terrain[4][9] = WALL;terrain[4][7] = WALL; terrain[4][6] = WALL;
        terrain[4][5] = WALL; terrain[9][11] = WALL;terrain[2][4] = WALL;terrain[2][3] = WALL; 
        terrain[10][9] = WALL;terrain[3][7] = WALL; terrain[5][2] = WALL; 
        terrain[9][12] = WALL;terrain[1][8] = WALL; terrain[1][6] = WALL; terrain[2][3] = WALL;
        //walls for secret path
        terrain[7][5] = SECRET_PASSAGE;terrain[7][6] = SECRET_PASSAGE; terrain[7][8] = SECRET_PASSAGE;
        terrain[7][9] = SECRET_PASSAGE;terrain[7][7] = SECRET_PASSAGE; terrain[7][10] = SECRET_PASSAGE;
        terrain[7][11] = SECRET_PASSAGE; terrain[6][11] = SECRET_PASSAGE;terrain[8][5] = SECRET_PASSAGE;
        }else if (choice == 2) {
        terrain[2][2] = WALL; terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[8][6] = WALL; terrain[9][6] = WALL;terrain[11][1] = WALL;terrain[5][7] = WALL;
        terrain[13][12] = WALL;terrain[8][1] = WALL;terrain[12][6] = WALL;terrain[11][9] = WALL;
        terrain[4][8] = WALL; terrain[4][9] = WALL;terrain[4][7] = WALL; terrain[4][6] = WALL;
        terrain[4][5] = WALL; terrain[9][11] = WALL;terrain[2][4] = WALL;terrain[2][3] = WALL; 
        terrain[10][9] = WALL; terrain[5][2] = WALL; terrain[13][3] = WALL;terrain[12][3] = WALL;
        terrain[9][12] = WALL;terrain[1][8] = WALL; terrain[1][6] = WALL; terrain[2][3] = WALL;
        //walls for secret path
        terrain[7][5] = SECRET_PASSAGE;terrain[7][6] = SECRET_PASSAGE; terrain[7][8] = SECRET_PASSAGE;
        terrain[7][9] = SECRET_PASSAGE;terrain[7][7] = SECRET_PASSAGE; terrain[7][10] = SECRET_PASSAGE;
        terrain[7][11] = SECRET_PASSAGE; terrain[8][11] = SECRET_PASSAGE;terrain[6][5] = SECRET_PASSAGE;
        }
        else if (choice == 3) {
        terrain[2][2] = WALL; terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[8][6] = WALL; terrain[9][6] = WALL;terrain[11][1] = WALL;terrain[5][7] = WALL;
        terrain[2][2] = WALL; terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[5][11] = SECRET_PASSAGE; terrain[8][2] = WALL;
        terrain[3][5] = WALL; terrain[6][8] = SECRET_PASSAGE;terrain[7][5] = SECRET_PASSAGE;terrain[7][6] = SECRET_PASSAGE; terrain[7][8] = SECRET_PASSAGE;
        terrain[7][9] = SECRET_PASSAGE;terrain[7][7] = SECRET_PASSAGE; terrain[7][10] = SECRET_PASSAGE;
        terrain[7][11] = SECRET_PASSAGE; terrain[8][11] = SECRET_PASSAGE;terrain[6][5] = SECRET_PASSAGE;
        terrain[6][5] = WALL; terrain[6][6] = WALL; terrain[5][5] = WALL;
        terrain[9][4] = WALL; terrain[10][6] = WALL; terrain[3][4] = WALL;
        }
        else if (choice == 4) {
        terrain[2][2] = WALL; terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[6][6] = WALL; terrain[11][7] = WALL; 
        terrain[3][5] = WALL; terrain[12][4] = WALL; 
        terrain[7][3] = WALL; terrain[9][7] = WALL;
        terrain[6][7] = WALL; terrain[5][6] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[8][6] = WALL; terrain[9][6] = WALL;terrain[11][1] = WALL;terrain[5][7] = WALL;
        terrain[2][2] = WALL; terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[7][5] = SECRET_PASSAGE;terrain[7][6] = SECRET_PASSAGE; terrain[7][8] = SECRET_PASSAGE;
        terrain[7][9] = SECRET_PASSAGE;terrain[7][7] = SECRET_PASSAGE; terrain[7][10] = SECRET_PASSAGE;
        terrain[7][11] = SECRET_PASSAGE; terrain[8][11] = SECRET_PASSAGE;terrain[6][5] = SECRET_PASSAGE;
        }
        else if (choice == 5) {
        terrain[2][2] = WALL; terrain[10][3] = WALL; 
        terrain[5][3] = WALL; terrain[12][9] = WALL;terrain[3][2] = WALL;terrain[4][2] = WALL;
        terrain[4][7] = WALL; terrain[8][3] = WALL; terrain[12][7] = WALL;terrain[12][8] = WALL;
        terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[3][2] = WALL; terrain[5][2] = WALL; terrain[5][3] = WALL; 
        terrain[6][3] = WALL; terrain[6][4] = WALL; terrain[8][4] = WALL;
        terrain[12][5] = WALL;
        terrain[12][6] = WALL; terrain[13][6] = WALL; terrain[14][6] = WALL;
        terrain[13][7] = WALL;
        terrain[8][5] = SECRET_PASSAGE; 
        terrain[8][6] = WALL; terrain[9][6] = WALL;terrain[11][1] = WALL;terrain[5][7] = WALL;
        terrain[13][12] = WALL;terrain[8][1] = WALL;terrain[12][6] = WALL;terrain[11][9] = WALL;
        terrain[4][8] = WALL; terrain[4][9] = WALL;terrain[4][7] = WALL; terrain[4][6] = WALL; terrain[9][3] = WALL; terrain[2][10] = WALL;terrain[2][11] = WALL;terrain[3][11] = WALL;
        terrain[12][7] = WALL;terrain[10][4] = WALL;terrain[4][11] = WALL;terrain[12][12] = WALL;
        terrain[5][11] = WALL;terrain[6][11] = WALL;terrain[6][10] = WALL;terrain[6][9] = WALL;
        terrain[6][8] = WALL; terrain[7][8] = WALL;terrain[8][8] = WALL;terrain[8][7] = WALL;
        terrain[5][11] = SECRET_PASSAGE; terrain[8][2] = WALL;
        terrain[3][5] = WALL; terrain[6][8] = SECRET_PASSAGE;terrain[7][5] = SECRET_PASSAGE;terrain[7][6] = SECRET_PASSAGE; terrain[7][8] = SECRET_PASSAGE;
        terrain[7][9] = SECRET_PASSAGE;terrain[7][7] = SECRET_PASSAGE; terrain[7][10] = SECRET_PASSAGE;
        terrain[7][11] = SECRET_PASSAGE; terrain[8][11] = SECRET_PASSAGE;terrain[6][5] = SECRET_PASSAGE;
        terrain[6][5] = WALL; terrain[6][6] = WALL; terrain[5][5] = WALL;
        terrain[9][4] = WALL; terrain[10][6] = WALL; terrain[3][4] = WALL;
       } else {
            cout << "Invalid choice. Default maze initialized." << endl;
        }
        }
//displays cirrent state of maze
void Map::display() const {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            //checks if current position is players position
            if (Position(i, j) == playerPos)
                cout << PLAYER_COLOR << "☺☺" << RESET_COLOR;
                //checks if current position is one of enemies positions
            else if (Position(i, j) == enemy1Pos || Position(i, j) == enemy2Pos)
                cout << ENEMY_COLOR << "☹☹" << RESET_COLOR;
                //checks if current position is finish line
            else if (Position(i, j) == endPos)
                cout << END_COLOR << "🏁 " << RESET_COLOR;
                //checks if current position is secret passage
            else if (terrain[i][j] == SECRET_PASSAGE)
                cout << "\033[38;5;214m" << "♦ " << RESET_COLOR;
                //checks if current position is wall
            else if (terrain[i][j] == WALL)
                cout << WALL_COLOR << "█ " << RESET_COLOR;
                //if position is empy
            else
                cout << EMPTY_COLOR << ". " << RESET_COLOR;
        }
        cout << endl;
    }
    //displays number of moves required to reach finish line
    if (dist[endPos.x][endPos.y] != INT_MAX) { 
    cout << "Moves until finish line: " << dist[endPos.x][endPos.y] << endl;
} else {
    cout << "No path to the finish line!" << endl;
}
}
//moves enemies within the maze
void Map::moveEnemies() {
    moveEnemy(enemy1Pos);//fist enemy
    moveEnemy(enemy2Pos);//secind enemy
}
//move player on WASD input
void Map::movePlayer(char move) {
    Position newPos = playerPos;//creates new position based on current position
    if (move == 'W' || move == 'w') newPos.x--;//decrease x coordinate
    else if (move == 'S' || move == 's') newPos.x++;//increase x coordinate
    else if (move == 'A' || move == 'a') newPos.y--;//decrease y coordinate
    else if (move == 'D' || move == 'd') newPos.y++;//increase y coordinate
    //checks if new position is valid move
    if (isValidMove(newPos, true)) { 
        playerPos = newPos;//updates player position
    }
}
//checks if player caught by enemy
bool Map::checkEnemyCollision() {
    //returns true if player cuaght by enemy
    return (playerPos == enemy1Pos || playerPos == enemy2Pos);
}
//checks if player reached finish line
bool Map::checkEndReached() {
    //return true if player position equal to finish line
    return (playerPos == endPos);
}
//fiinds shortest path to finsih line (Dijkstra)
void Map::findShortestPath() {
    //initalize distance and previous position arrays
    for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INT_MAX;
                prev[i][j] = Position(-1, -1);
            }
        }
        dist[playerPos.x][playerPos.y] = 0;// starting position

        for (int step = 0; step < n * n; ++step) {
            int minDist = INT_MAX;//set distances to max 
            Position minPos(-1, -1);//initialize prev positions to invlaid
            //performs Dijkstra
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    Position p(i, j);
                    if (terrain[i][j] != WALL && dist[i][j] < minDist) {
                        minDist = dist[i][j];
                        minPos = p;
                    }
                }
            }

            //if (minPos.x == -1) 
            // movements 
            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};
            //explores neighboring position
            for (int i = 0; i < 4; ++i) {
                Position neighbor(minPos.x + dx[i], minPos.y + dy[i]);
                //if valid updates dist and prev position
                if (isValidMove(neighbor, true)) {
                    int newDist = dist[minPos.x][minPos.y] + 1;// increase distance by 1
                    if (newDist < dist[neighbor.x][neighbor.y]) {
                        dist[neighbor.x][neighbor.y] = newDist;
                        prev[neighbor.x][neighbor.y] = minPos; //sets current position as prev for neighbor
                    }
                }
            }
        }

    }
    
//checks if move to new position is valid
bool Map::isValidMove(const Position& newPos, bool allowSecretPassages) const {
    //check if within bounds
    if (newPos.x < 0 || newPos.y < 0 || newPos.x >= n || newPos.y >= n) return false;
    //checks possitions isnt wall
    if (terrain[newPos.x][newPos.y] == WALL) return false;
    //check id screpassage which isnt allwoed
    if (terrain[newPos.x][newPos.y] == SECRET_PASSAGE && !allowSecretPassages) return false;
    return true;//true if all are satisfied
}
//add border walls around maze
void Map::addBoundaryWalls() {
    //set walls top ,bottom, left, right
    for (int i = 0; i < n; ++i) {
        terrain[i][0] = WALL;
        terrain[i][n - 1] = WALL;
        terrain[0][i] = WALL;
        terrain[n - 1][i] = WALL;
    }
}
//fills maze with entire space
void Map::fillMazeWithEmpty() {
    //sets all positions in maze to empty
   for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                terrain[i][j] = EMPTY;
}
//moves enemy towards player
void Map::moveEnemy(Position& enemyPos) {
    int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        Position bestMove = enemyPos;//choose best move off of current position
        int minDist = INT_MAX;//initialize min distance to large value
        //check neighbors to find best move
        for (int i = 0; i < 4; ++i) {
            Position newPos(enemyPos.x + dx[i], enemyPos.y + dy[i]);
            //if valid new position check the distance to player
            if (isValidMove(newPos, false)) {
                int distance = newPos.manhattanDistance(playerPos);
                if (distance < minDist) {
                    minDist = distance;//update min distance
                    bestMove = newPos;// update best move to current neighbor position
                }
            }
        }
        enemyPos = bestMove; //updates to best position for best move
    }


// g++ used to compile c++ files