#include "stdafx.h"
#include "Weapon.h"
#include "Landscape.h"
//#include <vector>

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

Weapon::Weapon() :Placeable(), lvl(0), rad(4.0), it(0), cost(100) {//dot=? �������
	//
}

Weapon::Weapon(Landscape* Landt, int xt, int yt, int lvlt, float radt, int costt) : Placeable(Landt, xt, xt), lvl(lvlt), rad(radt), it(0), cost(costt){
	//
}

float dist(dot a, dot b){
	return (float)(sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

Enemy* Weapon::DetectEnemy() {//������ ������ ��������� - �������� ������
	std::vector<Enemy>* Enemyoutp = (*Land).getEnemies();
	unsigned int i = 0;
	Enemy* Ew = nullptr;

	//���� �� ���� ������
	while (i < (*Enemyoutp).size()){
		if (i >(*Enemyoutp).size())//���� ���� �� ������� �� ��� 
			break;
		if (dist((*Enemyoutp)[i].getCor(), this->getCor()) <= rad){//�������� � ������ ��������
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
	//gold += 4 * (*Enemyoutp)[i].getSpeed();//���� ������ ����� ���������� !
}
//���������� ������ � Tower




