#ifndef MTOWER_H
#define MTOWER_H
#include "Tower.h"
 class Effect;
 /**
 \brief Класс магической башни

 Совершенство инженерной мысли , она не только атакует врагов по заданной стратегии , 
 так еще и может накладывать различные дебафы . Пользоваться - полное удовольствие , 
 именно она была продемонстрированна в демке . Думаю , вы уже предвкушаете момент , когда 
 накопите достаточно голды для ее постройки.
 */
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

	~MTower();
};

#endif
