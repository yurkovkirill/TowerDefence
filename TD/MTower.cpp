#include "stdafx.h"
#include "MTower.h"
#include "Enemy.h"

int MTower::Attack(Enemy* Eat) {
	if (Eat == nullptr){
		it++;
		return 0;
	}
	if (it >= rate){//пора стрелять
		it %= rate;
		it++;
		(*Eat).getHit(this->dmg);
		(*Eat).addEff(this->tEffect);//tEffect не может быть nullptr
	}
	else
		it++;
	return 1;
}

void MTower::Turn() {
	Enemy *Eat;
	Eat = DetectEnemy();//1)Detect
	Attack(Eat);//2)Attack
}

MTower::MTower() : Tower(), type(1) {
	tEffect = new Slow(0); //tEffect = nullptr;
}

MTower::MTower(Landscape* Landt, int xt, int yt, int lvlt, int typet, const std::string &fname) : Tower(Landt, xt, yt, lvlt, fname), type(typet) {
	if ((typet < 0) && (typet>2))
		throw std::exception("typet incorrect");
	if ((lvlt < 0) && (lvlt>2))
		throw std::exception("lvlt incorrect");
	if (typet == 1){
		//tEffect = new Slow(lvlt);
		tEffect = new Slow(lvlt, "configEffects.txt");
	}
	if (typet == 2){
		//tEffect = new Poison(lvlt);
		tEffect = new Poison(lvlt, "configEffects.txt");
	}
	if (typet == 3){
		//tEffect = new Weak(lvlt);//////////////////////////or from file  
		tEffect = new Weak(lvlt,"configEffects.txt");
	}
}

MTower::MTower(Landscape* Landt, int xt, int yt, int lvlt, int dmgt, float radt, int ratet, int costt, int typet) : Tower(Landt,xt,yt,lvlt,dmgt,radt,ratet,costt) , type(typet) {
	if ((typet < 0) && (typet>2))
		throw std::exception("typet incorrect");
	if ((lvlt < 0) && (lvlt>2))
		throw std::exception("lvlt incorrect");
	if (typet == 1){
		tEffect = new Slow(lvlt);
	}
	if (typet == 2){
		tEffect = new Poison(lvlt);
	}
	if (typet == 3){
		tEffect = new Weak(lvlt);
	}
	//может можно массивом указателей на классы?
}

MTower::~MTower(){
	delete tEffect;
}