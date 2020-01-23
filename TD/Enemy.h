#ifndef ENEMY_H
#define ENEMY_H
//#include "Effect.h"
#include "dot.h"
#include <vector>
#include <queue>
#include "Poison.h"
#include "Weak.h"
#include "Slow.h"
#include <stdexcept>  

const int SIZEL = 100; //»з landscape
/**
\brief  ласс ¬рага

Езлые демоны с любопытством наблюдают вс€кое наше движение и ничего не оставл€ют неисследованным из того,
чем можно воспользоватьс€ против нас Ц ни вставани€, ни сидени€, ни сто€ни€, ни поступи, ни слова, ни взора, Ц все любопытствуют, Ђвесь день поуча€сь на нас лъстивнымї (ѕсал. 37:13),
чтоб во врем€ молитвы осрамить смиренный ум и блаженный его погасить свет.
*/
class Enemy {

public:
	int Isdead;///<Is Dead?
protected:
	int hp;
	dot cor;///< текуща€ позици€
private:
	int it;///<итератор дл€ скорости 
	int speed;///<каждые speed*slwns итератора враг ходит
	std::queue<dot> path;///< путь , каждый будущий шаг 
	int slwns;///<from 1 to inf
	int lvl;
	std::vector<Effect*> Effects;///<¬ектор наложенных эффектов
	

public:
	int getHp();

	void setHp(int hp);

	int getSpeed();

	int getLvl();

	void setSpeed(int speed);

	dot getCor();


public:
	void setCor(dot cor);

	void setPath(std::queue<dot> path);

	int addEff(Effect* Eftmp);

	void delEff(int effit);

	void getHit(int dmg);

	void gonext();

	void getslwns();///<рассчитать новое значение от эффектов

	int getSlowValue();///<Value

	Enemy();

	Enemy(int lvl, std::string fname);

	Enemy(const Enemy &);

	Enemy(Enemy &&);

	~Enemy();

	void Turn();
};

#endif
