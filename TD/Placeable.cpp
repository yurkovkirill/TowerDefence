#include "stdafx.h"
#include "Placeable.h"


dot Placeable::getCor() {
	return this->cor;
}

void Placeable::setCor(dot cor) {
	this->cor = cor;
}

Placeable::Placeable() {
	//
}

Placeable::Placeable(Landscape* Land1, int int_posx , int int_posy) : Land(Land1)  {
	cor.x = int_posx;
	cor.y = int_posy;
}

Placeable::~Placeable(){
	Land = nullptr;
}
