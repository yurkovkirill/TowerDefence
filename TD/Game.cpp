#include "stdafx.h"
#include "Game.h"
#include <cstdlib>
#include <iostream>
using namespace std;

bool Game::getgameOver(){
	return this->gameOver;
}

bool Game::getwonLvl(){
	return this->wonLvl;
}

bool Game::checkStatus(){
	if (gameOver){
		cout << "GAME OVER" << endl;
		return true;
	}
	if (wonLvl){
		cout << "WON LVL ! CONGRATS !" << endl;
		return true;
	}
	return false;
}

void Game::Setup(){
	Land = new Landscape("configMap.txt");
}

void Game::DrawAll(){
	(*Land).DrawMap();
	(*Land).WriteInfo();
}
void Game::TurnG(int it) {
	//draw
	DrawAll();
	system("cls");
	//input
	//Logic
	(*Land).TurnL(it);
	gameOver = (*Land).getGameOver();
	wonLvl = (*Land).wonLvl();

}
Game::Game(): gameOver(false) , wonLvl(false) {
	//setup
	Setup();
}

Game::~Game(){
	delete Land;
}

int Game::InputK(char key){
	switch (key)
	{
		case 'T':
			int fl = (*Land).BuildMT(9,3);//CT
			switch (fl)
			{
			case 0:
				cout << "Not enough gold " <<  endl;
				break;
			case -1:
				cout << "Not for building place" << endl;
				break;
			case 1:
				cout << "Tower Builded" << endl;
				return 1;
				break;
			}
	break;
						/*case 'B':
							cout << "Choose, what to build: T - tower, W - wall, Q - quit (from build menu): ";
							cin.ignore(cin.rdbuf()->in_avail());
							buf1 = '0';
							flagBreak1 = 0;
							while (!flagBreak1)
							{
								buf1 = cin.get();
								if (!cin.good())
									throw exception("input_error");
								switch (buf1)
								{
								case 'W':
									t = 11;
									flagBreak1 = 1;
									break;
								case 'T':
									t = 12;
									flagBreak1 = 1;
									break;
								case 'Q':
									flagBreak1 = 1;
									flagBreak = 1;
									break;
								}*/
	}
	return 0;
}


//int main{
//	Game();
//	while (!gameOver){
//		TurnG();
//		//draw
//		//input
//		//logic
//	}
//}