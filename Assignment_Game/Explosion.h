#pragma once
// Explosion.h
// Made by 15010974
// last modified: 16/01/2020

#include "GameObject.h"

class Explosion : public GameObject
{
public:
	Explosion(float scale, RenderComponent* pRender);
	~Explosion();
	void Initialise(Vector2D pos);//initialises the explosion: pos = position the explosion will be set to
	void Update(float frametime); //updates the explosion: frametime = time to render a frame
	void Collision(); //empty function, never called, please ignore
private:
	float currentImage; //the current index of the array used for animating the explosion
	PictureIndex images[8]; // array of sprites used for rendering the explosion
	
};