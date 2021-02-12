// GameObject.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "GameObject.h"

using namespace std;

GameObject::GameObject()
{
	active = false;
	position.set(0, 0);
	angle = 0.0;
	scale = 1.0;
	transparency = 0.0;
}

GameObject::~GameObject()
{
}

//returns active
bool GameObject::isActive()
{
	return active;
}

//returns the type info
const type_info& GameObject::getType()
{
	return typeid(*this);
}

//gets the render component
RenderComponent* GameObject::GetRenderComp() 
{
	return pRenderComponent;
}

//gets the collision component
CollisionComponent* GameObject::GetCollisionComp()
{
	return pCollisionComponent;
}

//gets the movement component
MovementComponent* GameObject::GetMovementComp()
{
	return pMovementComponent;
}

//gets the position
Vector2D GameObject::getPosition() {
	return position;
}

//sets the position
void GameObject::setPosition(Vector2D newPosition)
{
	position.set(newPosition);
}

//gets the angle
float GameObject::getAngle() {
	return angle;
}

//sets the angle to equal ang
void GameObject::setAngle(float ang) {
	angle = ang;
}

//returns scale
float GameObject::getScale() {
	return scale;
}

//returns Transparency
float GameObject::getTransparency() {
	return transparency;
}