#ifndef PLACEABLE_H
#define PLACEABLE_H
#include "dot.h"
#include <fstream>

class Landscape;

class Placeable {

private:
	dot cor;
protected:
	Landscape* Land;
public:
	dot getCor();

protected:
	void setCor(dot cor);

public:
	Placeable();

	Placeable(Landscape* Land1 , int int_posx , int int_posy);

	void SetLand(Landscape* Land1){ this->Land = Land1; };

	//virtual void Turn();// = 0; //то же что и внизу , но просто placeable мы теперь не может создать

	/*virtual*/ //~Placeable();// = default;//дефолтный 
};

#endif
