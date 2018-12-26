#ifndef STABLE_H
#define STABLE_H
#include "TableS.h"
#include <string>
#include <fstream>

template <class Type,size_t N>
 class STable;
template<typename Type>
class MyIterator
{
	/*friend class STable<Type>;*/
	Type* value; // значение
public:
	// Конструкторы
	MyIterator() : value(nullptr){}
	MyIterator(const MyIterator&it) :value(it.value){}
	MyIterator operator=(MyIterator const &it){ if (*this != it) value = value.p; return *this; }
	bool operator > (MyIterator const &oi) const{ return value > oi.value; }
	bool operator < (MyIterator const &oi) const{ return value < oi.value; }
	bool operator != (MyIterator const &oi) const{ return value != oi.value; }
	bool operator == (MyIterator const &oi) const{ return value == oi.value; }
	MyIterator operator+(const int i) const { return (value + i); }
	Type& operator*() const { if (value == nullptr) throw std::exception("Iterator not inited"); else return *p; }
	Type& operator->() const { if (value == nullptr) throw std::exception("Iterator not inited"); else return p; }
	MyIterator& operator++(){ if (value == nullptr) throw std::exception("Iterator not inited"); else p += 1; return *this }
	MyIterator& operator--(){ if (value == nullptr) throw std::exception("Iterator not inited"); else p -= 1; return *this }
	template <typename U, std::size_t N>
	MyIterator(STable<U, N> & arr)  // инициализируем итератор первым элементом шаблона
	{
		value = arr.getVal(0);
	}

	// Методы
	Type operator*() // получаем текущий элемент
	{
		return *this->value;
	}

};
/**
\brief Шаблон класс для хранения характеристик неподвижных объектов

*/
template<class Type,size_t N>
class STable {

private:
	Type Specs[N];
public:
	typedef MyIterator<Type> iterator;
	iterator begin(){ return Specs[0]; }
	iterator end(){ return Specs[N-1]; }
	Type getVal(int lvl){
		if ((lvl < 0)||(lvl>N-1)){
			throw std::range_error("Invalid lvl");
		}
		return this->Specs[lvl];
	}

	STable();

	STable(const std::string &fname)
	{
		std::ifstream fs("../" + fname);
		if (fs.is_open())
		{
			std::string tmp;
			for (int i = 0; i < N; i++){
				fs >> tmp; fs >> tmp; fs >> Specs[i];
				/*fs >> tmp; fs >> tmp; fs >> Specs[i].dmg;
				fs >> tmp; fs >> tmp; fs >> Specs[i].rad;
				fs >> tmp; fs >> tmp; fs >> Specs[i].rate;
				fs >> tmp; fs >> tmp; fs >> Specs[i].cost;*/
			}
			fs.close();
		}
	}
};


#endif