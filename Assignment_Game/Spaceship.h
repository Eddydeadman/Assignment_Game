#pragma once
// Spaceship.h
// Made by 15010974
// last modified: 16/01/2020
#include "GameObject.h"

class SpaceshipMovementComponent;
class InputsComponent;

class Spaceship : public GameObject
{
private:

	ObjectManager& theManager; //reference to the object Manager
	int health; //health of the spaceship
	float invulnrableTime; //amount of time the ship is invulnerable for
	InputsComponent* pInputs; //reference to the inputs component

public: 
	Spaceship(RenderComponent* pRender, CollisionComponent* pCollide, SpaceshipMovementComponent* pMove, ObjectManager& Manager);
	~Spaceship();
	void Initialise();//initialises the spaceship
	void Update(float frametime); //updates the spaceship
	void Shoot(); //creates and fires a bullet from the spaeship
	void Collision(); //processes collision

};
