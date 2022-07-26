#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "p2Point.h"
#include "Animation.h"

struct SDL_Texture;
struct Collider; //Necesario para detectar con puntero

class Creature
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Creature(); //Hero pide un tipo de constructor sin parametros
	Creature(int x, int y);

	// Destructor
	virtual ~Creature();

	// Returns the enemy's collider
	const Collider* GetCollider() const;

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	// Collision response
	// Triggers an animation and a sound fx
	virtual void OnCollision(Collider* collider);

	//STATS SETTERS
	/*void SetName(const char* nombre) { this->name* = nombre; }*/
	void SetMaxHP(int stat);
	void takeDamage(int damage);
	void takeHeal(int heal);
	void SetArmor(int stat);
	void SetDodge(int stat);
	void SetAttack(int stat);
	void SetCrit(int stat);
	void SetAccuarcy(int stat);
	void SetInitiative(int stat);
	void SetMovementRes(int stat);
	void SetStunRes(int stat); 
	void SetDebuffRes(int stat);
	void SetPoisonRes(int stat); 
	
	//STATS GETTERS

	char* GetName();
	int GetMaxHP();
	int GetHP();
	int GetArmor();
	int GetDodge();
	int GetAttack();
	int GetCrit();
	int GetAccurcy();
	int GetInitiative();
	int GetMovementRes();
	int GetStunRes();
	int GetDebuffRes();
	int GetPoisonRes();




public:
	// The current position in the world
	iPoint position;

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	// Sound fx when destroyed
	int destroyedFx = 0;

protected:
	// A ptr to the current animation
	Animation* currentAnim = nullptr;

	// The enemy's collider
	Collider* collider = nullptr; //Se necesita esto para el cursor?

	// Original spawn position. Stored for movement calculations
	iPoint spawnPos;

	//STATS
	char* name[40]; //Nombre enemigo o heroe
	int maxHP; //Vida maxima
	int HP; //Vida actual
	int armor; //Armadura, reduce % el daño recibido 
	int dodge; // Posibildad de esquivar el golpe
	int attack; //Daño base diferentes ataques tendran distintos multiplicadores
	int crit; // Incremento posibildad ataque critico
	int accuary; //Probabilidad de no ser esquivado en cada ataque
	int initiative; //Bonificador para ver quien empieza la ronda, puede ser rand() % 8
	int movementRes; //Probabilidad de resistir movimiento forzado
	int stunRes; //Probabilidad de resistir stun
	int debuffRes; //Probabilidad de resistir mermas
	int poisonRes; ////Probabilidad de resistir veneno
	//LA IDEA ES TENER TAMBIEN SANGRADO Y QUEMADURA

	int ArrayPos;

	bool MyTurn;


};

#endif // __CREATURE_H__
