#include "Hero.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Hero::Hero(int x, int y) : position(x, y) { spawnPos = position; }

void Hero::SetLevel(int nivel) { this->level = nivel; };

void Hero::SetExp(int value) { this->exp = value; };

int Hero::getLevel() { return this->level; };

int Hero::getExp() { return this->exp; };

//Dead? Deaths door? En resumen , que mas a futuro se ponen las variables