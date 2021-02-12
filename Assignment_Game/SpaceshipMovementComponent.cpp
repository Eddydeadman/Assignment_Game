// SpaceshipMovementComponent.cpp
// Made by: 15010974
// last modified: 13/01/2020

#include "SpaceshipMovementComponent.h"
//default constructor
SpaceshipMovementComponent::SpaceshipMovementComponent() 
{
	rotation = 0.0f;
	bearing.setBearing(0, 0);
}

//updates movement of an objects with friction
void SpaceshipMovementComponent::update(GameObject* pOwner, float frametime)
{
	
	pOwner->setAngle(pOwner->getAngle() + rotation * frametime);
	bearing = bearing + acceleration * frametime;
	acceleration.set(0, 0);
	rotation = 0.0f;
	Vector2D pos = pOwner->getPosition();
	Vector2D friction;
	friction = (bearing * -0.7);
	bearing = bearing + (friction*frametime);
	pos = pos + (bearing * frametime);
	pOwner->setPosition(pos);
}

//set acceleration of pOwner by amount
void SpaceshipMovementComponent::accelerate(GameObject* pOwner, float amount)
{
	acceleration.setBearing(pOwner->getAngle(), amount);
}

//rotate spaceship by amount
void SpaceshipMovementComponent::rotate(float amount)
{
	rotation = amount;
}