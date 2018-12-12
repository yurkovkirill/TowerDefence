#ifndef WEAPON_H
#define WEAPON_H

#include "STable.h"
#include "Placeable.h"
extern class Enemy;
extern class Landscape;

class Weapon : public Placeable {

protected:
	//STable<3>* Table;
	int lvl;//from 0 to 2
	float rad;
	int it;
	int cost;

private:
	void setLvl(int lvlt);

public:
	virtual int LevelUp() = 0;

	int getLvl();

	float getRad();

	void setRad(float radt);

	Weapon();

	Weapon(Landscape* Landt, int xt, int yt, int lvlt, float radt , int costt);

	virtual Enemy* DetectEnemy();

	int virtual Attack();// = 0;
	
	~Weapon();
};

#endif
