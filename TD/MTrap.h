#ifndef MTRAP_H
#define MTRAP_H
#include "Weapon.h"
//#include "STable.h"
extern class Effect;
class MTrap :public Weapon {

protected:
	int type;
	Effect* tEffect;
	STable<3>* Table;//included throw Landscape
	//cost in weapon

public:
	int getType();

	void setType(int type);

	MTrap();

	MTrap(Landscape* Landt, int xt, int yt, int lvlt, int typet , const std::string &fname);

	MTrap(Landscape* Landt, int xt, int yt, int lvlt, float radt, int costt, int typet);

	int Attack(Enemy* Eat);

	//Enemy* DetectEnemy();

	void Turn();

	int LevelUp();//done = 1 , not ( lvl == lvlmax) = 0


};

#endif
