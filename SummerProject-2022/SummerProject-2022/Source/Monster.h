#ifndef __MONSTER_H__
#define __MONSTER_H__

#include "p2Point.h"
#include "Animation.h"
#include "Creature.h"

struct SDL_Texture;
struct Collider; //Necesario para detectar con puntero

class Monster : public Creature
{
public:
	// Constructor
	// Saves the spawn position for later movement calculations
	Monster(int x, int y);
	// Destructor
	virtual ~Monster();

	// Called from inhering enemies' Udpate
	// Updates animation and collider position
	virtual void Update();

	// Called from ModuleEnemies' Update
	virtual void Draw();

	//STATS SETTERS
	void SetSize(int value);


	//STATS GETTERS
	int getSize();
	





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
		//Heredadas de creature

	int size; //La idea es que quiza algunos monstruos (sobretodo jefes) pueden ocupar mas de un espacio, lo unico es eso


};

#endif // __HERO_H__
