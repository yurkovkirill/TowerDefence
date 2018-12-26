#ifndef LAIR_H
#define LAIR_H
#include "Placeable.h"
#include "Landscape.h"
#include <queue>
#include <vector>
const unsigned int SIZEW = 10;

/**
\brief Структура для понятного хранения единицы тактики 
*/
struct Lairtactic{
	int timetp;//time to push
	int num;
	int lvl;
};
/**
\brief Класс логова

Генерирует волны врагов в зависимости тактики из файла
*/
class Lair : public Placeable {

private:
	std::queue<Enemy> Enemyin;
	std::vector<Lairtactic> Tactic;//функция из файла
	//int timetp;//time to push
	//int wave;
	std::queue<dot> path;

public:
	dot getCor();

	void setCor(dot cor);

private:
	/*!
	\brief Возвращает вектор с тактикой

	Геттер
	*/
	/// \return Возвращает вектор с тактикой в данный момент времени
	std::vector<Lairtactic> getTactic();
	/*!
	\brief Загружает тактику в объект класса

	Fname файл с определенной структурой(см.приложенные файлы)
	*/
	/// \param fname файл с тактикой определенного вида (см.описание)
	/// \throws runtime_error Если файл не найден в данной директории
	void setTactic(std::string fname);
	/*!
	\brief Выгружает всех врагов 

	Выгружает всех врагов сгенерированных внутри объекта класса в ландшафт (во вне)
	*/
	void pushenemies();
	/*!
	\brief Генерирует волну врагов

	
	*/
	/// \param wavenum кол-во генерируемых врагов
	/// \param lvl уровень генерируемых врагов
	/// \throws exception1 Если файл не найден в данной директории
	void setwave(int wavenum , int lvl);
	/*!
	\brief Определяет дальнейший путь врагов

	Здесь реализован алгоритм поиска пути , а именнно алгоритм Ли или т.н. Волновой алгоритм
	*/
	/// \param startX Координата старта X
	/// \param startY Координата старта Y
	/// \param targetX Координата финиша X
	/// \param targetY Координата финиша Y
	/// \return возвращает true , если путь найден . Возвращает false если нет 
	/// \throws exception1 если на карте нет пути , вызывается exception
	bool setpath(int startX, int startY, int targetX, int targetY);
public:
	Lair();

	Lair(Landscape* Land1 , int x, int y);
	/*!
	\brief Шаг логики Логова

	Проверяется тактика и в связи с заданной тактикой выполняется гненерация врагов и дальнейший их вывод на поле
	*/
	/// \param it логическое время игры
	/// \throws exception1 Если файлы с конфигурацией для Врага и Логова не найдены 
	void Turn(int it);//it == время всей игры 
	/*!
	\brief Проверка на наличие врагов

	Проверяется наличие врагов планируемых
	*/
	bool NoMoreEnemies();
};

#endif
