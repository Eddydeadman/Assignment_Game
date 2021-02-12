// MovementComponent.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "MovementComponent.h"
#include "GameObject.h"


//default constrictor
MovementComponent::MovementComponent()
{
	bearing.setBearing(0,0);
}

//updates movement of an objects
void MovementComponent::update(GameObject* pOwner, float frametime)
{
	Vector2D pos = pOwner->getPosition();
	pos = pos + (bearing * frametime);
	pOwner->setPosition(pos);	
}

//sets the bearing, using a vector2D
void MovementComponent::setBearing(Vector2D newBearing)
{	
	bearing.setBearing(newBearing.angle(),newBearing.magnitude());
}

//sets the bearing, using angle and magnitude
void MovementComponent::setBearing(float ang, float mag)
{	
	bearing.setBearing(ang, mag);
}

//returns the bearing
Vector2D MovementComponent::getBearing()
{
	return bearing;
}
