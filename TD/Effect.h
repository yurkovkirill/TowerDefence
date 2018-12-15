#ifndef EFFECT_H
#define EFFECT_H
#include <string>
class Effect {

protected:
	int type;
	int lvl;
	/*static const!!что -то не вышло нормально сделать*/ int time0[3];//3lvls time0
private:
	int time;

protected:
	void setLvl(int lvl1);

	void setType(int type);


public:

	int getType(); //const везде!

	int getLvl();

	int IsGone();//time compare , default = 0

	Effect();

	Effect(int typed, int lvld);

	int getTime();

	//virtual int AddDmg(int dmg) ;

//	virtual int getSlwns() ;
	//Effect* eff
	//eff.AddDmg(..);
	//((Weak*)eff).AddDmg(..);

	void setTime(int time);

	//~Effect();
};

#endif
