/**
\file
\brief ������������ ���� � ������� Game

������ ���� �������� � ���� ����������� ���������
������ ���� , ������ ����� ���� �������� ��� ������
*/

/*!
\brief ���� �� �������� ������� ���� , ��������� �������

������ ����� ����� ��������� �� �������� � ���������� ���������� �� ������� ������ ����
*/
#ifndef GAME_H
#define GAME_H
#include "Landscape.h"
class Game {
private:
	bool gameOver;///< ��������� ���� == true
	bool wonLvl;///<�������� ������� == true
	Landscape* Land;///<��������� �� ��������

public:
	bool getgameOver();///< return geamOver value 

	bool getwonLvl();///< return wonLvl value

	Landscape* getLand();///<���������� ��������� �� ��������

	bool checkStatus();

	void Setup();/*std::string mfname*/

	void DrawAll();

	void TurnG(int);

	int InputK(char);

	Game();

	~Game();
};

#endif
