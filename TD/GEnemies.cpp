#include "stdafx.h"
#include "GEnemies.h"
#include "Landscape.h"

int GEnemies::Draw(RenderWindow &window){

	dot cor;
	for (int i = 0; i < (*Enemyout).size(); i++)
		{
			if ((*Enemyout)[i].getSpeed() == 12){
				heroimage.loadFromFile("images/zubat.png");//загружаем в него файл
				
			}
			else{
				if ((*Enemyout)[i].getSpeed() == 8){
					heroimage.loadFromFile("images/enemy2_32.png");//загружаем в него файл
					
				}
				else 
					if ((*Enemyout)[i].getSpeed() == 4){
						heroimage.loadFromFile("images/agentsmith32.png");//загружаем в него файл
						
					}
			}
			heroimage.createMaskFromColor(Color(255, 255, 255));
			herotexture.loadFromImage(heroimage);//передаем в него объект Image (изображения)
			herosprite.setTexture(herotexture);//передаём в него объект Texture (текстуры)
			herosprite.setTextureRect(IntRect(0, 0, 32, 32));//получили нужный нам прямоугольник с котом
			if ((*Enemyout)[i].getSlowValue()>1)
				herosprite.setColor(Color::Blue);
			else
				herosprite.setColor(Color::White);

			cor = (*Enemyout)[i].getCor();
			herosprite.setPosition(cor.x* 32, cor.y * 32);//j i == x y
			window.draw(herosprite);//рисуем квадратики на экран
		}
	//herosprite.setPosition(17 * 32, 4 * 32);//j i == x y
	//herosprite.setPosition(50, 25);//j i == x y

	//heroimage.loadFromFile("images/map.png");//загружаем файл для карты
	//herotexture.loadFromImage(heroimage);//заряжаем текстуру картинкой
	//herosprite.setTexture(herotexture);//заливаем текстуру спрайтом
	//herosprite.setTextureRect(IntRect(0, 0, 32, 32));
	//herosprite.setPosition(17 * 32, 4 * 32);//j i == x y
	////herosprite.setPosition(50, 25);//j i == x y

	//herosprite.setPosition(50, 25);//задаем начальные координаты появления спрайта
	//window.draw(herosprite);//выводим спрайт на экран
	return 1;
}

GEnemies::GEnemies()
{
}

GEnemies::GEnemies(Landscape* Land)
{
	Enemyout=(*Land).getEnemies();
}

GEnemies::~GEnemies()
{
}
