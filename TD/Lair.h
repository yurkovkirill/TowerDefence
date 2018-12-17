#ifndef LAIR_H
#define LAIR_H
#include "Placeable.h"
#include "Landscape.h"
#include <queue>
#include <vector>
const unsigned int SIZEW = 10;
struct Lairtactic{
	int timetp;//time to push
	int num;
	int lvl;
};
class Lair : public Placeable {

private:
	std::queue<Enemy> Enemyin;
	std::vector<Lairtactic> Tactic;//функция из файла
	//int timetp;//time to push
	//int wave;
	std::queue<dot> path;

public:
	dot getCor();

	void setCor(dot cor);

private:

	std::vector<Lairtactic> getTactic();

	void setTactic(std::string fname);

	void pushenemies();

	void setwave(int wavenum , int lvl);

	bool setpath(int startX, int startY, int targetX, int targetY);
public:
	Lair();

	Lair(Landscape* Land1 , int x, int y);

	void Turn(int it);//it == время всей игры 

	bool NoMoreEnemies();
};

#endif
