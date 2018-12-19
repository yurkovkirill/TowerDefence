#include "stdafx.h"
#include "Slow.h"
#include <fstream>

int Slow::getSlwns() {
	return this->eff[lvl];
}

//void Slow::setSlwns(int eff) {
//	// TODO - implement Slow::setSlwns
//	throw "Not yet implemented";
//}

Slow::Slow(const Slow &b) {
	type = (b.type);
	lvl = (b.lvl);
	time = (b.time);
	for (int i = 0; i < 2; i++){
		eff[i] = b.eff[i];
		time0[i] = b.time0[i];
	}


}

Slow::Slow(Slow &&b)  {
	type = (b.type);
	lvl = (b.lvl);
	time = (b.time);
	for (int i = 0; i < 2; i++){
		eff[i] = b.eff[i];
		time0[i] = b.time0[i];
	}
}

Slow::~Slow(){
	//delete[] eff;
}

Slow::Slow():Effect(1,0) {
	eff[0] = 2;
	eff[1] = 3;
	eff[2] = 5;
}

Slow::Slow(int lvld, const std::string &fname) :Effect(1, lvld){
		std::ifstream fs("../" + fname);
		if (fs.is_open())
		{
			std::string tmp;
			for (int i = 0; i < 2; i++){
				fs >> tmp; fs >> tmp; fs >> eff[i];
			}
			fs.close();
		}
}

Slow::Slow(int lvld) : Effect(1,lvld) {
	eff[0] = 2;
	eff[1] = 3;
	eff[2] = 5;
}
