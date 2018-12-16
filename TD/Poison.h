#ifndef POISON_H
#define POISON_H
#include "Effect.h"

class Poison : public Effect {//2 eff 

private:
	int eff[3];//lvl poison
public:
	int rate;//Effect::time==iterator for
	
public:
	//void setdmg(int eff);

	Poison();

	Poison(int lvlt, const std::string &fname);

	Poison(int lvld);

	~Poison();

	int AddDmg(int dmg);// override;//возвращает dmg+eff

	int getRate();

private:
	void setRate(int rate);
};

#endif
