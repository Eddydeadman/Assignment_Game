// Bullet.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "Bullet.h"


using namespace std;

Bullet::Bullet(RenderComponent* pRender, CollisionComponent* pCollision, MovementComponent* pMove) 
{
	pRenderComponent = pRender;
	pCollisionComponent = pCollision;
	pMovementComponent = pMove;
	active = false;
}

Bullet::~Bullet()
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

//give the bullet a start position and velocity, activate itm and set the image and collision box size
void Bullet::Initialise(Vector2D pos, Vector2D vel) 
{	
	position.set(pos);
	angle = vel.angle();
	active = true;
	pRenderComponent->SetImage(L"plasma.bmp");
	pCollisionComponent->SetSize(5.0f);
	pMovementComponent->setBearing(vel.angle(), vel.magnitude());
	scale = 0.5f;
	// fire sound
	MySoundEngine* pMSE = MySoundEngine::GetInstance();
	SoundIndex shot = pMSE->LoadWav(L"shoot.wav");
	pMSE->SetVolume(shot, -2500);
	pMSE->Play(shot);
}

//decativate the object of it goes of screen
void Bullet::Update(float frametime) 
{		
	float x = position.XValue;
	float y = position.YValue;
	if ((x > 1800) || (x < -1800) || (y > 1200) || (y < -1200))
	{
		active = false;
	}
}

//decativate if it collides with something
void Bullet::Collision() {
	active = false;
}