#include "Creature.h"

#include "Application.h"

#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Creature::Creature()
{
	
}

Creature::~Creature()
{
	
}



void Creature::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	
}

//void Creature::Draw()
//{
//	if (currentAnim != nullptr)
//		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
//}

//Hay que pensar como establecemos la posicion o si sera la misma en pantalla siempre

