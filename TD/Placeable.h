#ifndef PLACEABLE_H
#define PLACEABLE_H
#include "dot.h"
#include <fstream>

class Landscape;
/**
\brief ������������ ����� ��� ������� ������������ �������

����� ��������� �� �������� � ������� ���������
*/
class Placeable {

private:
	dot cor;
protected:
	Landscape* Land;
protected:
	void setCor(dot cor);

public:
	dot getCor();///<�������� ����������

	Placeable();

	Placeable(Landscape* Land1 , int int_posx , int int_posy);///<�������� �����������

	~Placeable();

	void SetLand(Landscape* Land1){ this->Land = Land1; };///<������ ��������� �� ��������
};

#endif
