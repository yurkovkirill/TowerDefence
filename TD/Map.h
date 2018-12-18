#pragma once
class Graphics;
class Landscape;
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	Image map_image;//������ ����������� ��� �����
	Texture map;//�������� �����
	Sprite s_map;//������ ������ ��� �����
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

