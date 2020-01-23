/**
\file
\brief ������������ ���� � ������� Landscape

������ ���� �������� � ���� ����������� ������ Landscape ,
������� �������� ������������ � ����� ������ Game
*/

#ifndef LANDSCAPE_H
#define LANDSCAPE_H
//#include "Placeable.h"
#include "Enemy.h"
#include "MTower.h"
#include "MTrap.h"
#include <vector>
#include "Castle.h"
#include <queue>
//SIZEL in Enemy
class Weapon;
class Castle;
class Placeable;
class Castle;
class Lair;
/*!
\brief ������ �� ������ 

������ ����� �������� ������������ � ����� ������ Game
*/
class Landscape  {
private:
	std::vector<Enemy> Enemyout;//������ ��� ������ ���� �� ��������� �� �� ������ ///<����� ��������� ��� ����� �� ����
	std::vector<Weapon*> Weapons;///<��� ��������� �������� ���������
	char **Map;///<����� , �������������� � ������� ��� ��������� ���� 
	Castle* CastleL;///<��������� �� ������ �����
	Lair* LairL;///<��������� �� ������ ������

public:
	int height; int width;
	void TurnL(int it); //death of enemyout here
	Landscape();
	Landscape(const std::string mfname);
	Landscape(const Landscape &b);
	Landscape(Landscape &&b);
	~Landscape();

	int getGold();
	int addenemy(Enemy);//
	std::vector<Enemy> *getEnemies();//*==& �� ����� �������� � Lair e.g.
	std::vector<Weapon*> *getWeapons();
	char*** getMap();
	dot getCcor();
	dot getLcor();
	void delEn(int enit);

	int BuildT(int x,int y);
	int upgradeT(int wi);//weapon i
	int BuildMT(int x, int y);
	int BuildMTrap(int x, int y);

	void DrawMap();
	void WriteInfo();

	bool getGameOver();
	bool wonLvl();
};

#endif
