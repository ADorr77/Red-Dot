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
#include "Tower.h"
#include<cmath>
#include<iostream>


Tower::Tower(int x, int y, int s)
{
	xPos = x;
	yPos = y;
	strength = s;
	timer = 0;
	pnumber = 0;
	if (strength == 1) {
		cooldown = 20;
		range = 5;
		speed = 1;
	}
}

void Tower::detect(double x, double y)
{
	if (timer == 0) {
		double xdist = xPos - x;
		double ydist = yPos - y;
		double dist = sqrt(xdist*xdist + ydist * ydist);
		if (dist < range) {
			pnumber += 1;
			double xV = -1 * xdist * speed / dist;
			double yV = -1 * ydist * speed / dist;
			Projectile *p1 = new Projectile(xPos, yPos, xV, yV, strength);
			projectiles.push_back(*p1);
			timer += cooldown;
			std::cout << "SHOT";

		
		}
	}
}

void Tower::advanceProjectiles(int pnum)
{
	projectiles[pnum].advance();
}

void Tower::cool()
{
	if (timer > 0) {
		--timer;
	}
}

void Tower::eraseProjectile(int pnum)
{
	--pnumber;
	projectiles.erase(projectiles.begin() + pnum);
}

double Tower::get_pnumber() {
	return pnumber;

}

double Tower::get_projectile_x(int pnum)
{
	return projectiles[pnum].get_xPos();
	
}

double Tower::get_projectile_y(int pnum)
{
	return projectiles[pnum].get_yPos();
}
