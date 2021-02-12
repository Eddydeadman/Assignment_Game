// CollisionComponent.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "CollisionComponent.h"
#include "GameObject.h"
#include<typeinfo>



CollisionComponent::CollisionComponent() {
	size = 1.0;	
}

//returns the shape of the owner, in the position required
IShape2D& CollisionComponent::GetShape(GameObject* pOwner) {	
	Vector2D position = pOwner->getPosition();
	shape.PlaceAt(position, size);
	return shape;
	
}

//sets the size
void CollisionComponent::SetSize(float newSize) {
	size = newSize;
}

//checks the collision between pOwner and the pOther
void CollisionComponent::Update(GameObject* pOther, GameObject* pOwner)
{

	if (pOther->getType() != pOwner->getType()) {
		IShape2D& otherShape = pOther->GetCollisionComp()->GetShape(pOther);	
		if (GetShape(pOwner).Intersects(otherShape)) {
			pOwner->Collision();
			pOther->Collision();
		}
	}
}
