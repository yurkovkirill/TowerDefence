#ifndef TABLES_H
#define TABLES_H
#include <fstream>
/**
\brief  ласс €чейки данных 

ƒл€ частного случа€ STable . »спользуетс€ дл€ в классах защитных построек . ѕерегружен оператор >> ( дл€ текстового файла ) 
*/
class TableS {

public:
	int dmg;
	float rad;
	int rate;
	int cost;
	friend std::ifstream & operator >>(std::ifstream &c, TableS &cd);
};


#endif
