#include "Graph.h"
#include <iostream>
#include <climits> 
using namespace std;

int main() {
    int mazeChoice; // variable to store chosen maze from player
    bool gameRunning = true; //boolean to determine if game should continue running 
    //handles restarting or exiting game
    while (gameRunning) {
        // user pick a maze
        cout << "Select a maze (1-5): ";
        cin >> mazeChoice;

        // initialize the map with the chosen maze
        Map gameMap(15); // maze size 
        gameMap.initializeMaze(mazeChoice);

        // track if player is caught by enemy
        bool playerCaught = false;
        while (!playerCaught && !gameMap.checkEndReached()) {
            system("clear");
            gameMap.display(); //display current state of maze
            //options to move player
            char move;
            cout << "Move (W/A/S/D): ";
            cin >> move;
            //moves player in specified direction
            gameMap.movePlayer(move);
            gameMap.moveEnemies();

            // check if the player was caught by an enemy
            playerCaught = gameMap.checkEnemyCollision();
        }

        // check if the player reached the end or got caught
        if (gameMap.checkEndReached()) {
            cout << "Congratulations! You've reached the end!" << endl;
        } else if (playerCaught) {
            cout << "You were caught by an enemy! Try again!" << endl;
        }

        // ask if the player wants to play again
        char playAgain;
        cout << "Do you want to play again? (Y/N): ";
        cin >> playAgain;

        if (playAgain == 'N' || playAgain == 'n') {
            gameRunning = false;
        }
    }
    // end if player chose N.
    cout << "Thanks for playing!" << endl;
    return 0;
}
