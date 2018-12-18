#include "stdafx.h"
#include "Graphics.h"
#include "Game.h"
#include "Map.h"


Graphics::Graphics(Game* Gamet) : Land((*Gamet).getLand())
{
	MapG = new Map(Land);
	GEnemiesG = new GEnemies(Land);
}


Graphics::~Graphics()
{
}
