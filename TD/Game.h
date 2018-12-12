#ifndef GAME_H
#define GAME_H
#include "Landscape.h"
class Game {
	bool gameOver;
private:
	Landscape* Land;//по сути можно без указателя

public:

	void Setup();/*std::string mfname*/

	void DrawAll();

	void TurnG();

	Game();
};

#endif
