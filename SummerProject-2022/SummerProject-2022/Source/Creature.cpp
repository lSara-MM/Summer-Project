#include "Creature.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Creature::Creature() { spawnPos = position; };

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

//Setters

void Creature::SetMaxHP(int stat) { this->maxHP = stat; }

void Creature::SetArmor(int stat) { this->armor = stat; }

void Creature::SetDodge(int stat) { this->dodge = stat; }

void Creature::SetAttack(int stat) { this->attack = stat; }

void Creature::SetCrit(int stat) { this->attack = stat; }

void Creature::SetAccuarcy(int stat) { this->accuary = stat; }

void Creature::SetInitiative(int stat) { this->initiative = stat; }

void Creature::SetStunRes(int stat) { this->stunRes = stat; }

void Creature::SetMovementRes(int stat) { this->movementRes = stat; }

void Creature::SetDebuffRes(int stat) { this->debuffRes = stat; }

void Creature::SetPoisonRes(int stat) { this->poisonRes = stat; }

//HP Managment

void Creature::takeHeal(int heal) 
{
	if ((maxHP - HP) < heal) { HP = maxHP; }
	else { HP += heal; }
}



void Creature::takeDamage(int damage) //Se puede complicar a futuro con perforacion de armadura etc
{
	//Falta calculo de si es un critico
	HP -= (damage - ((float)armor / 100) * damage);
	if (HP < 0) { HP = 0; }
}

//Getters

char* Creature::GetName() { return this->name[40]; }

int Creature::GetMaxHP() { return this->maxHP; }

int Creature::GetHP() { return this->HP; }

int Creature::GetArmor() { return this->armor; }

int Creature::GetDodge() { return this->dodge; }

int Creature::GetAccurcy() { return this->accuary; }

int Creature::GetCrit() { return this->crit; }

int Creature::GetAttack() { return this->attack; }

int Creature::GetInitiative() { return this->initiative; }

int Creature::GetDebuffRes() { return this->debuffRes; }

int Creature::GetMovementRes() { return this->movementRes; }

int Creature::GetPoisonRes() { return this->poisonRes; }

int Creature::GetStunRes() { return this->stunRes; }