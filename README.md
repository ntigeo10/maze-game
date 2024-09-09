**Simple Maze Game**

This is a simple maze game developed for my Object-Oriented Programming class. The whole purpose of it is for the player (Loukas) to obtain the Stone - which teleports after a random amount of seconds - before the opponent (who is named Mpampis). 

***Entities**

Entity.h and Entity.cpp contain the class Entity and it's getters and setters for the XY positions and the entities symbol. Also, it contains two virtual voids that each entity (Stone, Mpampis and Loukas) uses to define its movements and how it will be drawn on the map. 

- Loukas: The user controls its movement with the arrow keys and is displayed on the map with a green L.
- Mpampis: Though buggy, Mpampis moves on his own. A new method should be developed here to get the position of the stone and find the optimal path. It is displayed with a red M.
- Stone: The stone is positioned on a random point of the map (Not inside any walls as it was tested) and teleports after a short and random period of time. It is displayed with a cyan S on the map.

**Maps**

Map.h and Map.cpp contain any code related to the map creation based on an imported .txt file. The walls are defined with the symbol * and the path with the symbol .

**Engine**

Engine.h and Engine.cpp is the engine of the program and puts all the elements on display on the monitor. Library ncurses was used to draw the elements on the monitor.

**Main**

main.cpp initializes the engine and allows the game to begin. When running the program on Linux, the user has to include one of the two maze text files when executing main.exe (when compiled) or else it will throw an error message. 

