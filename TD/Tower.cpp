#include "stdafx.h"
#include "Tower.h"
#include "Enemy.h"
int Tower::LevelUp() {
	if (lvl < 2){
		(this->lvl)++;
		return 1;
	}
	else
		return 0;
}

int Tower::Attack(Enemy* Eat) { 
	if (Eat == nullptr){
		return 0;
	}
	if (it >= rate){//пора стрелять
		it++;
		it %= rate;
		(*Eat).getHit(this->dmg);
	}
	else
		it++;
	return 1;
}

Tower::Tower() : Weapon(), rate(4), dmg(25)  {
	Table = new STable<TableS,3>("configTowers.txt");
	it = 0;
}

Tower::Tower(Landscape* Landt, int xt, int yt, int lvlt, const std::string &fname) : Weapon(Landt, xt, yt, lvlt){//из файла
	
	Table = new STable<TableS,3>(fname);
	lvl = lvlt;//from 0 to 2
	rad = (*Table).getVal(lvl).rad;
	cost = (*Table).getVal(lvl).cost;
	dmg = (*Table).getVal(lvl).dmg;
	rate = (*Table).getVal(lvl).rate;
	it = 0;
}

Tower::Tower(Landscape* Landt, int xt, int yt, int lvlt, int dmgt, float radt, int ratet, int costt) : Weapon(Landt, xt, yt, lvlt, radt, costt), dmg(dmgt)  , rate(ratet) {//не переопределяется из файла , если хочешь , то можно руками
	//
	if ((lvlt < 0) && (lvlt>2))
		throw std::exception("lvlt incorrect");
	Table = new STable<TableS,3>("configTowers.txt");
	it = 0;
}

Tower::~Tower(){
	delete Table;
}
void Tower::Turn() {
	Enemy *Eat;
	Eat = DetectEnemy();//1)Detect
	Attack(Eat);//2)Attack
}

int Tower::getRate() {
	return this->rate;
}

void Tower::setRate(int rate) {
	this->rate = rate;
}

int Tower::getDmg() {
	return this->dmg;
}

void Tower::setDmg(int dmgt) {
	this->dmg = dmgt;
}