#pragma once
// Asteroid.h
// Made by 15010974
// last modified: 16/01/2020

#include "GameObject.h"


class Asteroid : public GameObject
{
public:
	Asteroid(RenderComponent* pRender, CollisionComponent* pCollision, MovementComponent* pMove, ObjectManager& Manager);
	~Asteroid();
	void Initialise(); //initialise the asteroid

	void Update(float frametime); //update the asteroid - frametime = the time taken to render the frame
	void Collision(); // process the collision

private:
	ObjectManager& theManager; //reference to the object manager
	float spin; // makes the asteroid spin
};
