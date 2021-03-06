#include "stdafx.h"
#include "Map.h"
#include "Landscape.h"
#include "Graphics.h"

int Map::setMap(char*** tMap){
	LMap = tMap;
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
	map_image.loadFromFile("images/map.png");//��������� ���� ��� �����
	map.loadFromImage(map_image);//�������� �������� ���������
	s_map.setTexture(map);//�������� ������

	/////////////////////////////������ �����/////////////////////
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if ((*LMap)[i][j] == '.')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ., �� ������ 1� ���������
			if ((*LMap)[i][j] == '^')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ ^, �� ������ 2� ���������
			if ((*LMap)[i][j] == '=') s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ =, �� ������ 3� ���������
			if ((*LMap)[i][j] == '@') s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ @, �� ������ �����
			if ((*LMap)[i][j] == '*') s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ *, �� ������ ������

			s_map.setPosition(j * 32, i * 32);//�� ���� ����������� ����������, ��������� � �����. �� ���� ������ ������� �� ��� �������. ���� ������, �� ��� ����� ���������� � ����� �������� 32*32 � �� ������ ���� �������
			Mwindow.draw(s_map);//������ ���������� �� �����
		}


	//������ �����
	dot cor;
	map_image.loadFromFile("images/castle32.png");//��������� ���� ��� �����
	map_image.createMaskFromColor(Color(255, 255, 255));
	map.loadFromImage(map_image);//�������� �������� ���������
	s_map.setTexture(map);//�������� ������
	s_map.setTextureRect(IntRect(0, 0, 32, 32));//����� �� ������ � ������ ���������
	cor = (*(*GraphicsM).Land).getCcor();
	s_map.setPosition(cor.x * 32, cor.y * 32);
	Mwindow.draw(s_map);

	//������ ������
	map_image.loadFromFile("images/flagblack.png");//��������� ���� ��� ������
	map_image.createMaskFromColor(Color(255, 255, 255));
	map.loadFromImage(map_image);//�������� �������� ���������
	s_map.setTexture(map);//�������� ������
	s_map.setTextureRect(IntRect(0, 0, 32, 32));//����� �� ������ � ������ ���������
	cor = (*(*GraphicsM).Land).getLcor();
	s_map.setPosition(cor.x * 32, cor.y * 32);
	Mwindow.draw(s_map);

	//������ �����
	for (unsigned i = 0; i < (*Weapons).size(); i++)
		{
			Weapon* W = (*Weapons)[i];
			if ((*W).getLvl() == 0){
				map_image.loadFromFile("images/tower1lvl.png");//��������� ���� ��� �����

			}
			else{
				if ((*W).getLvl() == 1){
					map_image.loadFromFile("images/tower2lvl.png");//��������� � ���� ����

				}
				else
				if ((*W).getLvl() == 2){
					map_image.loadFromFile("images/shield.png");//��������� � ���� ����

				}
			}
			map_image.createMaskFromColor(Color(255, 255, 255));
			map.loadFromImage(map_image);//�������� �������� ���������
			s_map.setTexture(map);//�������� ������
			s_map.setTextureRect(IntRect(0, 0, 32, 32));//����� �� ������ � ������ ���������

			cor = (*W).getCor();
			//circle
			float rad = (*W).getRad();
			sf::CircleShape shape( rad* 32);
			shape.setFillColor(sf::Color(255, 255, 255, 128)); //sf::Color::Transparent sf::Color(255, 255, 255, 128)
			// set a 3-pixel wide orange outline
			shape.setOutlineThickness(3);
			shape.setOutlineColor(sf::Color(100, 150, 100));
			//shape.createMaskFromColor(Color(255, 255, 255));
			shape.setPosition(cor.x * 32 - rad * 32 + 16, cor.y * 32 - rad * 32 + 16);
			Mwindow.draw(shape);


			//if (TileMap[i][j] == ' ')  s_map.setTextureRect(IntRect(0, 0, 32, 32)); //���� ��������� ������ ������, �� ������ 1� ���������
			//if (TileMap[i][j] == 's')  s_map.setTextureRect(IntRect(32, 0, 32, 32));//���� ��������� ������ s, �� ������ 2� ���������
			//if ((TileMap[i][j] == '0')) s_map.setTextureRect(IntRect(64, 0, 32, 32));//���� ��������� ������ 0, �� ������ 3� ���������

			s_map.setPosition(cor.x * 32, cor.y * 32); 
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
	//
}
