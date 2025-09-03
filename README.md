 *Creator
    Harsharan Dhillon
    Fresno State CSCI 115


 *Maze Game Project
 To compile code copy paste this executable into terminal: g++ -o maze_game main.cpp Graph.cpp Position.cpp
 Then to run the compiled code copy paste: ./maze_game

*Overview  
This is a console-based maze game implemented in C++. The player navigates through a maze, aiming to reach the goal while avoiding enemies. The game features multiple maze layouts, secret passages, and strategic enemy movement.  

*Features  
 Dynamic Maze Layouts:** Five different maze designs with walls, empty spaces, secret passages, and dirt blocks.  
 Player Movement:** Use `W`, `A`, `S`, and `D` to move up, l
 ft, down, and right respectively.  
 Enemy AI:** Enemies attempt to catch the player using Dijkstra's shortest path algorithm with occasional random movements.  
 Visual Representation:** Color-coded maze elements for walls, enemies, the player, and the goal.  

*Controls  
`W`: Move up  
`A`: Move left  
`S`: Move down  
`D`: Move right  

*Maze Elements  
Walls (`█`)**: Blocks movement.  
Dirt (`.`)**: Walkable paths.  
Secret Passages (`■`)**: Hidden pathways for the player only.  
Player (`☺`)**: Your position in the maze.  
Enemies (`☹`)**: Avoid these as they will chase you.  
Goal (`🏁`)**: The end position to win the game.  

*Gameplay  
The game starts with the player, enemies, and goal initialized in predefined positions.  
Navigate the maze using the controls to reach the goal.  
Enemies move each turn, attempting to catch the player.  
Use strategy to take advantage of secret passages and avoid the enemies.  

*Maze Configurations  
The game includes five predefined mazes.  
Each maze has the following features:  
Walls (`█`)**: Surround and define the maze structure.  
Dirt (`.`)**: Allow the player and enemies to move freely.  
Secret Passages (`■`)**: Accessible only by the player, offering shortcuts or escape routes.  

*The project is organized into multiple files for modularity:
Header Files (.h):
Map.h: Manages the maze representation.
Graph.h: Handles graph-related operations like Dijkstra's algorithm.
Position.h: Defines player and enemy positions.

Source Files (.cpp):
Map.cpp: Implementation of maze operations.
Graph.cpp: Implementation of graph traversal and shortest path algorithms.
Position.cpp: Implementation of player/enemy movement logic.

Main File:
main.cpp: The entry point, integrating all components.# MazeGame
