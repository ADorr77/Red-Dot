#ifndef TOWER_H
#define TOWER_H
enum TowerType { RecognizeTheSituation, Direct, Distract, Delegate };
#include "Projectile.h"
#include<vector>

class Tower
{
private:
	int timer;
	int cooldown;
	int pnumber;
	double strength;
	int xPos, yPos;
	double range;
	double speed;
	std::vector<Projectile> projectiles;
	double strenght;
	double xPos, yPos;
	double fire_rate;
	double strength;
	double range;
	double base_cost;
	double upgrade_cost;
	double level;
	// int type; Possible way to implement multiple types of towers with enum
public:
	// Tower constructor (pass in whatever you decide)
	Tower(int x, int y, int s);
	Tower(TowerType, int, int);
	Tower();
	// update method to fire from it
	void detect(double x, double y);
	void advanceProjectiles(int pnum);
	void cool();
	void eraseProjectile(int pnum);
	double get_pnumber();
	double get_projectile_x(int pnum);
	double get_projectile_y(int pnum);
	// getters
	
	void update(TowerType); // takes the tower type as input to define behavior
	void update();
	// getters
	double get_strength() const;
	double get_xPos() const;
	double get_yPos() const;
	double get_fire_rate() const;
	double get_range() const;
	double get_base_cost() const;
	double get_upgrade_cost() const;
	// Write additional behavior
	// build towers
	Tower* BuildTower(TowerType, int, int);
};
#endif