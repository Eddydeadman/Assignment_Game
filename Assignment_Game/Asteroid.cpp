// Asteroid.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "Asteroid.h"
#include "Explosion.h"
#include "ObjectManager.h"

using namespace std;

Asteroid::Asteroid(RenderComponent* pRender, CollisionComponent* pCollision, MovementComponent* pMove, ObjectManager& Manager) :theManager(Manager)
{
	active = false;
	pCollisionComponent = pCollision;
	pRenderComponent = pRender;
	pMovementComponent = pMove;

 	Initialise();
}

Asteroid::~Asteroid()
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

//initialises the asteroid
void Asteroid::Initialise()
{
	active = true;
	int randomX;
	int randomY;

	// randomise position
	
	randomX = (rand() % 2801) - 1400;
	randomY = (rand() % 2001) - 1000;
	position.set(randomX, randomY);

	//safe area within 300 units of 0,0
	if ((randomX < 300) && (randomX > -300)) {
		if( (randomY < 300) && (randomY > -300) ){
			if (randomY >= 0) {
				randomY += 300;
			}
			else {
				randomY -= 300;
			}
		}
	}
	
	//set hitbox size
	pCollisionComponent->SetSize(55.0f);

	// set bearing	
	randomX = rand() % 361;
	randomX = randomX * 3.142 / 180;
	randomY = rand() % 151 + 50;
	pMovementComponent->setBearing(randomX, randomY);
	
	//randomise spin
	spin = rand() % 316 + 45;
	spin = spin * 3.142 / 180;

	//randomise pic
	randomX = rand() % 4;
	if (randomX == 0) {
		pRenderComponent->SetImage(L"rock1.bmp");
	}
	else if (randomX == 1) {
		pRenderComponent->SetImage(L"rock2.bmp");
	}
	else if (randomX == 2) {
		pRenderComponent->SetImage(L"rock3.bmp");
	}
	else{
		pRenderComponent->SetImage(L"rock4.bmp");
	}
}

//updates the angle the asteroid is drawn at, and decativate the object of it goes of screen
void Asteroid::Update(float frametime) 
{
	angle += (spin * frametime);

	if ((position.XValue >= 1800) || (position.XValue <= -1800) || (position.YValue >= 1200) || (position.YValue <= -1200)) {
		active = false;
	}		
}

//process collision
void Asteroid::Collision()
{
	RenderComponent* pExpRender = new RenderComponent(L"explosion1.bmp");
	Explosion* pExp = new Explosion(1.75f, pExpRender);
	pExp->Initialise(position);
	theManager.AddObject(pExp);
	active = false;
}
