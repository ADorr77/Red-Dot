#pragma once

#ifndef RENDER_H
#define RENDER_H
#include "TowerDefense.h"
#include "Dungeon.h"

class Render
{
public:
	void render(const TowerDefense& game);
	void render(TowerDefense&game, Tower& tower);
	void render(const Dungeon& game);
};

#endif
