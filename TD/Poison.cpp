#include "stdafx.h"
#include "Poison.h"
#include <fstream>
//void Poison::setdmg(int eff) {
//	// TODO - implement Poison::setdmg
//	throw "Not yet implemented";
//}

Poison::Poison():Effect(2,0) {
	eff[0] = 4;
	eff[1] = 10;
	eff[2] = 25;
	rate = 2 * (3-lvl);
}

Poison::Poison(int lvld, const std::string &fname) :Effect(2, lvld){
	std::ifstream fs("../" + fname);
	if (fs.is_open())
	{
		std::string tmp;
		int i;
		for (i = 0; i < 9; i++){//пропускаем три строки 
			fs >> tmp;
		}
		for (i = 0; i < 2; i++){
			fs >> tmp; fs >> tmp; fs >> eff[i];
		}
		fs >> tmp; fs >> tmp; fs >> rate;
		rate = rate*(3 - lvld);
		fs.close();
	}
}

Poison::Poison(int lvld) :Effect(2, lvld) {
	eff[0] = 4;
	eff[1] = 10;
	eff[2] = 25;
	rate = 2*(3- lvl);
}

Poison::~Poison(){
	delete[] eff;
}
int Poison::AddDmg(int dmg){
	int timet = this->getTime();
	if (timet%rate == 0)
		dmg += eff[lvl];
	return dmg;
}
int Poison::getRate() {
	return this->rate;
}

void Poison::setRate(int rate) {
	this->rate = rate;
}
