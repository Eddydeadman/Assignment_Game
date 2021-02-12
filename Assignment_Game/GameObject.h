#pragma once
// GameObject.h
// Made by 15010974
// last modified: 16/01/2020

#include "vector2D.h"
#include "CollisionComponent.h"
#include "MovementComponent.h"
#include "RenderComponent.h"
#include "mysoundengine.h"
#include<typeinfo>

class ObjectManager;
class GameObject
{
	
public:
	
	GameObject();
	virtual ~GameObject();
	virtual void Update(float frametime) = 0; //abstract update function
	virtual void Collision() = 0; // abstract collision function
	bool isActive(); //returns the active variable
	const type_info& getType(); //returns the object type of the GameObject
	RenderComponent* GetRenderComp(); //returns the Render Component
	CollisionComponent* GetCollisionComp(); //returns the Collision Component
	MovementComponent* GetMovementComp(); //returns the Movememt Component
	Vector2D getPosition(); //returns the position
	void setPosition(Vector2D newPosition); //sets the position of the GameObject: newPosition is the position the the object will be set to
	float getAngle(); // returns the angle of the Object
	void setAngle(float ang); //sets the angle of the Object: ang = the new angle to set the obejct to
	float getScale();//returns the scale of the object
	float getTransparency(); //returns the transparency of the object

protected:
	Vector2D position; //position of the object
	float angle; //angle of the object
	float scale; //scale of the object
	float transparency; //transparency of the object
	bool active; //true if object is active
	RenderComponent* pRenderComponent; //render component of the object
	CollisionComponent* pCollisionComponent;//collision component of the object
	MovementComponent* pMovementComponent; //movement component of the object
};
