#ifndef DOT_H
#define DOT_H
/**
\brief Класс Точки (x,y)

Вам что-то неясно ? Кстати перегружен оператор ==
*/
struct dot {
	int x;
	int y;
}
;
bool operator ==(dot const & a, dot const & b);
//нужен ли оператор присваивания перегруженный?
#endif
