// Application.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "..\TD\Game.h"
#include "..\TD\Graphics.h"
#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
using namespace std;
dot ConverttoMap(int* x, int* y){
	dot cor;
	cor.x = floor(*x / 32);
	cor.y = floor(*y / 32);
	return cor;
}
int ClickMap(RenderWindow &window, Game * G, sf::Event * event0){

	Vector2i pos = Mouse::getPosition(window);//забираем коорд курсора
	dot cor;
	std::cout << pos.x << "\n";//смотрим на координату Х позиции курсора в консоли (она не будет больше ширины окна)
	if ((*event0).type == Event::MouseButtonPressed)//если нажата клавиша мыши
		if ((*event0).key.code == Mouse::Left)//а именно левая
		{
			cor = ConverttoMap(&pos.x, &pos.y);
			(*G).InputK('T', cor.x, cor.y);
		}
	return 1;
}



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
	Landscape* GlobalLand = G.getLand();
	Graphics Graph(&G);
	G.InputK('T',9,4);
	Font font;//шрифт 
	font.loadFromFile("fonts/CyrilicOld.ttf");//передаем нашему шрифту файл шрифта
	Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	text.setColor(Color::White);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(Text::Bold);//жирный текст.



	///////////// in building
	Image yes_image;//объект изображения для карты
	Texture yes_texture;//текстура карты
	Sprite yes_sprite;//создаём спрайт для карты
	yes_image.loadFromFile("images/Yes_19x89.png");//загружаем файл для карты
	yes_texture.loadFromImage(yes_image);//заряжаем текстуру картинкой
	yes_sprite.setTexture(yes_texture);//заливаем спрайт
	RenderWindow menuwindow(sf::VideoMode(200, 200), "Tower Defence Menu");
	while (1){
		if (menuwindow.isOpen())
		{
			sf::Event event;
			bool Break = false;
			Vector2i pixelPos = Mouse::getPosition(menuwindow);//забираем коорд курсора
			Vector2f pos = menuwindow.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
			while (menuwindow.pollEvent(event))
			{
				if (event.type == sf::Event::Closed){
					menuwindow.close();
				}
				if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
					if (event.key.code == Mouse::Left)//а именно левая
						if (yes_sprite.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
						{
							Break = true;
						}
			}
			if (Break){
				menuwindow.close();
				break;
			}
			if (event.type == sf::Event::Closed){
				break;
			}
			menuwindow.clear();
			text.setString("Запустить игру?");//задаем строку тексту и вызываем сформированную выше строку методом .str()
			text.setPosition(0, 0);
			menuwindow.draw(text);//рисую этот текст
			yes_sprite.setPosition(0, 32);
			menuwindow.draw(yes_sprite);
			menuwindow.display();
		}
	}


	/////////////

	RenderWindow window(sf::VideoMode(640, 480), "ForsenE");
	window.setVerticalSyncEnabled(true); // call it once, after creating the window
	
	Clock clock;
	Clock gameTimeClock;//переменная игрового времени, будем здесь хранить время игры 
	int gameTime = 0;//объявили игровое время, инициализировали.


	

	int i = 0;
	/////////////////GAME START
	while (1){
		/*if (i == 456)
			cout << endl;*/
		int time = clock.getElapsedTime().asMilliseconds();//получаем истекшее время clock с момента рестарта в микросекундах
		gameTime = gameTimeClock.getElapsedTime().asSeconds(); //игровое время в секундах идёт вперед , перезагружать как time его не надо. оно не обновляет логику игры

		if (time < 10)
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(static_cast<int>(std::round(10 - time))));
		}

		//if (time > 10){//каждая итерация логики игры
		clock.restart();
		G.TurnG(i);
		i++;
		//}

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
			if (event.type == sf::Event::Closed){//CT закрывается если закрыли окно
				break;
			}
			window.clear();

			//for (i = 0; i < (*Graph.Land).height; i++)
			//	for (int j = 0; j < (*Graph.Land).width; j++){
			//		(*Graph.Land)
			//	}
			//
			//
			///// clickofmouse
			//Vector2i pixelPos = Mouse::getPosition(window);//забираем коорд курсора
			//Vector2f pos = window.mapPixelToCoords(pixelPos);//переводим их в игровые (уходим от коорд окна)
			//if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			//	if (event.key.code == Mouse::Left)//а именно левая
			//		if (p.sprite.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
			//		{
			//			std::cout << "isClicked!\n";//выводим в консоль сообщение об этом
			//			dX = pos.x - p.sprite.getPosition().x;//делаем разность между позицией курсора и спрайта.для корректировки нажатия
			//			dY = pos.y - p.sprite.getPosition().y;//тоже самое по игреку
			//			isMove = true;//можем двигать спрайт							
			//		}
			//if (event.type == Event::MouseButtonReleased)//если отпустили клавишу
			//	if (event.key.code == Mouse::Left) //а именно левую
			//		isMove = false; //то не можем двигать спрайт
			//p.sprite.setColor(Color::White);//и даем ему прежний цвет
			//}
			//if (isMove) {//если можем двигать
			//p.sprite.setColor(Color::Green);//красим спрайт в зеленый 
			//p.x = pos.x - dX;//двигаем спрайт по Х
			//p.y = pos.y - dY;//двигаем по Y
			////p.sprite.setPosition(pos.x - dX, pos.y - dY);//можно и так написать,если у вас нету х и у
			//}
			///// clickofmouse


			ClickMap(window,&G,&event);
			//window.setActive(false);

			/// graphics
			(*Graph.MapG).Draw(window);
			(*Graph.GEnemiesG).Draw(window);
			/// graphics

			/// text
			std::ostringstream  gameTimeString;    // объявили переменную времени
			gameTimeString << gameTime;		//формируем строку
			text.setString("Время игры: " + gameTimeString.str() + " Золото: " + std::to_string((*GlobalLand).getGold()));//задаем строку тексту и вызываем сформированную выше строку методом .str()
			text.setPosition(8, 342);
			window.draw(text);//рисую этот текст
			/// text

			window.display();
		}
	}
	system("pause");
	return 0;
}



























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