#include "stdafx.h"
#include "Lair.h"
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
	//работа с очередью , обращаемся к landscape 
}

void Lair::setwave(int wavenum , int lvl) {
	Enemy Etmp(lvl, "configEnemy.txt");
	for (unsigned i = 0; i < SIZEW*(lvl+1)*wavenum; i++){
		(Etmp).Enemy::setCor(Placeable::getCor());
		(Etmp).Enemy::setPath(path);
		Enemyin.push(Etmp);//создает копию в векторе
	}
}

void Lair::setpath() {
	// TODO - implement Lair::setpath
	throw "Not yet implemented";
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
