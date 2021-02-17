# Assignment_Game
Assignment given to build a game object managment system, and game using a partialy built engine
As part of this assignment I chose to impliment a component system over an animation system or level managment system

TODO:
1) Remove coupling in spaceship and controller (have the controller return a bool for fire mechanic??) - enables an AI controller to be placed on the ship
2) Add generic component which all components inherit from (allows greater future modularity)
3) Add individual list for each main component type to object manager (need to figure out how to delete these components during cleanup - possible to get the pointer and set to null?)
4) Rework collision system - i) hitbox object - contains shape, size, and relative position/angle
                            ii) hitbox array in component - used for comparisons of the "hit"
                           iii) better way of determining what object hit this object and decision making based on this                           
5) Score system
6) Enemy Ships?? - have a generic controller class and have an AI controller and player controller inherit from it?
