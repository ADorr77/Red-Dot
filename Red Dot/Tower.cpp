#include "Tower.h"
Tower::Tower(TowerType type, int x, int y) // set base parameters
{
	switch (type)
	{
	case RecognizeTheSituation:
		strength = 1;
		range = 20; //not sure how big our map will be
		base_cost = 10;
		level = 1;
	case Direct:
		strength = 1;
		range = 20;
		base_cost = 10;
		level = 1;
	case Distract:
		strength = 1;
		range = 20;
		base_cost = 10;
		level = 1;
	case Delegate:
		strength = 1;
		range = 20;
		base_cost = 10;
		upgrade_cost = 10;
		level = 1;
	}
}
void Tower::update(TowerType type)
{
	//do stuff?
}
//getters
double Tower::get_strength() const
{
	return strength;
}
double Tower::get_xPos() const
{
	return xPos;
}
double Tower::get_yPos() const
{
	return yPos;
}
double Tower::get_fire_rate() const
{
	return fire_rate;
}
double Tower::get_range() const
{
	return range;
}
double Tower::get_base_cost() const
{
	return base_cost;
}
double Tower::get_upgrade_cost() const
{
	return upgrade_cost;
}
// Build towers - pass in tower type and (x, y) coordinate
Tower* Tower::BuildTower(TowerType type, int x, int y)
{
	return new Tower(type, x, y);
}
// define types of projectiles to create