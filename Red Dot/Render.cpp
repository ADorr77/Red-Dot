#include "Render.h"
#include <string>

void Render::render(const TowerDefense& game)
{
	const std::vector<Enemy> enemies = game.get_enemies();
	const std::vector<Tower> towers = game.get_towers();
	int ** map = game.get_map();
	std::vector<std::string> print;
	auto iterator = print.begin();

	for(int row = 0; row < game.width; row++)
	{
		print.insert(iterator, "");
		for (int col = 0; col < game.height; ++col)
		{
			print[0] += std::to_string(map[row][col]);
		}
	}

	for (int i = 0; i < enemies.size(); i++)
	{
		print[int(enemies[i].get_yPos())][int(enemies[i].get_xPos())] = 'E';
	}

	for (int i = 0; i < towers.size(); i++)
	{
		print[int(towers[i].get_yPos())][int(towers[i].get_xPos())] = 'E';
	}
}
