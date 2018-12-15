#include "stdafx.h"
#include "MTrap.h"
#include <vector>
#include "Enemy.h"
#include "Landscape.h"
int MTrap::getType() {
	return this->type;
}

void MTrap::setType(int type) {
	this->type = type;
}

MTrap::MTrap() : Weapon(), type(1) {
	tEffect = new Slow(1); //tEffect = nullptr; � ������� ����� ���������� ��� !!!!!!!!!!!1 ��� �� 0 � ���� ��� ���������!!!!!!!!!!!
}

MTrap::MTrap(Landscape* Landt, int xt, int yt, int lvlt, int typet, const std::string &fname){
	Table = new STable<TableS,3>(fname);
	lvl = lvlt;//from 0 to 2
	rad = (*Table).getVal(lvl).rad;
	cost = (*Table).getVal(lvl).cost;
	it = 0;
}
MTrap::MTrap(Landscape* Landt, int xt, int yt, int lvlt/*�� 2(1) �� ������� ����*/,  float radt, int costt, int typet) : Weapon(Landt, xt, yt, lvlt, radt, costt), type(typet)  {
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
}

float dist(dot a, dot b){
	return (float)(sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
}

int MTrap::Attack(Enemy* Eat) {
	if (Eat == nullptr){
		return 0;
	}
	(*Eat).addEff(tEffect);//tEffect �� ����� ���� nullptr
	return 1;
}

void MTrap::Turn() {//������� ���� � ���� ��������
	std::vector<Enemy>* Enemyoutp = (*Land).getEnemies();
	unsigned int i = 0;

	//1)���� �� ���� ������
	while (i < (*Enemyoutp).size()){
		if (i >(*Enemyoutp).size())//���� ���� �� ������� �� ��� 
			break;
		if (dist((*Enemyoutp)[i].getCor(), this->getCor()) <= rad){//1)�������� � ������ ��������
			Attack(&(*Enemyoutp)[i]);//2)Attack
			}
		i++;
		}
		
}

int MTrap::LevelUp() {
	if (lvl < 2){
		(this->lvl)++;
		return 1;
	}
	else
		return 0;
}



//Enemy* MTrap::DetectEnemy() {//������ Mtrap ��������� ��
//	std::vector<Enemy>* Enemyoutp = (*Land).getEnemies();
//	int i = 0;
//	Enemy* Ew = nullptr;
//
//	//���� �� ���� ������
//	while (i < (*Enemyoutp).size()){
//		if (i >(*Enemyoutp).size())//���� ���� �� ������� �� ��� 
//			break;
//		if (dist((*Enemyoutp)[i].getCor(), this->getCor()) <= rad){//�������� � ������ ��������
//			if (Ew == nullptr)
//				Ew = &((*Enemyoutp)[i]);
//			else{
//				if ((*Enemyoutp)[i].getHp() < (*Ew).getHp())
//					Ew = &((*Enemyoutp)[i]);
//			}
//		}
//		i++;
//	}
//	return Ew;
//	//gold += 4 * (*Enemyoutp)[i].getSpeed();//���� ������ ����� ���������� !
//}