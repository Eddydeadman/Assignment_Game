#pragma once
// MovementComponent.h
// Made by 15010974
// last modified: 16/01/2020
#include "vector2D.h"

class GameObject;

class MovementComponent
{
private:

protected:
	Vector2D bearing; //bearing of the object
public:
	MovementComponent();
	virtual void update(GameObject* pOwner, float frametime); //updates the position of pOwner using bearing
	void setBearing(Vector2D newBearing); //sets a new bearing using a Vector2D
	void setBearing(float ang, float mag); //sets a new bearing using an angle float, and a magnitude float
	Vector2D getBearing(); //returns the bearing
};