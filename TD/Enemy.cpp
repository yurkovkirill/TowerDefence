#include "stdafx.h"
#include "Enemy.h"
#include <fstream>

int Enemy::getHp() {
	return this->hp;
}

void Enemy::setHp(int hp) {
	this->hp = hp;
}

int Enemy::getSpeed() {
	return this->speed;
}

int Enemy::getLvl() {
	return this->lvl;
}

void Enemy::setSpeed(int speed) {
	this->speed = speed;
}

dot Enemy::getCor() {
	return this->cor;
}

void Enemy::setCor(dot cor) {
	this->cor = cor;
}

void Enemy::setPath(std::queue<dot> path) {
	this->path = path;
}

int Enemy::addEff(Effect* Eftmp) {//0 = new , 1 = added , 2 = reload , 3 = do nothing , have stronger 
	int typetmp = (*Eftmp).Effect::getType();
	Effect* tmp = nullptr;
	if (!(Effects).empty()){
		for (unsigned i = 0; i < Effects.size(); i++){
			if ((*Effects[i]).getLvl() == (*Eftmp).getLvl())
				if ((*Effects[i]).getType() == (*Eftmp).getType())
					if ((*Effects[i]).getTime() >(*Eftmp).getTime()){///CT  // if same effect with same lvl but lower time change it
						(*Effects[i]).setTime((*Eftmp).getTime());
						return 2;
					}
					else
						return 3;
		}
		if (typetmp == 1){
			tmp = new Slow(*(Slow*)Eftmp);
		}
		if (typetmp == 2){
			tmp = new Poison(*(Poison*)Eftmp);
		}
		if (typetmp == 3){
			tmp = new Weak(*(Weak*)Eftmp);
		}
		Effects.push_back(tmp);
		return 1;
			
	}
	else 
		if (typetmp == 1){
			tmp = new Slow(*(Slow*)Eftmp);
		}
		if (typetmp == 2){
		tmp = new Poison(*(Poison*)Eftmp);
		}
		if (typetmp == 3){
			tmp = new Weak(*(Weak*)Eftmp);
		}
		Effects.push_back(tmp);
	return 0;

	/*if ((*Effects[typetmp]).getLvl() > (*Eftmp).getLvl()){///CT
		Effects[typetmp] = (Eftmp);///
	}*/
}

void Enemy::delEff(int effit) {//��������� [effit]
	if (effit < 0){
		throw std::range_error("Invalid effit"); 
	}
	delete Effects[effit];
	Effects.erase(Effects.begin() + effit);

}

void Enemy::getHit(int dmg) {
	for (unsigned i = 0; i < Effects.size(); i++){
		if ((*Effects[i]).Effect::getType() == 3)
			dmg = (*((Weak*)Effects[i])).Weak::AddDmg(dmg);
	}
	hp = hp - dmg;
	if (hp <= 0)
		Isdead = 1;//bool
}

void Enemy::gonext() {
	if (!path.empty()){//���� ����� ��� � �����, �� ������ �� ����������
		cor = path.front();
		path.pop();
	}
}

void Enemy::getslwns(){
	slwns = 1;
	for (unsigned i = 0; i < Effects.size(); i++)
		if ((*Effects[i]).Effect::getType() == 1){
			slwns *= (*((Slow*)Effects[i])).Slow::getSlwns();
		}
}

int Enemy::getSlowValue(){
	return this->slwns;
}

Enemy::Enemy() {
	lvl = 0;
	it = 0;
	Isdead = 0;
	speed = 4 * (3 - lvl);//
	hp = 50 * (lvl + 1);//
	//path = nullptr;
	slwns = 1;
	cor.x = SIZEL - 4;
	cor.y = SIZEL - 4;
}

Enemy::Enemy(const Enemy &b) : it(b.it) , Isdead(b.Isdead) , hp(b.hp) , cor(b.cor) , speed(b.speed) , path(b.path) , slwns(b.slwns), lvl(b.lvl)  {
	Effect* tmp = new Effect;
	for (unsigned i = 0; i < b.Effects.size(); i++){
		(*tmp) = (*(b.Effects[i]));
		this->Effects.push_back(tmp);
	}
	tmp = nullptr;
	
}

Enemy::Enemy(Enemy &&b) : it(b.it), Isdead(b.Isdead), hp(b.hp), cor(b.cor), speed(b.speed), path(b.path), slwns(b.slwns), lvl(b.lvl)  {
	for (unsigned i = 0; i < b.Effects.size(); i++){
		this->Effects.push_back(b.Effects[i]);
		b.Effects[i] = nullptr;
	}
}

Enemy::Enemy(int lvli , std::string fname) {

	int ks;
	int khp;
	std::ifstream fs("../" + fname);
	if (fs.is_open())
	{
		fs >> ks; fs >> khp;
		fs.close();
	}
	lvl = lvli;
	it = 0;
	Isdead = 0;
	speed = ks * (3 - lvl);//CT
	hp = khp * (lvl+1);//
	slwns = 1;
	//path = nullptr;
	cor.x = SIZEL - 4;
	cor.y = SIZEL - 4;
}

Enemy::~Enemy(){
	//delete[] path;
	while (!path.empty()) 
		path.pop();
	for(auto i : Effects)
	{
		delete i;
	}
	Effects.clear();
	//delete[] Effects;
}
void Enemy::Turn(){///�������� ���� �������� � ����������� �� ����� 
	it++;
	getslwns();
	if (it >= speed*slwns)//1)����������� 
		gonext();
	it %= speed*slwns; //��� ���������� �� ������� �������� ��������

	int dmg = 0;//2)���� �� ��� 
	unsigned i;
	for (i = 0; i < Effects.size(); i++){
		if ((*Effects[i]).Effect::getType() == 2)
			dmg = (*((Poison*)Effects[i])).Poison::AddDmg(dmg);//
	}
	getHit(dmg);//������� Weak
	if (hp <= 0)
		Isdead = 1;


	i = 0;
	while(i < Effects.size())//3)�������� �� ���� �������� , ����������� , ��� ����� ��� �� �����������
	{
		if (i > Effects.size())//���� ���� �� ������� (�������� , ��������� ������ ����������)
			break;
		if ((*Effects[i]).IsGone() == 1){
			delEff(i);
			continue;
		}
		else
			i++;
	}
}


