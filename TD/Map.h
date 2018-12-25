#pragma once
class Graphics;
class Landscape;

class Weapon;
class Lair;
class Castle;
#include <SFML\Graphics.hpp>
using namespace sf;

class Map
{
public:
	Image map_image;//������ ����������� ��� �����
	Texture map;//�������� �����
	Sprite s_map;//������ ������ ��� �����
private:
	Graphics* GraphicsM;
	char*** LMap;
	int height; int width;

	std::vector<Weapon*> *Weapons;
public:
	int setMap(char***);//����� ����� ������ � �����

	int setWeapons(std::vector<Weapon*> *Weapons);

	int Draw(RenderWindow &Mwindow);
	int Setup1();
	Sprite getSMap();
	Map(Landscape* Land, Graphics* GraphicsM);
	Map();
	~Map();
};

