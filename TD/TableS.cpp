#include "stdafx.h"
#include "TableS.h"

std::ifstream & operator >>(std::ifstream &c, TableS &cd)
{
	std::string tmp;
	c >> cd.dmg; c >> cd.rad; c >> cd.rate; c >> cd.cost;
	return c;
}