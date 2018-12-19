#include "stdafx.h"
#include "Map.h"
#include "Landscape.h"
#include "Graphics.h"

int Map::setMap(char*** tMap){
	LMap = new char*[height];//можно избавиться
	int i = 0;
	for (i = 0; i<height; i++)
		LMap[i] = new char[width];
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			LMap[i][j] = (*tMap)[i][j];
		}
	return 1;
}

int Map::setWeapons(std::vector<Weapon*> *Weaponst){
	Weapons = Weaponst;
	return 1;
}

int Map::Draw(RenderWindow &Mwindow){
	/*sf::String TileMap[25] = {
		"0000000000000000000000000000000000000000",
		"0                                      0",
		"0   s                                  0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0                                      0",
		"0000000000000000000000000000000000000000",
	};*/
	map_image.loadFromFile("images/map.png");//загружаем файл для карты
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	s_map.setTexture(map);//заливаем спрайт

	/////////////////////////////Рисуем карту/////////////////////
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (LMap[i][j] == '.')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
			if (LMap[i][j] == '^')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
			if ((LMap[i][j] == '=')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
			if ((LMap[i][j] == '@')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
			if ((LMap[i][j] == '*')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
			//if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
			//if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
			//if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик

			s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
			Mwindow.draw(s_map);//рисуем квадратики на экран
		}


	//
	dot cor;
	map_image.loadFromFile("images/castle32.png");//загружаем файл для ЗАМКА
	map_image.createMaskFromColor(Color(255, 255, 255));
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	s_map.setTexture(map);//заливаем спрайт
	s_map.setTextureRect(IntRect(0, 0, 32, 32));//можно не писать с данной картинкой
	cor = (*(*GraphicsM).Land).getCcor();
	s_map.setPosition(cor.x * 32, cor.y * 32);
	Mwindow.draw(s_map);

	map_image.loadFromFile("images/flagblack.png");//загружаем файл для Логова
	map_image.createMaskFromColor(Color(255, 255, 255));
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	s_map.setTexture(map);//заливаем спрайт
	s_map.setTextureRect(IntRect(0, 0, 32, 32));//можно не писать с данной картинкой
	cor = (*(*GraphicsM).Land).getLcor();
	s_map.setPosition(cor.x * 32, cor.y * 32);
	Mwindow.draw(s_map);

	map_image.loadFromFile("images/2tower32.png");//загружаем файл для Логова
	map_image.createMaskFromColor(Color(255, 255, 255));
	map.loadFromImage(map_image);//заряжаем текстуру картинкой
	s_map.setTexture(map);//заливаем спрайт
	s_map.setTextureRect(IntRect(0, 0, 32, 32));//можно не писать с данной картинкой


	for (unsigned i = 0; i < (*Weapons).size(); i++)
		{
			cor = (*(*Weapons)[i]).getCor();
			//circle
			float rad = (*(*Weapons)[i]).getRad();
			sf::CircleShape shape( rad* 32);
			shape.setFillColor(sf::Color::White);
			// set a 3-pixel wide orange outline
			shape.setOutlineThickness(3);
			shape.setOutlineColor(sf::Color(250, 150, 100));
			//shape.createMaskFromColor(Color(255, 255, 255));
			shape.setPosition(cor.x * 32 - rad * 32 + 16, cor.y * 32 - rad * 32 + 16);
			Mwindow.draw(shape);


			//if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
			//if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
			//if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик

			s_map.setPosition(cor.x * 32, cor.y * 32); 
			Mwindow.draw(s_map);//рисуем квадратики на экран

			

		}



	return 1;
}

//int Map::Setup1(){
//	/*sf::String TileMap[25] = {
//	"0000000000000000000000000000000000000000",
//	"0                                      0",
//	"0   s                                  0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0                                      0",
//	"0000000000000000000000000000000000000000",
//	};*/
//	map_image.loadFromFile("images/map.png");//загружаем файл для карты
//	map.loadFromImage(map_image);//заряжаем текстуру картинкой
//	s_map.setTexture(map);//заливаем текстуру спрайтом
//
//	/////////////////////////////Рисуем карту/////////////////////
//	for (int i = 0; i < height; i++)
//		for (int j = 0; j < width; j++)
//		{
//			if (LMap[i][j] == '.')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
//			if (LMap[i][j] == '^')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
//			if ((LMap[i][j] == '=')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
//			if ((LMap[i][j] == '@')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
//			if ((LMap[i][j] == '*')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
//			//if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //если встретили символ пробел, то рисуем 1й квадратик
//			//if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//если встретили символ s, то рисуем 2й квадратик
//			//if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//если встретили символ 0, то рисуем 3й квадратик
//
//			s_map.setPosition(j * 32, i * 32);//по сути раскидывает квадратики, превращая в карту. то есть задает каждому из них позицию. если убрать, то вся карта нарисуется в одном квадрате 32*32 и мы увидим один квадрат
//			//Mwindow.draw(s_map);//рисуем квадратики на экран
//		}
//	return 1;
//}

Sprite Map::getSMap(){
	return this->s_map;
}

Map::Map()
{
}

Map::Map(Landscape* Land, Graphics* Graphicst)
{
	GraphicsM = Graphicst;
	height = (*Land).height;
	width = (*Land).width;
	setMap((*Land).getMap());
	setWeapons((*(*GraphicsM).Land).getWeapons());


}

Map::~Map()
{
	for (int i = 0; i < height; i++)
		delete[] LMap[i];
	delete[] LMap;
}
