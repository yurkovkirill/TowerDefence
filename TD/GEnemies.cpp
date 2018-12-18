#include "stdafx.h"
#include "GEnemies.h"
#include "Landscape.h"

int GEnemies::Draw(RenderWindow &window){
	heroimage.loadFromFile("images/evil-minion.png");//��������� � ���� ����
	heroimage.createMaskFromColor(Color(255, 255, 255));
	herotexture.loadFromImage(heroimage);//�������� � ���� ������ Image (�����������)
	herosprite.setTexture(herotexture);//������� � ���� ������ Texture (��������)
	herosprite.setTextureRect(IntRect(0, 0, 32, 32));//�������� ������ ��� ������������� � �����

	dot cor;
	for (int i = 0; i < (*Enemyout).size(); i++)
		{
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
