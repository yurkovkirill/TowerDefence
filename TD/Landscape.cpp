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
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++){
				fs >> Map[i][j];
			}
		fs.close();
		LairL = new Lair(this , Lcor.x, Lcor.y);
		CastleL = new Castle(this, "configCastle.txt", Ccor.x, Ccor.y);
	}
	
}
std::vector<Enemy> * Landscape::getEnemies(){
	return &(this->Enemyout);
}

char*** Landscape::getMap(){
	return &(this->Map);
}

void Landscape::delEn(int enit) {//��������� [enit]
	if (enit < 0){
		throw std::exception("Invalid effit");
	}
	(*CastleL).Earn(4 * (Enemyout)[enit].getSpeed());//���� ������ ��� ���������!
	//delete &(Enemyout[enit]);
	Enemyout.erase(Enemyout.begin() + enit);
}

void Landscape::TurnL() {
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
}
	//���������� �� ���� , ��� � Game � ��������� �������� ��� ��
int Landscape::BuildT(int x, int y){
	int Tcost = 100;//���������� �� ����� ����� @ � ����� ������� ��������� , ����� ������
	if ((*CastleL).getGold() < Tcost)
		return 0;
	else
	{
		if (Map[x][y] == '.'){
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
	int Tcost = 150;//���������� �� ����� ����� @ � ����� ������� ��������� , ����� ������
	if ((*CastleL).getGold() < Tcost)
		return 0;
	else
	{
		if (Map[x][y] == '.'){
			Weapon* Etmp = new MTower(this, x, y, 0, 1,  "configSTable.txt");//Slow=1
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
		if (Map[x][y] == '.'){
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
