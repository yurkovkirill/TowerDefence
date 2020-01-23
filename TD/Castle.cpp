#include "stdafx.h"
#include "Castle.h"

int Castle::getHp() {
	return this->hp;
}

void Castle::setHp(int hp) {
	this->hp = hp;
}

int Castle::getGold() {//hack protection
	return this->gold;
}

void Castle::setGold(int gold) {
	this->gold = gold;
}

void Castle::Hit(int dmg) {
	hp = hp - dmg;
}

void Castle::Earn(int ecost) {
	gold += ecost;
}

Castle::Castle() : Placeable(), name("Highgarden")/*, hp0(hp0), hp(1000), gold(100)*/{
	//
	std::fstream fs("configCastle.txt", std::ios::in);
	if (fs.is_open())
	{
		std::string tmp;
		fs >> tmp; fs >> tmp; fs >> hp0;
		fs >> tmp; fs >> tmp; fs >> gold;
		fs >> tmp; fs >> tmp; fs >> name;
		hp = hp0;
		fs.close();
	}
}

Castle::Castle(Landscape* Land1, std::string fname, int x, int y/*, int hp0, int gold0*/) : Placeable(Land1, x, y) /*name(name), hp(hp0), hp0(hp0), gold(gold0)*/{
	//
	std::ifstream fs("../" + fname);
	if (fs.is_open())
	{
		std::string tmp;
		fs >> tmp; fs >> tmp; fs >> hp0;
		fs >> tmp; fs >> tmp; fs >> gold;
		fs >> tmp; fs >> tmp; fs >> name;
		hp = hp0;
		fs.close();
	}
}

void Castle::Turn() {
	std::vector<Enemy>* Enemyoutp = (*Land).getEnemies();
	unsigned int i = 0;
	
	//1)Enemy дошел до замка
	while (i < (*Enemyoutp).size()){
		if (i > (*Enemyoutp).size())//если ушло за границы (например , последний враг пришел)
			break;
		if ((*Enemyoutp)[i].getCor() == this->getCor()){
			hp -= (*Enemyoutp)[i].getHp();
			(*Land).delEn(i);
			continue;
		}
	else
		i++;	
	}

	//2)Gameover?
	if (this->hp <= 0){
		//запрос на провал gameover
		//Castle::~Castle(); не делать !!!
	}

			
	
}
