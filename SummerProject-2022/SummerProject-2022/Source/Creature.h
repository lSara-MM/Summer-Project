#ifndef __CREATURE_H__
#define __CREATURE_H__


#include "Animation.h"

struct SDL_Texture;

class Creature
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Creature();

	// Destructor
	virtual ~Creature();

	

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	//virtual void Draw();

public:
	

	// The enemy's texture
	SDL_Texture* texture = nullptr;

	// Sound fx when destroyed
	int destroyedFx = 0;

	

protected:
	// A ptr to the current animation
	Animation* currentAnim = nullptr;

private:
	int MaxHP; // Puntos de vida Maxima
	int HPLeft; //Puntos de vida actuales
	int armor; // % de reduccion de daño
	int dodge; // % de esquivar ataques
	int accuarcy; // Bono a impactar que se resta a la esquiva enemiga
	int attack; //ataque base, cada habilidad deberia tener un multiplicador del daño, por ejemplo
	int initiative; //Iniciativa para ver quien actua antes cada ronda
	int DebuffRes; // % de resistir un debufffo.
	int StunRes; // % de resistir un aturdimiento.
	int PoisonRes; // % de resistir un Veneno.
	int MoveRes; // % de resistir movimiento forzado

	//Mi idea es que como efectos tmb haya quemadura y hemoragia pero de momento podemos dejarlo simplificado

	int ArrayPos; //Position in the team formation

	bool MyTurn; //indica si le toca hacer acciones o no
	


	
};

#endif // __CREATURE_H__
