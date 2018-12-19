#include "stdafx.h"
#include "GEnemies.h"
#include "Landscape.h"

int GEnemies::Draw(RenderWindow &window){

	dot cor;
	for (int i = 0; i < (*Enemyout).size(); i++)
		{
			if ((*Enemyout)[i].getSpeed() == 12){
				heroimage.loadFromFile("images/zubat.png");//��������� � ���� ����
				
			}
			else{
				if ((*Enemyout)[i].getSpeed() == 8){
					heroimage.loadFromFile("images/enemy2_32.png");//��������� � ���� ����
					
				}
				else 
					if ((*Enemyout)[i].getSpeed() == 4){
						heroimage.loadFromFile("images/agentsmith32.png");//��������� � ���� ����
						
					}
			}
			heroimage.createMaskFromColor(Color(255, 255, 255));
			herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)
			herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
			herosprite.setTextureRect(IntRect(0, 0, 32, 32));//�������� ������ ��� ������������� � �����
			if ((*Enemyout)[i].getSlowValue()>1)
				herosprite.setColor(Color::Blue);
			else
				herosprite.setColor(Color::White);

			cor = (*Enemyout)[i].getCor();
			herosprite.setPosition(cor.x* 32, cor.y * 32);//j i == x y
			window.draw(herosprite);//������ ���������� �� �����
		}
	//herosprite.setPosition(17 * 32, 4 * 32);//j i == x y
	//herosprite.setPosition(50, 25);//j i == x y

	//heroimage.loadFromFile("images/map.png");//��������� ���� ��� �����
	//herotexture.loadFromImage(heroimage);//�������� �������� ���������
	//herosprite.setTexture(herotexture);//�������� �������� ��������
	//herosprite.setTextureRect(IntRect(0, 0, 32, 32));
	//herosprite.setPosition(17 * 32, 4 * 32);//j i == x y
	////herosprite.setPosition(50, 25);//j i == x y

	//herosprite.setPosition(50, 25);//������ ��������� ���������� ��������� �������
	//window.draw(herosprite);//������� ������ �� �����
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
