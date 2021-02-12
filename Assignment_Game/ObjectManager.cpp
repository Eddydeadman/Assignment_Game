// ObjectManager.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "ObjectManager.h"
#include "GameObject.h"
#include<algorithm>


using namespace std;

ObjectManager::ObjectManager() {

}

//adds an object to the list
void ObjectManager::AddObject(GameObject* pNewObj) 
{	
	pObjects.push_back(pNewObj);
}

//updates every object in the list
void ObjectManager::UpdateAll(float frametime) 
{
	for (GameObject* nextGameObj : pObjects) 
	{
		if (nextGameObj->isActive() == true) {
			nextGameObj->Update(frametime);
			//during this update the controls
		}			
	}
}

//updates the mvoement of every object in the list
void ObjectManager::UpdateMovement(float frametime)
{
	for (GameObject* nextGameObj : pObjects)
	{
		if (nextGameObj->GetMovementComp() != nullptr) {
			nextGameObj->GetMovementComp()->update(nextGameObj, frametime);
		}
	}
}

//renders every object in the list
void ObjectManager::RenderAll() 
{
	for (GameObject* nextGameObj : pObjects)
	{
		if ((nextGameObj->GetRenderComp() != nullptr)&&(nextGameObj->isActive())) {
			nextGameObj->GetRenderComp()->Update(nextGameObj);
		}
	}
}

//checks the collisions of every object
void ObjectManager::CheckCollisions() {
	list<GameObject*>::iterator it1;
	list<GameObject*>::iterator it2;
	for (it1 = pObjects.begin(); it1 != pObjects.end(); it1++) {
		if ((*it1)->GetCollisionComp() != nullptr){
			for (it2 = next(it1); it2 != pObjects.end(); it2++) {
				if ((*it2)->GetCollisionComp() != nullptr) {
					(*it1)->GetCollisionComp()->Update((*it2), (*it1));
				}
			}	
		}
	}
}

//deletes all objects in the list
void ObjectManager::DeleteAll() 
{
	//cycle through list
	for (GameObject* nextGameObj : pObjects)
	{
		//delete the object
		delete nextGameObj;
		
		nextGameObj = nullptr;
	}
	//clear the list
	pObjects.clear();
}

//deletes objects in the list where active is false
void ObjectManager::DeleteInactive()
{
	//cycle through list
	for (GameObject* &nextGameObj : pObjects)
	{
		//check avtivity
		if(nextGameObj->isActive()==false)
		{
			//delete the object
			delete nextGameObj;
			nextGameObj = nullptr;
		}
	}
	//mark for removal
	auto it = remove(pObjects.begin(), pObjects.end(), nullptr);
	//remove from list
	pObjects.erase(it, pObjects.end());
}