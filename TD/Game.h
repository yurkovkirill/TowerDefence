#ifndef GAME_H
#define GAME_H
#include "Landscape.h"
class Game {
	bool gameOver;
private:
	Landscape* Land;//�� ���� ����� ��� ���������

public:

	void Setup();/*std::string mfname*/

	void DrawAll();

	void TurnG();

	Game();
};

#endif
