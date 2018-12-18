#pragma once
#include "Map.h"
#include "GEnemies.h"
class Game;
class Landscape;
class Map;
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

