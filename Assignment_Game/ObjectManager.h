#pragma once
// ObjectManager.h
// Made by 15010974
// last modified: 16/01/2020

#include<list>


using namespace std;
class GameObject;
class ObjectManager
{
public:

	ObjectManager();

	void AddObject(GameObject* pNewObj); //adds a GameObject pointer to pObjects: pNewObj = the GameObject pointer to be added
	void UpdateAll(float frameTime); //updates all objects in pObjects
	void UpdateMovement(float frametime); //updates all objects containing movement Components in pObjects
	void RenderAll(); //updates all objects containing render Components in pObjects
	void CheckCollisions(); //updates all objects containing collision Components in pObjects
	void DeleteAll(); //Deletes all objects in pObejcts
	void DeleteInactive(); //Deletes all inactive objects in pObejcts

private:
	list<GameObject*> pObjects; //list of game object pointer
};

