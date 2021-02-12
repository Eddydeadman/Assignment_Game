// Spaceship.cpp
// Made by: 15010974
// last modified: 13/01/2020

#include "Spaceship.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "Explosion.h"
#include "InputsComponent.h"
#include "SpaceshipMovementComponent.h"


using namespace std;

Spaceship::Spaceship(RenderComponent* pRender, CollisionComponent* pCollide, SpaceshipMovementComponent* pMove, ObjectManager& Manager):theManager(Manager) {
	pRenderComponent = pRender;
	pCollisionComponent = pCollide;
	pMovementComponent = pMove;
	Initialise();
}

Spaceship::~Spaceship()
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
	if (pInputs != nullptr) {
		delete pInputs;
	}
}

//initialise the spaceship
void Spaceship::Initialise() {
	position.set(0,0);
	angle = 0;
	active = true;
	GetRenderComp()->SetImage(L"harrasser.bmp");	
	health = 5;
	invulnrableTime = 0.5f;
	pInputs = new InputsComponent();
	pCollisionComponent->SetSize(55.0f);
	scale = 0.75f;
}

//process collision
void Spaceship::Collision() {

	if (invulnrableTime <=0.0f) {
		health -= 1;
		if (health <= 0) {

			RenderComponent* pExpRender = new RenderComponent(L"explosion1.bmp");
			Explosion* pExp = new Explosion(4.0f, pExpRender);
			pExp->Initialise(position);
			theManager.AddObject(pExp);
			//send End of Game message
			active = false;
		}
		else {
			invulnrableTime = 1.0f;		
		}
	}

}

//updates the inputs, invulnerability, and prevent out of bounds
void Spaceship::Update(float frametime) {

	//check invulnerability
	if (invulnrableTime > 0.0) {
		invulnrableTime -= frametime;
		transparency = 0.5f;
	}
	else {
		transparency = 0.0f;
	}
	
	//update movement
	
	pInputs->Update((SpaceshipMovementComponent*)pMovementComponent,frametime,this);

	
	//prevent out of bounds
	float x = position.XValue;
	float y = position.YValue;
	if (x >= 1600 )
	{
		x = 1600;		
	}
	if (x <= -1600) {
		x = -1600;
	}
	if (y >= 800)  
	{
		y = 800;
	}
	if (y <= -800) {
		y = -800;
	}
	position.set(x, y);
	
	
}

//creates and fires a bullet
void Spaceship::Shoot() 
{
	Vector2D speed = pMovementComponent->getBearing();
	float mag = speed.magnitude();
	RenderComponent* render = new RenderComponent(L"plasma.bmp");
	CollisionComponent* colide = new CollisionComponent();
	MovementComponent* move = new MovementComponent();
	Bullet* pBullet = new Bullet(render, colide, move);	
	//figure out position
	Vector2D front;
	front.setBearing(angle, 75);
	Vector2D bulletpos = position + front;
	//figure out bearing
	Vector2D bulletspeed;
	bulletspeed.setBearing(angle, (mag/2) + 250.0f);
	pBullet->Initialise(bulletpos, bulletspeed);
	theManager.AddObject(pBullet);
	
	
}