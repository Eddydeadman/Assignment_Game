// InputComponent.cpp
// Made by: 15010974
// last modified: 13/01/2020

#include "InputsComponent.h"
#include "myinputs.h"
#include "SpaceshipMovementComponent.h"
#include "Spaceship.h"


using namespace std;

InputsComponent::InputsComponent()
{
	pInputs = MyInputs::GetInstance();
	firetime = 0.25f;
	firerate = 0.5f;
}

InputsComponent::~InputsComponent()
{
}

//gets the inputs from the keyboard and updates the movement component, and owner accordingly, also class shoot if spacebar is pressed
void InputsComponent::Update(SpaceshipMovementComponent* move, float frametime, Spaceship* pOwner)
{
	
	pInputs->SampleKeyboard();
	if (pInputs->KeyPressed(DIK_W)) {
		move->accelerate(pOwner, 150);
	}
	else if (pInputs->KeyPressed(DIK_S)) {
		move->accelerate(pOwner, -150);			
	}
	if (pInputs->KeyPressed(DIK_A)) {
		move->rotate(-1.2);
	}
	if (pInputs->KeyPressed(DIK_D)) {
		move->rotate(+1.2);
	}

	firetime -= frametime;
	if (pInputs->KeyPressed(DIK_SPACE)) {
		Shoot(frametime, pOwner);
	}	
}



//direct back to the owner to fire bullets if firerate allowes it
void InputsComponent::Shoot(float frametime, Spaceship* pOwner)
{
	{
		if (firetime <= 0) {
			firetime = firerate;
			// direct to spaceship to shoot
			pOwner->Shoot();
		}
	}
}
