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
class Landscape  {
private:
	std::vector<Enemy> Enemyout;//доступ для других если по указателю то по ссылке
	std::vector<Weapon*> Weapons;
	char **Map;//
	int height; int width;
	Castle* CastleL;//
	Lair* LairL;

public:
	void TurnL(); //death of enemyout here
	Landscape();
	Landscape(const std::string mfname);
	int addenemy(Enemy*);//
	std::vector<Enemy> *getEnemies();//*==& он может меняться в Lair e.g.
	char*** getMap();
	void delEn(int enit);

	int BuildT(int x,int y);
	int upgradeT(int wi);//weapon i
	int BuildMT(int x, int y);
	int BuildMTrap(int x, int y);

	void DrawMap();

};

#endif
