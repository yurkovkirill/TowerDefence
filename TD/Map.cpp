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
	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	s_map.setTexture(map);//�������� �������� ��������

	/////////////////////////////������ �����/////////////////////
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (LMap[i][j] == '.')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
			if (LMap[i][j] == '^')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
			if ((LMap[i][j] == '=')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
			if ((LMap[i][j] == '@')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
			if ((LMap[i][j] == '*')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
			//if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
			//if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
			//if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������

			s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
			Mwindow.draw(s_map);//������ ���������� �� �����
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
//	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
//	map.loadFromImage(map_image);//�������� �������� ���������
//	s_map.setTexture(map);//�������� �������� ��������
//
//	/////////////////////////////������ �����/////////////////////
//	for (int i = 0; i < height; i++)
//		for (int j = 0; j < width; j++)
//		{
//			if (LMap[i][j] == '.')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
//			if (LMap[i][j] == '^')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
//			if ((LMap[i][j] == '=')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
//			if ((LMap[i][j] == '@')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
//			if ((LMap[i][j] == '*')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
//			//if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
//			//if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
//			//if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������
//
//			s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
//			//Mwindow.draw(s_map);//������ ���������� �� �����
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
