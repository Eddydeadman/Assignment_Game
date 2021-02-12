#pragma once
// RenderComponent.h
// Made by 15010974
// last modified: 16/01/2020
#include "mydrawengine.h"
class GameObject;

class RenderComponent
{
	PictureIndex render; //image to be rendered
	MyDrawEngine* pDE; //reference to the draw engine
public:
	RenderComponent(const wchar_t* filename);
	void Update(GameObject* pOwner); //renders pOwner using variables from pOwner
	void SetImage(const wchar_t* filename); //sets the image to be rendered using a filename
	void SetImage(PictureIndex pic); //sets the image to be rendered using a PictureIndex
	PictureIndex GetNewImage(const wchar_t* filename); //returns a PictureIndex of a specified filename
};