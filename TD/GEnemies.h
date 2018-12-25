#pragma once
#pragma once
class Graphics;
class Landscape;
class Enemy;
#include <SFML\Graphics.hpp>
using namespace sf;
/*!
\brief ������� ������

������ � �������� ������� ������� 
*/
class GEnemies
{
public : 
	Image heroimage; //������� ������ Image (�����������)
	Texture herotexture;//������� ������ Texture (��������)
	Sprite herosprite;//������� ������ Sprite(������)
private:
	Graphics* Graphics;
	std::vector<Enemy> *Enemyout;///<��������� �� ������ ������ �� ���������
public:
	int Draw(RenderWindow &window);///< \param window - ���� � ������� ����� ��������

	GEnemies(Landscape* Land);
	GEnemies();
	~GEnemies();
};

