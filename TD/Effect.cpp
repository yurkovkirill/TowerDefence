#include "stdafx.h"
#include "Effect.h"

void Effect::setLvl(int lvl1){
	lvl = lvl1;
}
void Effect::setType(int type) {
	this->type = type;
}

int Effect::getType() {
	return this->type;
}

int Effect::getLvl() {
	return this->lvl;
}

int Effect::IsGone(){//use for eff time run
	if (time >= time0[lvl])
		return 1;
	else 
		return 0;
	time++;//то есть используем метод=идет время эффекта (не...==не идет)
}

Effect::Effect() : type(-1) , lvl(0) {
	//int time0[3] = { 20, 50, 100 };
	time0[0] = 20;//from file TODO
	time0[1] = 50;
	time0[2] = 100;
	time = 0;
}

Effect::Effect(int typed,int lvld):type(typed),lvl(lvld) {
	time0[0] = 20;//from file TODO
	time0[1] = 50;
	time0[2] = 100;
	time = 0;
}

Effect::~Effect(){
	delete[] time0;
}

int Effect::getTime() {
	return this->time;
}

void Effect::setTime(int time) {
	this->time = time;
}
//Effect::~Effect(){
//	//default
//}