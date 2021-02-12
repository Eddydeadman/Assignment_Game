// RenderComponent.cpp
// Made by: 15010974
// last modified: 13/01/2020

#include "RenderComponent.h"
#include "GameObject.h"

using namespace std;

//filename is the filename of the image to be rendered
RenderComponent::RenderComponent(const wchar_t* filename){
	pDE = MyDrawEngine::GetInstance();
	SetImage(filename);
}

//draws the owner on screen according to the GameObject properties
void RenderComponent::Update(GameObject* pOwner) 
{
	Vector2D pos;
	pos.set(pOwner->getPosition());
	float scale = pOwner->getScale();
	float ang = pOwner->getAngle();
	float trans = pOwner->getTransparency();
	pDE->DrawAt(pos, render, scale, ang, trans);
}

//sets the image that the render component will draw via filename
void RenderComponent::SetImage(const wchar_t* filename) 
{
	render = pDE->LoadPicture(filename);
}

//sets the image that the render component will draw via Picture Index
void RenderComponent::SetImage(PictureIndex pic)
{
	render = pic;
}

//returns a picture index of a specified file name
PictureIndex RenderComponent::GetNewImage(const wchar_t* filename)
{	
	PictureIndex pic = pDE->LoadPicture(filename);
	return pic;
}
