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
/**
\brief ����� �����

����� ������ � ������������ ��������� ������ ���� �������� � ������ �� ��������� ��������������� �� ����,
��� ����� ��������������� ������ ��� � �� ���������, �� �������, �� �������, �� �������, �� �����, �� �����, � ��� �������������, ����� ���� �������� �� ��� ��������� (����. 37:13),
���� �� ����� ������� �������� ��������� �� � ��������� ��� �������� ����.
*/
class Enemy {

public:
	int Isdead;///<Is Dead?
protected:
	int hp;
	dot cor;///< ������� �������
private:
	int it;///<�������� ��� �������� 
	int speed;///<������ speed*slwns ��������� ���� �����
	std::queue<dot> path;///< ���� , ������ ������� ��� 
	int slwns;///<from 1 to inf
	int lvl;
	std::vector<Effect*> Effects;///<������ ���������� ��������
	

public:
	int getHp();

	void setHp(int hp);

	int getSpeed();

	int getLvl();

	void setSpeed(int speed);

	dot getCor();


public:
	void setCor(dot cor);

	void setPath(std::queue<dot> path);

	int addEff(Effect* Eftmp);

	void delEff(int effit);

	void getHit(int dmg);

	void gonext();

	void getslwns();///<���������� ����� �������� �� ��������

	int getSlowValue();///<Value

	Enemy();

	Enemy(int lvl, std::string fname);

	Enemy(const Enemy &);

	Enemy(Enemy &&);

	~Enemy();

	void Turn();
};

#endif
