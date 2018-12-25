#pragma once
class Graphics;
class Landscape;

class Weapon;
class Lair;
class Castle;
#include <SFML\Graphics.hpp>
using namespace sf;
/*!
\brief Графика карты и неподвижных объектов

Связан с основным классом графики
*/
class Map
{
public:
	Image map_image;//объект изображения для карты
	Texture map;//текстура карты
	Sprite s_map;//создаём спрайт для карты
private:
	Graphics* GraphicsM;
	char*** LMap;///<указатель на таблицу карты из Landscape
	int height; int width;///< Для удобства работы с картой

	std::vector<Weapon*> *Weapons;///<указатель на вектор защитных построек карты из Landscape
public:
	int setMap(char***);//здесь башни логово и замок

	int setWeapons(std::vector<Weapon*> *Weapons);

	int Draw(RenderWindow &Mwindow);
	int Setup1();
	Sprite getSMap();
	Map(Landscape* Land, Graphics* GraphicsM);
	Map();
	~Map();
};

