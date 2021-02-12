// Level.cpp
// Made by 15010974
// last modified: 13/01/2020

#include "Level.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "ObjectManager.h"
#include "SpaceshipMovementComponent.h"

Level::Level(ObjectManager& Manager): theManager(Manager)
{
	//potential to use a render component to create background scenery in the level???
	pCollisionComponent = nullptr;
	pMovementComponent = nullptr;
	pRenderComponent = nullptr;
	Initialise();
}

Level::~Level()
{

}

//initialises the level
void Level::Initialise()
{
	asteroidtimer = 2;
	active = true;
	position.set(0, 0);
	angle = 0;
}

//updates the level
void Level::Update(float frametime)
{
	// output score
	//if timer = 0 create asteroid, reset timer
	asteroidtimer -= frametime;
	if (asteroidtimer <= 0.0f) {
		CreateAsteroid();
		asteroidtimer = (rand() % 3)+1;
	}
	
}

//not required - never called due to no collision component
void Level::Collision()
{
	
}

//creates a new spaceship
void Level::CreatePlayer()
{
	//move this to level
	RenderComponent* render = new RenderComponent(L"harrasser.bmp");
	CollisionComponent* colide = new CollisionComponent();
	SpaceshipMovementComponent* move = new SpaceshipMovementComponent();
	Spaceship* player = new Spaceship(render, colide, move, theManager);
	theManager.AddObject(player);
}

//creates a new asteroid
void Level::CreateAsteroid()
{	
	RenderComponent* render = new RenderComponent(L"rock1.bmp");
	CollisionComponent* colide = new CollisionComponent();
	MovementComponent* move = new MovementComponent();
	Asteroid* ast = new Asteroid(render, colide, move, theManager);
	ast->Initialise();
	theManager.AddObject(ast);	
}
