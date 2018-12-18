#pragma once
class Graphics;
class Landscape;
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	Image map_image;//объект изображения для карты
	Texture map;//текстура карты
	Sprite s_map;//создаём спрайт для карты
private:
	Graphics* Graphics;
	char** LMap;
	int height; int width;
public:
	int setMap(char***);
	int Draw(RenderWindow &Mwindow);
	int Setup1();
	Sprite getSMap();
	Map(Landscape* Land);
	Map();
	~Map();
};

