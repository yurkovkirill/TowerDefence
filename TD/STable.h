#ifndef STABLE_H
#define STABLE_H
#include "TableS.h"
#include <string>
#include <fstream>

//class STable {
//
//private : 
//	TableS Specs[3];
//public:
//	int getDmg(int int_lvl);
//
//	int getRate(int int_lvl);
//
//	int getRad(int int_lvl);
//
//	int getCost(int int_lvl);
//
//	STable();
//
//	STable(const std::string &fname);
//};



template<class Type,size_t N>
class STable {

private:
	Type Specs[N];
public:
	Type getVal(int lvl){
		if ((lvl < 0)||(lvl>N-1)){
			throw std::range_error("Invalid lvl");
		}
		return this->Specs[lvl];
	}

	STable();

	STable(const std::string &fname)
	{
		std::ifstream fs("../" + fname);
		if (fs.is_open())
		{
			std::string tmp;
			for (int i = 0; i < N; i++){
				fs >> tmp; fs >> tmp; fs >> Specs[i];
				/*fs >> tmp; fs >> tmp; fs >> Specs[i].dmg;
				fs >> tmp; fs >> tmp; fs >> Specs[i].rad;
				fs >> tmp; fs >> tmp; fs >> Specs[i].rate;
				fs >> tmp; fs >> tmp; fs >> Specs[i].cost;*/
			}
			fs.close();
		}
	}
};
#endif