#include "stdafx.h"
#include "Weapon.h"
#include "Landscape.h"
//#include <vector>
#include <iostream>
int Weapon::getLvl() {
	return this->lvl;
}

void Weapon::setLvl(int lvlt) {
	this->lvl = lvlt;
}

float Weapon::getRad() {
	return this->rad;
}

void Weapon::setRad(float radt) {
	this->rad = radt;
}

Weapon::Weapon() :Placeable(), lvl(0), rad(4.0), it(0), cost(100) {//dot=? подумай
	//
}

Weapon::Weapon(Landscape* Landt, int xt, int yt, int lvlt) : Placeable(Landt, xt, yt), lvl(lvlt){
	//
}

Weapon::Weapon(Landscape* Landt, int xt, int yt, int lvlt, float radt, int costt) : Placeable(Landt, xt, yt), lvl(lvlt), rad(radt), it(0), cost(costt){
	//
}

float dist1(dot a, dot b){
	return (float)(sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

Enemy* Weapon::DetectEnemy() {//сейчас дефолт стратегия - наиболее слабый
	std::vector<Enemy>* Enemyoutp = (*Land).getEnemies();
	unsigned int i = 0;
	Enemy* Ew = nullptr;

	//идем по всем врагам
	while (i < (*Enemyoutp).size()){
		if (i >(*Enemyoutp).size())//если ушло за границы хз как 
			break;
		if ((*Enemyoutp)[0].getCor().x == 9)
			std::cout << (*Enemyoutp)[0].getCor().x << ' ' << std::endl;
		if (dist1((*Enemyoutp)[i].getCor(), this->getCor()) <= rad){//попадает в радиус действия
			if (Ew == nullptr)
				Ew = &((*Enemyoutp)[i]);
			else{
				if ((*Enemyoutp)[i].getHp() < (*Ew).getHp())
					Ew = &((*Enemyoutp)[i]);
			}
		}
		i++;
	}
	return Ew;
	//gold += 4 * (*Enemyoutp)[i].getSpeed();//надо решить трабл начисления !
}
//изначально лежала в Tower




