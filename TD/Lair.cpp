#include "stdafx.h"
#include "Lair.h"
#include "Landscape.h"
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
	Enemy* Etmpo;
	while (!Enemyin.empty()) {
		Etmpo = &(Enemyin.front());
		Enemyin.pop();
		(*Land).addenemy(Etmpo);
	}
	//работа с очередью , обращаемс€ к landscape 
}

void Lair::setwave(int wavenum , int lvl) {
	Enemy Etmp(lvl, "configEnemy.txt");
	for (unsigned i = 0; i < SIZEW*(lvl+1)*wavenum; i++){
		(Etmp).Enemy::setCor(Placeable::getCor());
		(Etmp).Enemy::setPath(path);
		Enemyin.push(Etmp);//создает копию в векторе
	}
}

bool Lair::setpath(int startX, int startY, int targetX, int targetY) {
	/// ѕоиск пути (¬олновой)
	/// </summary>
	/// <param name="startX"> оордината старта X</param>
	/// <param name="startY"> оордината старта Y</param>
	/// <param name="targetX"> оордината финиша X</param>
	/// <param name="targetY"> оордината финиша Y</param>
	{
		bool stop = false;
		int x, y, step = 0; 
		int MapWidth = (*Land).width;
		int MapHeight = (*Land).height;
		int** cMap = new int*[];
		int i;
		for (i = 0; i < MapHeight; i++)
			cMap[i] = new int[];
		char** Map = (*(*Land).getMap());

		for (y = 0; y < MapHeight; y++)
			for (x = 0; x < MapWidth; x++)
			{
				if (Map[y][x] != '=')
					cMap[y][x] = -2;//индикатор стены
				else
					cMap[y][x] = -1;//индикатор еще не ступали сюда
			}
		cMap[startY][startX] = 0;//Ќачинаем с финиша
		cMap[targetY][targetX] = -1;
		while (!stop == true)//пока еще есть непомеченные или не достигли финиша 
		{
			stop = true;
			for (y = 0; y < MapWidth; y++)
				for (x = 0; x < MapHeight; x++)
				{
					if (cMap[x][y] == step)
					{
						//—тавим значение шага+1 в соседние €чейки (если они проходимы)
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
			if (cMap[targetY][targetX] != -1)//решение найдено
				stop = true;
		}
		// восстановление пути
		int len = cMap[targetX][targetY];// длина кратчайшего пути из (ax, ay) в (bx, by)
		x = targetX;
		y = targetY;
		int d = len;
		dot patht;
		while (d > 0)
		{
			patht.x = x;
			patht.y = y;
			path.push(patht);// записываем €чейку (x, y) в путь
			d--;
			int iy; int ix;
			for (i = 0; i < 4; ++i)
			{
				if (i == 0){ iy = y + 1; ix = x + 1; }
				if (i == 1){ iy = y - 1; ix = x + 1; }
				if (i == 2){ iy = y + 1; ix = x - 1; }
				if (i == 3){ iy = y - 1; ix = x - 1; }

				if (iy >= 0 && iy < MapHeight && ix >= 0 && ix < MapWidth && cMap[iy][ix] == d)
				{
					x = ix;
					y = iy;           // переходим в €чейку, котора€ на 1 ближе к старту
					break;
				}
			}
		}
		patht.x = startX;
		patht.y = startY;// теперь px[0..len] и py[0..len] - координаты €чеек пути
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
	//1)тактика выпуска врагов
	if (!Tactic.empty()){
		if (Tactic[0].timetp >= it){
			setwave(Tactic[0].num, Tactic[0].lvl);
			pushenemies();
			Tactic.erase(Tactic.begin());
		}
	}
}
