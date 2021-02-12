#pragma once
// Bullet.h
// Made by 15010974
// last modified: 16/01/2020
#include "GameObject.h"

class Bullet : public GameObject
{
private:

public:
	Bullet(RenderComponent* pRender, CollisionComponent* pCollision, MovementComponent* pMove);
	~Bullet();
	void Initialise(Vector2D pos, Vector2D vel); //initialise the bullet: pos = start position, vel bullet velocity
	void Update(float frametime);// update the bullet - prevents out-of-bounds activity
	void Collision(); //process bullet collision
};
