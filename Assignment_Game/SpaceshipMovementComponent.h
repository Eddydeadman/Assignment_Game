#pragma once
// SpaceshipMovementComponent.h
// Made by 15010974
// last modified: 16/01/2020
#include "GameObject.h"

class SpaceshipMovementComponent: public MovementComponent
{
private:
	Vector2D acceleration; //acceleration of the ownere
	float rotation; //rotation of the owner
public:
	SpaceshipMovementComponent();
	void update(GameObject* pOwner, float frametime)override; //updatees the movement of pOwner, while also accounting for friction
	void accelerate(GameObject* pOwner, float amount); //updates the acceleration being added by pOwner
	void rotate(float amount);  //updates the rotation
};