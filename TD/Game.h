/**
\file
\brief Заголовочный файл с классом Game

Данный файл содержит в себе определение основного
класса игры , именно через него работает вся логика
*/

/*!
\brief Один из основных классов игры , управляет логикой

Данный класс имеет указатель на ландшафт и переменные отвечающие за текущий статус игры
*/
#ifndef GAME_H
#define GAME_H
#include "Landscape.h"
class Game {
private:
	bool gameOver;///< Проиграли игру == true
	bool wonLvl;///<Выйграли уровень == true
	Landscape* Land;///<указатель на ландшафт

public:
	bool getgameOver();///< return geamOver value 

	bool getwonLvl();///< return wonLvl value

	Landscape* getLand();///<Возвращает указатель на ландшафт

	bool checkStatus();

	void Setup();/*std::string mfname*/

	void DrawAll();

	void TurnG(int);

	int InputK(char);

	Game();

	~Game();
};

#endif
