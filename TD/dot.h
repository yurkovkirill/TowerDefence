#ifndef DOT_H
#define DOT_H
/**
\brief ����� ����� (x,y)

Int
��� ���-�� ������ ? ������ ���������� �������� ==
*/
struct dot {
	int x;
	int y;
}
;
bool operator ==(dot const & a, dot const & b);
//����� �� �������� ������������ �������������?
#endif
