#ifndef MTOWER_H
#define MTOWER_H
#include "Tower.h"
extern class Effect;
class MTower : public Tower {

protected: 
	int type;
	Effect* tEffect;

public:
	int Attack(Enemy* Eat);

	void Turn();

	MTower();

	MTower(Landscape* Landt, int xt, int yt, int lvlt, int typet , const std::string &fname);

	MTower(Landscape* Landt, int xt, int yt, int lvlt, int dmgt, float radt, int ratet, int costt , int typet);
};

#endif
