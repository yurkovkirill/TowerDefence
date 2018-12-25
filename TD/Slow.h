#ifndef SLOW_H
#define SLOW_H
#include "Effect.h"
/**
\brief Класс эффекта "Замедление"

Замедляет врага . Именно под действием его враг окрашивался в синий в демке 
*/
class Slow : public Effect {//1 eff

private:
	int eff[3];//lvl slwns
public:
	int getSlwns();// override;

	//void setSlwns(int eff);

	~Slow();

	Slow();

	Slow(const Slow &);

	Slow(Slow &&);

	Slow(int lvlt, const std::string &fname);

	Slow(int lvld);
};

#endif
