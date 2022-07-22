#include "Creature.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Creature::Creature(int x, int y) : position(x, y) //No hace falta inicializar los atributos se hara con los heroes y monstruos especificos
{
	spawnPos = position;
}

Creature::~Creature()
{
	if (collider != nullptr)
		collider->pendingToDelete = true;
}

const Collider* Creature::GetCollider() const
{
	return collider;
}

void Creature::Update()
{
	if (currentAnim != nullptr)
		currentAnim->Update();

	if (collider != nullptr)
		collider->SetPos(position.x, position.y);
}

void Creature::Draw()
{
	if (currentAnim != nullptr)
		App->render->Blit(texture, position.x, position.y, &(currentAnim->GetCurrentFrame()));
}

void Creature::OnCollision(Collider* collider)
{
	App->particles->AddParticle(App->particles->explosion, position.x, position.y);
	App->audio->PlayFx(destroyedFx);
}

//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::
//
//void Creature::