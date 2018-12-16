#include "stdafx.h"
#include "Game.h"

void Game::Setup(){
	Land = new Landscape("configMap.txt");
}

void Game::DrawAll(){
	(*Land).DrawMap();
}
void Game::TurnG() {
	//draw
	DrawAll();
	system("clear");
	//input
	//Logic

}
Game::Game(): gameOver(false) {
	//setup
}

Game::~Game(){
	delete Land;
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