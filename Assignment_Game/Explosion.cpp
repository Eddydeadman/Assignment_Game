// Explosion.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "Explosion.h"

Explosion::Explosion(float scale, RenderComponent* pRender) 
{
	pRenderComponent = pRender;
	pCollisionComponent = nullptr;
	pMovementComponent = nullptr;
	this->scale = scale;

}

Explosion::~Explosion()
{
	if (pRenderComponent != nullptr) {
		delete pRenderComponent;
	}
	if (pCollisionComponent != nullptr) {
		delete pCollisionComponent;
	}
	if (pMovementComponent != nullptr) {
		delete pMovementComponent;
	}
}

//initialise the explosion, 
//Vector2D pos: the position the explosion is set to
void Explosion::Initialise(Vector2D pos)
{
	images[0] = pRenderComponent->GetNewImage(L"explosion1.bmp");
	images[1] = pRenderComponent->GetNewImage(L"explosion2.bmp");
	images[2] = pRenderComponent->GetNewImage(L"explosion3.bmp");
	images[3] = pRenderComponent->GetNewImage(L"explosion4.bmp");
	images[4] = pRenderComponent->GetNewImage(L"explosion5.bmp");
	images[5] = pRenderComponent->GetNewImage(L"explosion6.bmp");
	images[6] = pRenderComponent->GetNewImage(L"explosion7.bmp");
	images[7] = pRenderComponent->GetNewImage(L"explosion8.bmp");
	pRenderComponent->SetImage(images[0]);
	currentImage = 0.0f;
	active = true;
	position = pos;
	MySoundEngine* pMSE = MySoundEngine::GetInstance();
	SoundIndex explosion = pMSE->LoadWav(L"explosion5.wav");
	pMSE->SetVolume(explosion, -1000);
	pMSE->Play(explosion);
}
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     

//update the explosion
void Explosion::Update(float frametime)
{
	currentImage = currentImage + (3.0f * frametime);
	int current = currentImage;
	pRenderComponent->SetImage(images[current]);
	if (current >= 8.0f) {
		active = false;
	}
}

//empty method - never called due to no collision component
void Explosion::Collision()
{
}
