#ifndef ENEMY_H
#define ENEMY_H
//#include "Effect.h"
#include "dot.h"
#include <vector>
#include <queue>
#include "Poison.h"
#include "Weak.h"
#include "Slow.h"
#include <stdexcept>  

const int SIZEL = 100; //�� landscape
class Enemy {

public:
	int Isdead;
protected:
	int hp;
	dot cor;
private:
	int it;//�������� ��� �������� 
	int speed;
	std::queue<dot> path;
	int slwns;//from 1 to inf
	std::vector<Effect*> Effects;//��� nullptr ��� �������� , ��� ��� ���������� ������������ �� ����� 
	//For landscape tip : ���� insert , �� ���������� ���������� ����������� + ��� ���� ����������� = ���� 

public:
	int getHp();

	void setHp(int hp);

	int getSpeed();

	void setSpeed(int speed);

	dot getCor();


public:
	void setCor(dot cor);

	void setPath(std::queue<dot> path);

	int addEff(Effect* Eftmp);

	void delEff(int effit);

	void getHit(int dmg);

	void gonext();

	void getslwns();

	Enemy();

	Enemy(int lvl, std::string fname);

	Enemy(const Enemy &);

	Enemy(Enemy &&);

	~Enemy();

	void Turn();
};

#endif
