#pragma once
// CollisionComponent.h
// Made by 15010974
// last modified: 16/01/2020
#include "Shapes.h"

class GameObject;
class Spaceship;

class CollisionComponent
{
	
public:
	CollisionComponent();
	IShape2D& GetShape(GameObject* pOwner); //returns the shape used to detect collision
	void SetSize(float newSize); //sets the size of the shape used for collision
	void Update(GameObject* pOther, GameObject* pOwner); //checks for and processes the collision between pOwner & pOther
private:
	Circle2D shape;//collision hitbox shape
	float size;//collision hitbox size
};