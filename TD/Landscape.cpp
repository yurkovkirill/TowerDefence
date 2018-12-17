#include "stdafx.h"
#include "Landscape.h"
#include "Lair.h"
#include <iostream>
Landscape::Landscape(){
	Weapons.reserve(4);//
	Enemyout.reserve(10);//
	Map = nullptr;
	CastleL = nullptr;
	LairL = nullptr;
}
Landscape::Landscape(const std::string mfname){//setup like
	//��������� ����� �� �����
	std::ifstream fs("../" + mfname);
	if (fs.is_open())
	{
		std::string tmp;
		//int width; int height;
		dot Ccor; dot Lcor;
		fs >> tmp; fs >> tmp; fs >> width;
		fs >> tmp; fs >> tmp; fs >> height;
		fs >> tmp; fs >> tmp; fs >> Ccor.y; fs >> Ccor.x;
		fs >> tmp; fs >> tmp; fs >> Lcor.y; fs >> Lcor.x;
		Map = new char*[height];
		int i = 0;
		for (i = 0; i<height; i++)
			Map[i] = new char[width];
		for (i = 0; i < height; i++)
		{
			fs.get();
			for (int j = 0; j < width; j++){
				Map[i][j] = fs.get();
			}
		}
		fs.close();
		CastleL = new Castle(this, "configCastle.txt", Ccor.x, Ccor.y);
		LairL = new Lair(this, Lcor.x, Lcor.y);
	}
	
}

Landscape::~Landscape(){
	for (int i = 0; i < height; i++)
		delete[] Map[i];
	delete[] Map;
}
std::vector<Enemy> * Landscape::getEnemies(){
	return &(this->Enemyout);
}

char*** Landscape::getMap(){
	return &(this->Map);
}
dot Landscape::getCcor(){
	return (*CastleL).getCor();
}
dot Landscape::getLcor(){
	return (*LairL).getCor();
}

void Landscape::delEn(int enit) {//��������� [enit]
	if (enit < 0){
		throw std::exception("Invalid effit");
	}
	(*CastleL).Earn(4 * (Enemyout)[enit].getSpeed());//���� ������ ��� ���������!
	//delete &(Enemyout[enit]);
	Enemyout.erase(Enemyout.begin() + enit);
}

void Landscape::TurnL(int it) {
	//1)������� ����� �������� �� ������
	unsigned i = 0;
	for (i = 0; i < Weapons.size(); i++)
		(*Weapons[i]).Turn();

	//2)����� ��������� ������ � ������� ��� ������ 
	i = 0;
	while (i < Enemyout.size()){
		(Enemyout[i]).Turn();
		if ((Enemyout[i]).Isdead == 1){
			delEn(i);//��������� ����� ��������� ���
			continue;
		}
		else
			i++;
	}
	(*CastleL).Turn();
	(*LairL).Turn(it);
	std::cout << it << std::endl;
}
	//���������� �� ���� , ��� � Game � ��������� �������� ��� ��
int Landscape::BuildT(int x, int y){
	int Tcost = 100;//���������� �� ����� ����� @ � ����� ������� ��������� , ����� ������ CT
	if ((*CastleL).getGold() < Tcost)
		return 0;
	else
	{
		if (Map[y][x] == '.'){//CT
			Weapon* Etmp = new Tower(this, x, y, 0, "configTowers.txt");
			Weapons.push_back(Etmp);//��� �� ���������� Etmp , �����(?)
			Etmp = nullptr;
		}
		else
			return -1;

	}
	return 1;
}
int Landscape::upgradeT(int wi){//weapon i
	return (*Weapons[wi]).LevelUp();
}

int Landscape::BuildMT(int x, int y){
	int Tcost = 150;//���������� �� ����� ����� @ � ����� ������� ��������� , ����� ������ CT
	if ((*CastleL).getGold() < Tcost)
		return 0;
	else
	{
		if (Map[y][x] == '.'){
			Weapon* Etmp = new MTower(this, x, y, 0, 1,  "configTowers.txt");//Slow=1
			Weapons.push_back(Etmp);
			Etmp = nullptr;
		}
		else
			return -1;

	}
	return 1;
}

int Landscape::BuildMTrap(int x, int y){
	int Tcost = 125;//���������� �� ����� ����� @ � ����� ������� ��������� , ����� ������
	if ((*CastleL).getGold() < Tcost)
		return 0;
	else
	{
		if (Map[y][x] == '.'){
			Weapon* Etmp = new MTrap(this, x, y, 0, 1, "configMTrap.txt");//Slow == 1
			Weapons.push_back(Etmp);
			Etmp = nullptr;
		}
		else
			return -1;

	}
	return 1;
}

void Landscape::DrawMap(){
	for (int i = 0; i < height; i++){
		for (int j = 0; j < width; j++){
			std::cout << Map[i][j];
		}
		std::cout << std::endl;
	}
}

void Landscape::WriteInfo(){
	std::cout << "There are " << Enemyout.size() << " enemies " << std::endl;
	std::cout << "There are " << Weapons.size() << " towers " << std::endl;
	std::cout << "Castle HP = " << (*CastleL).getHp() << "  " << std::endl;
}

int Landscape::addenemy(Enemy Enemyt){
	//Enemy Etmp = *Enemyt;
	Enemyout.push_back(Enemyt);
	return 1;
}

bool Landscape::getGameOver(){
	return ((*CastleL).getHp() <= 0);
}

bool Landscape::wonLvl(){
	return (Enemyout.size() == 0 && (*LairL).NoMoreEnemies());
}