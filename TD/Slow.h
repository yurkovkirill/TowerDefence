#ifndef SLOW_H
#define SLOW_H
#include "Effect.h"
class Slow : public Effect {//1 eff

private:
	int eff[3];//lvl slwns
public:
	int getSlwns();// override;

	//void setSlwns(int eff);

	~Slow();

	Slow();

	Slow(int lvlt, const std::string &fname);

	Slow(int lvld);
};

#endif
