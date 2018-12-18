#ifndef CASTLE_H
#define CASTLE_H
#include "Landscape.h"
#include <string> 
class Landscape;
//class Placeable;
#include "Placeable.h"

class Castle : public Placeable {

private:
	std::string name;
	int hp;
	int hp0;
	int gold;

private:
	void setHp(int hp);

private:
	void setGold(int gold);

public:
	int getHp();

	int getGold();

	void Hit(int dmg);

	void Earn(int ecost);

	Castle();

	Castle(Landscape* Land1 , std::string fname ,int x , int y /*int hp0, int x, int y,int gold0*/);

	void Turn();// override;//вместо virtual void в cpp override не пишется

	//~Castle();// override = default;//делает виртуальный дефолтным

};

#endif
