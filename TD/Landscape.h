/**
\file
\brief Заголовочный файл с классом Landscape

Данный файл содержит в себе определение класса Landscape ,
который является инструментом в руках класса Game
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
\brief Логика на уровне 

Данный класс является инструментом в руках класса Game
*/
class Landscape  {
private:
	std::vector<Enemy> Enemyout;//доступ для других если по указателю то по ссылке ///<Здесь храняться все враги на поле
	std::vector<Weapon*> Weapons;///<Все возможные защитные механизмы
	char **Map;///<Карта , представленная в удобном для программы виде 
	Castle* CastleL;///<указатель на объект замка
	Lair* LairL;///<указатель на объект логова

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
	std::vector<Enemy> *getEnemies();//*==& он может меняться в Lair e.g.
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
