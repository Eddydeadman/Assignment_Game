#pragma once
// Level.h
// Made by 15010974
// last modified: 16/01/2020
#include "GameObject.h"

class Level : public GameObject
{
private:
	ObjectManager& theManager; //reference to the object manager
	float asteroidtimer; //time until another asteroid can be created
public:
	Level(ObjectManager& Manager);
	~Level();
	void Initialise(); //Initialises the Level
	void Update(float frametime); //Updates the Level
	void Collision(); //empty function, please Ignore
	void CreatePlayer(); //creates a new spaceship
	void CreateAsteroid(); //creates a new asteroid
};