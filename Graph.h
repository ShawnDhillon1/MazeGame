#ifndef GRAPH_H
#define GRAPH_H

#include "Position.h"

class Map {
private:
    int n; //size of maze
    int** terrain;// array representing maze layout(wall/secret path)
    Position playerPos;//curent poition of player in maze
    Position enemy1Pos, enemy2Pos;//position of both enemies
    Position endPos;//end point of maze
    
    int** dist; // stores distance for Dijkstra
    Position** prev; // stores previous positions for path

public:
    Map(int size);//allocates memory for terrain
    ~Map();//deconstructor/ cleans up allocated memory // bitwise flips bit 1-0 and 0-1

    void initializeMaze(int choice);//initalize chosen maze layout 1-5
    void display() const;//visual of maze for player
    void moveEnemies();//updates enemy avoiding walls and secret path
    void movePlayer(char move);//updates players position if valid move 
    bool checkEnemyCollision();//check if enemy caught player
    bool checkEndReached();//check if player reached end
    void findShortestPath();//uses dijktra to find shortest path from players position
    bool isValidMove(const Position& newPos, bool allowSecretPassages) const;//checks if move is valid
    void addBoundaryWalls();//ensures player and enemies stay in maze
    void fillMazeWithEmpty();//open path move freely
    void moveEnemy(Position& enemyPos);//moves enemy to new position and updates position in maze
};

#endif
