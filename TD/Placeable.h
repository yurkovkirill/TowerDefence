#ifndef PLACEABLE_H
#define PLACEABLE_H
#include "dot.h"
#include <fstream>

class Landscape;
/**
\brief Родительский класс для всякого неподвижного объекта

Имеет указатель на Ландшафт в котором находится
*/
class Placeable {

private:
	dot cor;
protected:
	Landscape* Land;
protected:
	void setCor(dot cor);

public:
	dot getCor();///<получить координаты

	Placeable();

	Placeable(Landscape* Land1 , int int_posx , int int_posy);///<Основной конструктор

	~Placeable();

	void SetLand(Landscape* Land1){ this->Land = Land1; };///<Задать указатель на ландшафт
};

#endif
