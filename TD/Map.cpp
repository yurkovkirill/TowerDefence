#include "stdafx.h"
#include "Map.h"
#include "Landscape.h"

int Map::setMap(char*** tMap){
	LMap = new char*[height];
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
	s_map.setTexture(map);//заливаем текстуру спрайтом

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

Map::Map(Landscape* Land)
{
	height = (*Land).height;
	width = (*Land).width;
	setMap((*Land).getMap());
}

Map::~Map()
{
	for (int i = 0; i < height; i++)
		delete[] LMap[i];
	delete[] LMap;
}
