#include "Monster.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#include "ModuleRender.h"

Monster::Monster(int x, int y) : position(x, y) { spawnPos = position; }

void Monster::SetSize(int value) { this->size = value; };

int Monster::getSize() { return this->size; };