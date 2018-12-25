#pragma once
#pragma once
class Graphics;
class Landscape;
class Enemy;
#include <SFML\Graphics.hpp>
using namespace sf;
/*!
\brief Графика врагов

Связан с основным классом графики 
*/
class GEnemies
{
public : 
	Image heroimage; //создаем объект Image (изображение)
	Texture herotexture;//создаем объект Texture (текстура)
	Sprite herosprite;//создаем объект Sprite(спрайт)
private:
	Graphics* Graphics;
	std::vector<Enemy> *Enemyout;///<указатель на вектор врагов из ландшафта
public:
	int Draw(RenderWindow &window);///< \param window - окно в котором будем рисовать

	GEnemies(Landscape* Land);
	GEnemies();
	~GEnemies();
};

