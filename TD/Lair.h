#ifndef LAIR_H
#define LAIR_H
#include "Placeable.h"
#include "Landscape.h"
#include <queue>
#include <vector>
const unsigned int SIZEW = 10;

/**
\brief ��������� ��� ��������� �������� ������� ������� 
*/
struct Lairtactic{
	int timetp;//time to push
	int num;
	int lvl;
};
/**
\brief ����� ������

���������� ����� ������ � ����������� ������� �� �����
*/
class Lair : public Placeable {

private:
	std::queue<Enemy> Enemyin;
	std::vector<Lairtactic> Tactic;//������� �� �����
	//int timetp;//time to push
	//int wave;
	std::queue<dot> path;

public:
	dot getCor();

	void setCor(dot cor);

private:
	/*!
	\brief ���������� ������ � ��������

	������
	*/
	/// \return ���������� ������ � �������� � ������ ������ �������
	std::vector<Lairtactic> getTactic();
	/*!
	\brief ��������� ������� � ������ ������

	Fname ���� � ������������ ����������(��.����������� �����)
	*/
	/// \param fname ���� � �������� ������������� ���� (��.��������)
	/// \throws runtime_error ���� ���� �� ������ � ������ ����������
	void setTactic(std::string fname);
	/*!
	\brief ��������� ���� ������ 

	��������� ���� ������ ��������������� ������ ������� ������ � �������� (�� ���)
	*/
	void pushenemies();
	/*!
	\brief ���������� ����� ������

	
	*/
	/// \param wavenum ���-�� ������������ ������
	/// \param lvl ������� ������������ ������
	/// \throws exception1 ���� ���� �� ������ � ������ ����������
	void setwave(int wavenum , int lvl);
	/*!
	\brief ���������� ���������� ���� ������

	����� ���������� �������� ������ ���� , � ������� �������� �� ��� �.�. �������� ��������
	*/
	/// \param startX ���������� ������ X
	/// \param startY ���������� ������ Y
	/// \param targetX ���������� ������ X
	/// \param targetY ���������� ������ Y
	/// \return ���������� true , ���� ���� ������ . ���������� false ���� ��� 
	/// \throws exception1 ���� �� ����� ��� ���� , ���������� exception
	bool setpath(int startX, int startY, int targetX, int targetY);
public:
	Lair();

	Lair(Landscape* Land1 , int x, int y);
	/*!
	\brief ��� ������ ������

	����������� ������� � � ����� � �������� �������� ����������� ���������� ������ � ���������� �� ����� �� ����
	*/
	/// \param it ���������� ����� ����
	/// \throws exception1 ���� ����� � ������������� ��� ����� � ������ �� ������� 
	void Turn(int it);//it == ����� ���� ���� 
	/*!
	\brief �������� �� ������� ������

	����������� ������� ������ �����������
	*/
	bool NoMoreEnemies();
};

#endif
