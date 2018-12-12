#ifndef TOWER_H
#define TOWER_H
//#include "STable.h"
#include "Weapon.h"
class Tower : public Weapon {

protected:
	//In weapon
	//int lvl;//from 0 to 2
	//float rad;
	//int it;
	//int cost;
	int rate;
	int dmg;

public:
	STable<3>* Table;

private: 
	void setDmg(int dmgt);

public:
	int LevelUp();

	//Enemy* DetectEnemy() in weapon

	int Attack(Enemy* Eat);

	Tower();

	Tower(Landscape* Landt, int xt, int yt, int lvlt,  const std::string &fname);

	Tower(Landscape* Landt, int xt, int yt, int lvlt, int dmgt, float radt, int ratet , int costt);

	virtual void Turn();

	int getRate();

	void setRate(int ratet);

	int getDmg();
};

#endif
