#pragma once
// InputsComponent.h
// Made by 15010974
// last modified: 16/01/2020
class SpaceshipMovementComponent;
class MyInputs;
class Spaceship;

class InputsComponent
{
private:
	MyInputs* pInputs;	//pointer to the inputs logger
	float firerate; //contains the firerate of the object
	float firetime; // holds the time until the owner can fire again
public:
	InputsComponent();
	~InputsComponent();
	void Update(SpaceshipMovementComponent* move, float frametime, Spaceship* pOwner); //processes the inputs, and updates move accordingly
	void Shoot(float frametime, Spaceship* pOwner); //directs back to pOwner to shoot, if firetime is 0

};