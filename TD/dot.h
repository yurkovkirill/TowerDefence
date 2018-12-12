#ifndef DOT_H
#define DOT_H

struct dot {
	int x;
	int y;
}
;
bool operator ==(dot const & a, dot const & b);
//нужен ли оператор присваивания перегруженный?
#endif
