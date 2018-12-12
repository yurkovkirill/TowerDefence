#include "stdafx.h"
#include "Weak.h"
#include <fstream>

Weak::Weak() :Effect(3, 1) {
	eff[0] = 2;
	eff[1] = eff[0] * 2;
	eff[2] = eff[0] * 4;
}

Weak::Weak(int lvld, const std::string &fname) :Effect(1, lvld){
	std::ifstream fs("../" + fname);
	if (fs.is_open())
	{
		std::string tmp;
		int i;
		for (i = 0; i < 21 ; i++){//пропускаем 7 строк 
			fs >> tmp;
		}
		for (i = 0; i < 2; i++){
			fs >> tmp; fs >> tmp; fs >> eff[i];
		}
		fs.close();
	}
}

Weak::Weak(int lvld) :Effect(3, lvld) {
	eff[0] = 2;
	eff[1] = eff[0]*2;
	eff[2] = eff[0]*4;

}

//float Weak::getWkns() {
//	return this->eff[lvl];
//}

int Weak::AddDmg(int dmg){
		dmg *= eff[lvl];
	return dmg;
}

void Weak::setWkns(int eff) {
	this->eff[0] = eff;
}
