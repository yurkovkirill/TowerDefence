#ifndef WEAPON_H
#define WEAPON_H

#include "STable.h"
#include "Placeable.h"
 class Enemy;
 class Landscape;
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

	Weapon(Landscape* Landt, int xt, int yt, int lvlt);

	Weapon(Landscape* Landt, int xt, int yt, int lvlt, float radt , int costt);

	virtual Enemy* DetectEnemy();

	//virtual int Attack();// = 0;

	virtual void Turn() = 0;
	
	//~Weapon();
};

#endif
