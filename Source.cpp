#include <iostream>
#include "Ring_Header.h"


using namespace std;
const string PATH_OF_FILE = "Player.txt";

int main()
{
	setlocale(LC_ALL, "rus");

	Ring<Player> playerRing;
	Ring<Player> tempRing;
	bool menu = true;
	Player bufer_player;
	do {
		system("cls");
		cout << "1. Добавить игрока" << endl;
		cout << "2. Сохранить изменения" << endl;
		cout << "3. Вывести на экран" << endl;
		cout << "4. Сортировка" << endl;
		cout << "5. Считать информацию из файла" << endl;
		cout << "6. Выполнение задания" << endl;
		cout << "0. Выход" << endl;

		int choise = inputNumber(0, 6);
		switch (choise)
		{
		case 1:
		{
			
			cin >> bufer_player;
			playerRing.add_end(bufer_player);
			break;
		}
		case 2:
		{
			
			playerRing.writeRing(PATH_OF_FILE);
			system("pause");
			break;
		}
		case 3:
		{
			
			playerRing.show_straight();
			system("pause");
			break;
		}
		case 4:
		{
			cout << "Введите способ сортировки:" << endl;
			cout << "1. По ФИО" << endl;
			cout << "2. По номеру игрока" << endl;
			cout << "3. По возрасту" << endl;
			cout << "4. По росту" << endl;
			cout << "5. По весу" << endl;
			int choise = inputNumber(1, 5);
			playerRing.sort_0_2(choise);
			system("pause");
			break;
		}
		case 5: 
			try
			{
				playerRing.clear();
			}
			catch (Ring<Player>::Range)
			{
				cout << "Перед считыванием из файла кольцо было пустым" << endl;
			}
			catch (...)
			{
				cout << "Перед считыванием из файла кольцо НЕ было пустым" << endl;
			}
			try
			{
				playerRing.readRing(PATH_OF_FILE);
			}
			catch (Ring<Player>::NoExist)
			{
				cout << "Файл не существует или пуст! Запишите данные в файл" << endl;
			}
			system("pause");
			break;
		case 6:
			playerRing.sort_0_2(3);
			tempRing.add_end(playerRing[0]);
			playerRing.sort_0_2(-1);
			tempRing.add_end(playerRing[0]);
			tempRing.sort_0_2(1);
			tempRing.show_straight();
			system("pause");
			tempRing.del_begin();
			tempRing.del_begin();
			break;
		case 0:
		{
			menu = false;
			try
			{
				playerRing.clear();
			}
			catch (Ring<Player>::Range)
			{
				cout << "Перед считыванием из файла кольцо было пустым" << endl;
			}
			break;
		}
		}
	} while (menu);



























	Ring<int> doubleRing;
	doubleRing.add_end(4);
	doubleRing.add_end(2);
	doubleRing.add_end(5);
	doubleRing.add_end(3);
	doubleRing.add_end(1);

	doubleRing.show_straight();
	cout << endl;

	doubleRing.show_straight();

	try 
	{
		cout << endl << doubleRing[5] << endl;
	}
	catch(Ring<int>::Range)
	{
		cout << endl <<"Выход за пределы кольца(хотя это же кольцо...)" << endl;
	}
	cout << "Введите значение нового элемента: ";
	bool flag = true;
	while (flag)
	{
		flag = false;
		try
		{
			doubleRing.add_begin(1, 100);
		}
		catch (Ring<int>::Range)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректный ввод. Пожалуйста,введите число от " << 1 << " до " << 10 << endl;
			flag = true;
		}
	}
	cout << doubleRing << endl;

	cout << "Перезапись кольца" << endl;
	cin >> doubleRing;
	cout << doubleRing << endl;
	doubleRing.clear();

	

	try 
	{
		doubleRing.clear();
	}
	catch (Ring<int>::Range)
	{
		cout << "Кольцо уже очищено!" << endl;
	}


	

	cout << endl;

	system("pause");

	return 0;
}