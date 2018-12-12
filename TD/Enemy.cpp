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

void Enemy::addEff(Effect* Eftmp) {
	int typetmp = (*Eftmp).Effect::getType();
	if ((*Effects[typetmp]).getLvl() > (*Eftmp).getLvl()){///
		Effects[typetmp] = (Eftmp);///
	}
}

void Enemy::delEff(int effit) {//удаляется [effit]
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
	if (!path.empty()){//если вдруг уже в конце, то ничего не происходит
		cor = path.front();
		path.pop();
	}
}

void Enemy::getslwns(){
	for (unsigned i = 0; i < Effects.size(); i++)
		if ((*Effects[i]).Effect::getType() == 1)
			slwns *= (*((Slow*)Effects[i])).Slow::getSlwns(/*((*Effects[i]).Effect::getLvl())*/);//
}

Enemy::Enemy() {
	int lvl = 0;
	it = 0;
	Isdead = 0;
	speed = 4 * (3 - lvl);//
	hp = 50 * (lvl + 1);//
	//path = nullptr;
	slwns = 1;
	cor.x = SIZEL - 4;
	cor.y = SIZEL - 4;
}

Enemy::Enemy(int lvl , std::string fname) {

	int ks;
	int khp;
	std::ifstream fs("../" + fname);
	if (fs.is_open())
	{
		fs >> ks; fs >> khp;
		fs.close();
	}
	it = 0;
	Isdead = 0;
	speed = ks * (3 - lvl);//
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
void Enemy::Turn(){
	it++;
	if (it >= speed*slwns)//1)продвижение 
		gonext();
	it %= speed*slwns; //при избавлении от эффекта обновить итератор

	int dmg = 0;//2)урон от яда 
	unsigned i;
	for (i = 0; i < Effects.size(); i++){
		if ((*Effects[i]).Effect::getType() == 2)
			dmg = (*((Poison*)Effects[i])).Poison::AddDmg(dmg);//
	}
	getHit(dmg);//наложит Weak
	if (hp <= 0)
		Isdead = 1;


	i = 0;
	while(i < Effects.size())//3)проверка на уход эффектов , обязательно , без этого они не закончаться
	{
		if (i > Effects.size())//если ушло за границы (например , последний эффект закончился)
			break;
		if ((*Effects[i]).IsGone() == 1){
			delEff(i);
			continue;
		}
		else
			i++;
	}
}


