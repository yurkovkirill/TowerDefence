// Application.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "..\TD\Game.h"
#include "..\TD\Graphics.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	/*Game A;
	A.Game::Setup();
	int i = 0;
	while (i++ < 3000){
	A.Game::TurnG();
	}*/
	cout << "Welcome!" << endl;
	Game G;
	Graphics Graph(&G);
	G.InputK('T');


	RenderWindow window(sf::VideoMode(640, 480), "ForsenE");
	window.setVerticalSyncEnabled(true); // call it once, after creating the window
	
	Clock clock;
	Clock gameTimeClock;//переменна€ игрового времени, будем здесь хранить врем€ игры 
	int gameTime = 0;//объ€вили игровое врем€, инициализировали.

	Font font;//шрифт 
	font.loadFromFile("fonts/CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пиксел€х);//сам объект текст (не строка)
	text.setColor(Color::White);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(Text::Bold);//жирный текст.


	int i = 0;
	while (1){
		/*if (i == 456)
			cout << endl;*/
		float time = clock.getElapsedTime().asMilliseconds();//получаем истекшее врем€ clock с момента рестарта в микросекундах
		gameTime = gameTimeClock.getElapsedTime().asSeconds(); //игровое врем€ в секундах идЄт вперед , перезагружать как time его не надо. оно не обновл€ет логику игры

		if (time > 10){//кажда€ итераци€ логики игры
			clock.restart();
			G.TurnG(i);
			i++;
		}

		std::cout << i << std::endl;
		G.DrawAll();
		system("cls");

		if (G.checkStatus())
		{
			window.close();
			break;
		}

		if (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.clear();
			//window.setActive(false);
			(*Graph.MapG).Draw(window);
			(*Graph.GEnemiesG).Draw(window);

			/// text
			std::ostringstream  gameTimeString;    // объ€вили переменную времени
			gameTimeString << gameTime;		//формируем строку
			text.setString("¬рем€ игры: " + gameTimeString.str());//задаем строку тексту и вызываем сформированную выше строку методом .str()
			text.setPosition(8, 342);
			window.draw(text);//рисую этот текст
			/// text

			window.display();
		}
	}
	system("pause");
	
	/*int i = 0;
	G.InputK('T');
	while (i++ < 1000){
		G.TurnG(i);
		if (G.checkStatus())
			break;
	}
	G.DrawAll();*/






	//system("cls");












//	//Loading
//	Landscape A("configMap.txt");
//	//Game
//	char buf1;
//	bool flagBreak1;
//	int x, y, t, rc;
//	string bname;
//	string saveFnameNew;
//	int trc;
//	double healing;
//	while (1)
//	{
//		try
//		{
//			cout << "T - turn, B - build, U - upgrade, R - repair (wall), S - save and exit, E - exit" << endl;
//			cin.ignore(cin.rdbuf()->in_avail());
//			buf = '0';
//			flagBreak = 0;
//			while (!flagBreak)
//			{
//				buf = cin.get();
//				if (!cin.good())
//					throw exception("input_error");
//				switch (buf)
//				{
//				case 'T':
//					trc = A.TurnL();
//					switch (trc)
//					{
//					case 0:
//						cout << "Time: " << game.getTimeG() << endl;
//						break;
//					case -1:
//						cout << "YOU LOSE" << endl;
//						system("pause");
//						return -1;
//						break;
//					case 1:
//						cout << "YOU WIN" << endl;
//						system("pause");
//						return 1;
//						break;
//					}
//					flagBreak = 1;
//					break;
//				case 'B':
//					cout << "Choose, what to build: T - tower, W - wall, Q - quit (from build menu): ";
//					cin.ignore(cin.rdbuf()->in_avail());
//					buf1 = '0';
//					flagBreak1 = 0;
//					while (!flagBreak1)
//					{
//						buf1 = cin.get();
//						if (!cin.good())
//							throw exception("input_error");
//						switch (buf1)
//						{
//						case 'W':
//							t = 11;
//							flagBreak1 = 1;
//							break;
//						case 'T':
//							t = 12;
//							flagBreak1 = 1;
//							break;
//						case 'Q':
//							flagBreak1 = 1;
//							flagBreak = 1;
//							break;
//						}
//					}
//					if (flagBreak) //used for Quit
//						continue;
//					cout << "Enter position (x y). Enter negative to quit: ";
//					cin >> x >> y;
//					if (!cin.good())
//						throw exception("input_error");
//					if ((x < 0) || (y < 0))
//					{
//						flagBreak = 1;
//						break;
//					}
//					cout << "Enter building name: ";
//					cin >> bname;
//					if (!cin.good())
//						throw exception("input_error");
//					rc = game.build(Pos(x, y), t, bname);
//					switch (rc)
//					{
//					case 0:
//						cout << "Not existing position!" << endl;
//						break;
//					case -1:
//						cout << "Wrong place (bad terrain/another building)!" << endl;
//						break;
//					case -2:
//						cout << "Not enough gold!" << endl;
//						break;
//					case -3:
//						cout << "Blocking path for light infantry!" << endl;
//						break;
//					case -4:
//						cout << "Enemies at position!" << endl;
//						break;
//					case 1:
//						cout << "Done!" << endl;
//						break;
//					default:
//						throw exception("unexpected_error");
//						break;
//					}
//					flagBreak = 1;
//					break;
//				case 'U':
//					cout << "Enter position (x y). Enter negative to quit: ";
//					int x, y, rc;
//					cin >> x >> y;
//					if (!cin.good())
//						throw exception("input_error");
//					if ((x < 0) || (y < 0))
//					{
//						flagBreak = 1;
//						break;
//					}
//					rc = game.upgrade(Pos(x, y));
//					switch (rc)
//					{
//					case 0:
//						cout << "Not existing position!" << endl;
//						break;
//					case -1:
//						cout << "Wrong place (empty/enemy building) or not upgradable building (wall)!" << endl;
//						break;
//					case -2:
//						cout << "Not enough gold!" << endl;
//						break;
//					case -3:
//						cout << "Maximum level is already reached!" << endl;
//						break;
//					case 1:
//						cout << "Done!" << endl;
//						break;
//					default:
//						throw exception("unexpected_error");
//						break;
//					}
//					flagBreak = 1;
//					break;
//				case 'R':
//					cout << "Enter position (x y). Enter negative to quit: ";
//					cin >> x >> y;
//					if (!cin.good())
//						throw exception("input_error");
//					if ((x < 0) || (y < 0))
//						continue;
//					cout << "Enter healing value: ";
//					cin >> healing;
//					if (!cin.good())
//						throw exception("input_error");
//					rc = game.repair(Pos(x, y), healing);
//					switch (rc)
//					{
//					case 0:
//						cout << "Not existing position!" << endl;
//						break;
//					case -1:
//						cout << "There is no any walls!" << endl;
//						break;
//					case -2:
//						cout << "Not enough gold!" << endl;
//						break;
//					case -3:
//						cout << "Negative healing value!" << endl;
//						break;
//					case 1:
//						cout << "Done!" << endl;
//						break;
//					default:
//						throw exception("unexpected_error");
//						break;
//					}
//					flagBreak = 1;
//					break;
//				case 'S':
//					cout << "Enter save file name: ";
//					cin >> saveFnameNew;
//					if (!cin.good())
//						throw exception("input_error");
//					game.save(string(SAVE_FOLDER) + string("/") + saveFnameNew);
//					cout << "Game was stopped by player." << endl;
//					system("pause");
//					return 0;
//				case 'E':
//					cout << "Game was stopped by player." << endl;
//					system("pause");
//					return 0;
//				}
//			}
//		}
//		catch (exception &ex)
//		{
//			game.save(string(SAVE_FOLDER) + string("/") + string(CRASH_SAVE_FILE));
//			cout << "Game was stopped. ERROR: " << ex.what() << endl;
//			cout << "Current game state was saved to this file: " << CRASH_SAVE_FILE << endl;
//			system("pause");
//			return 0;
//		}
//
//	}
//}



	return 0;
}

