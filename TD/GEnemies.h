#pragma once
#pragma once
class Graphics;
class Landscape;
class Enemy;
#include <SFML\Graphics.hpp>
using namespace sf;

class GEnemies
{
public : 
	Image heroimage; //создаем объект Image (изображение)
	Texture herotexture;//создаем объект Texture (текстура)
	Sprite herosprite;//создаем объект Sprite(спрайт)
private:
	Graphics* Graphics;
	std::vector<Enemy> *Enemyout;
public:
	int Draw(RenderWindow &window);

	GEnemies(Landscape* Land);
	GEnemies();
	~GEnemies();
};

