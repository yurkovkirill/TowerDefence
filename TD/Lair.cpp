#include "stdafx.h"
#include "Lair.h"
#include "Landscape.h"
#include "iostream"
dot Lair::getCor() {
	dot cor1 = Placeable::getCor();
	return cor1;
}

void Lair::setCor(dot cor1) { 
	Placeable::setCor(cor1);
}

std::vector<Lairtactic> Lair::getTactic(){
	return this->Tactic;
}

void Lair::setTactic(std::string fname){
	std::ifstream fs("../" + fname);
	if (fs.is_open())
	{
		std::string tmp;
		Lairtactic tmpL;
		while (!fs.eof()){
			fs >> tmp; fs >> tmp; fs >> tmpL.num;
			fs >> tmp; fs >> tmp; fs >> tmpL.timetp;
			fs >> tmp; fs >> tmp; fs >> tmpL.lvl;
			Tactic.push_back(tmpL);
		}
		fs.close();
	}
}

void Lair::pushenemies() {
	while (!Enemyin.empty()) {
		(*Land).addenemy((Enemyin.front()));
		Enemyin.pop();
	}
	//������ � �������� , ���������� � landscape 
}

void Lair::setwave(int wavenum , int lvl) {
	Enemy Etmp(lvl, "configEnemy.txt");
	for (int i = 0; i < wavenum; i++){
		(Etmp).Enemy::setCor(Placeable::getCor());
		(Etmp).Enemy::setPath(path);
		Enemyin.push(Etmp);//������� ����� � �������
	}
}
bool Lair::setpath(int startX, int startY, int targetX, int targetY) {
	
	{
		bool stop = false;
		int x, y, step = 0;
		int MapWidth = (*Land).width;
		int MapHeight = (*Land).height;
		int** cMap = new int*[MapHeight];
		int i;
		for (i = 0; i < MapHeight; i++)
			cMap[i] = new int[MapWidth];
		char** Map = (*(*Land).getMap());

		for (y = 0; y < MapHeight; y++)
			for (x = 0; x < MapWidth; x++)
			{
				if (Map[y][x] != '=')
					cMap[y][x] = -2;//��������� �����
				else
					cMap[y][x] = -1;//��������� ��� �� ������� ����
			}
		cMap[startY][startX] = 0;//�������� � ������
		cMap[targetY][targetX] = -1;
		while (!stop == true)//���� ��� ���� ������������ ��� �� �������� ������ 
		{
			//stop = true;
			for (y = 0; y < MapWidth; y++)
				for (x = 0; x < MapHeight; x++)
				{
					if (cMap[x][y] == step)
					{
						//������ �������� ����+1 � �������� ������ (���� ��� ���������)
						if (y - 1 >= 0 && cMap[x - 1][y] != -2 && cMap[x - 1][y] == -1){
							cMap[x - 1][y] = step + 1; stop = false;}
						if (x - 1 >= 0 && cMap[x][y - 1] != -2 && cMap[x][y - 1] == -1){
							cMap[x][y - 1] = step + 1; stop = false;}
						if (y + 1 < MapWidth && cMap[x + 1][y] != -2 && cMap[x + 1][y] == -1){
							cMap[x + 1][y] = step + 1; stop = false;}
						if (x + 1 < MapHeight && cMap[x][y + 1] != -2 && cMap[x][y + 1] == -1){
							cMap[x][y + 1] = step + 1; stop = false;}
					}
				}
			step++;
			if (cMap[targetY][targetX] != -1)//������� �������
				stop = true;
		}
		// �������������� ����
		/////////////////////////////////////////////////////////////
		/*for (int i = 0; i < MapHeight; i++){
			for (int j = 0; j < MapWidth; j++){
				std::cout << cMap[i][j];
			}
			std::cout << std::endl;
		}
		system("pause");*/ //PrT
		/////////////////////////////////////////////////////////////
		int len = cMap[targetY][targetX];// ����� ����������� ���� �� (ax, ay) � (bx, by)
		x = startX;// targetX;
		y = startY;// targetY;
		int d = 0;
		dot patht;
		while (d < len+1)
		{
			patht.x = x;
			patht.y = y; 
			/*std::cout << "d = " << d << std::endl;
			std::cout << x << " " << y << std::endl;
			system("pause");	*///PrT
			path.push(patht);// ���������� ������ (x, y) � ����
			d++;
			int iy; int ix;
			for (i = 0; i < 4; ++i)
			{
				if (i == 0){ iy = y; ix = x + 1; }
				if (i == 1){ iy = y; ix = x - 1; }
				if (i == 2){ iy = y + 1; ix = x; }
				if (i == 3){ iy = y - 1; ix = x; }

				if (iy >= 0 && iy < MapHeight && ix >= 0 && ix < MapWidth && cMap[iy][ix] == d)
				{
					x = ix;
					y = iy;           // ��������� � ������, ������� �� 1 ����� � ������
					break;
				}
			}
		}
		patht.x = startX;
		patht.y = startY;// ������ px[0..len] � py[0..len] - ���������� ����� ����
		for (i = 0; i < MapHeight; i++)
			delete[] cMap[i];
		delete[] cMap;
		return true;
		
}
}

Lair::Lair() :Placeable(nullptr, SIZEL-4 , SIZEL-4) /*, wave(1), lvl(0) */ {
	//for (int i = 0; i < Tactic.size();i++)//balance
	//{
	//	Tactic[i].num = (i + 1) * 3;
	//	Tactic[i].timetp = (i + 1) * 80;
	//	Tactic[i].lvl = 0;
	//}
	setTactic("configLair.txt");
}


Lair::Lair(Landscape* Land1, int x, int y) : Placeable(Land1, x, y) /*wave(1), lvl(0)*/ {
	//for (int i = 0; i < Tactic.size(); i++)//balance
	//{
	//	Tactic[i].num = (i + 1) * 3;
	//	Tactic[i].timetp = (i + 1) * 80;
	//	Tactic[i].lvl = 0;
	//}
	//path
	if (!setpath(x, y, (*Land).getCcor().x, (*Land).getCcor().y))
		throw std::exception("Path not found");
	setTactic("configLair.txt");

}

void Lair::Turn(int it) {
	//1)������� ������� ������
	if (!Tactic.empty()){
		if (Tactic[0].timetp <= it){
			/*if (it == 160)
				std::cout << std::endl;*/ //it was for PrT (check)
			setwave(Tactic[0].num, Tactic[0].lvl);
			pushenemies();
			Tactic.erase(Tactic.begin());
		}
	}
}

bool Lair::NoMoreEnemies(){
	return (Enemyin.size() == 0 && Tactic.size() == 0);
}
