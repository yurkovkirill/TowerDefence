#ifndef GAME_H
#define GAME_H
#include "Landscape.h"
class Game {
private:
	bool gameOver;
	bool wonLvl;
	Landscape* Land;//�� ���� ����� ��� ���������

public:
	bool getgameOver();

	bool getwonLvl();

	bool checkStatus();

	void Setup();/*std::string mfname*/

	void DrawAll();

	void TurnG(int);

	int InputK(char);

	Game();

	~Game();
};

#endif
