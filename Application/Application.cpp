// Application.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "..\TD\Game.h"
#include <iostream>
#include <cstdlib>
int _tmain(int argc, _TCHAR* argv[])
{
	/*Game A;
	A.Game::Setup();
	int i = 0;
	while (i++ < 3000){
	A.Game::TurnG();
	}*/
	Landscape A("configMap.txt");
	A.DrawMap();
	//system("cls");

	return 0;
}

