#pragma once
#include "Map.h"
#include "GEnemies.h"
class Game;
class Landscape;
class Map;
/*!
\brief Один из основных классов игры , управляет графикой

Класс не может работать без класса Game . Имеет указатель на объект ландшафта и объекты классов отвечающие за графику .
*/
class Graphics
{
public:
	Landscape* Land;
	Map* MapG;
	GEnemies* GEnemiesG;

public:
	
	Graphics(Game* Gamel);
	~Graphics();
};

