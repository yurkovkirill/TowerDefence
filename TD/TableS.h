#ifndef TABLES_H
#define TABLES_H
#include <fstream>
class TableS {

public:
	int dmg;
	float rad;
	int rate;
	int cost;
	friend std::ifstream & operator >>(std::ifstream &c, TableS &cd);
};


#endif
