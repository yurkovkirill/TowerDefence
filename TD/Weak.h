#ifndef WEAK_H
#define WEAK_H
#include "Effect.h"
class Weak : public Effect {//3 eff

private:
	int eff[3];//lvl wkns
public:
	Weak();

	Weak(int lvlt, const std::string &fname);

	Weak(int lvld);

	Weak(const Weak &);

	Weak(Weak &&);

	~Weak();

	//float getWkns() override = default;

	int AddDmg(int dmg);// override;//возвращает dmg*eff

private:
	
	void setWkns(int eff);
};

#endif
