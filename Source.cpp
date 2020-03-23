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
		cout << "1. �������� ������" << endl;
		cout << "2. ��������� ���������" << endl;
		cout << "3. ������� �� �����" << endl;
		cout << "4. ����������" << endl;
		cout << "5. ������� ���������� �� �����" << endl;
		cout << "6. ���������� �������" << endl;
		cout << "0. �����" << endl;

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
			cout << "������� ������ ����������:" << endl;
			cout << "1. �� ���" << endl;
			cout << "2. �� ������ ������" << endl;
			cout << "3. �� ��������" << endl;
			cout << "4. �� �����" << endl;
			cout << "5. �� ����" << endl;
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
				cout << "����� ����������� �� ����� ������ ���� ������" << endl;
			}
			catch (...)
			{
				cout << "����� ����������� �� ����� ������ �� ���� ������" << endl;
			}
			try
			{
				playerRing.readRing(PATH_OF_FILE);
			}
			catch (Ring<Player>::NoExist)
			{
				cout << "���� �� ���������� ��� ����! �������� ������ � ����" << endl;
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
				cout << "����� ����������� �� ����� ������ ���� ������" << endl;
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
		cout << endl <<"����� �� ������� ������(���� ��� �� ������...)" << endl;
	}
	cout << "������� �������� ������ ��������: ";
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
			cout << "������������ ����. ����������,������� ����� �� " << 1 << " �� " << 10 << endl;
			flag = true;
		}
	}
	cout << doubleRing << endl;

	cout << "���������� ������" << endl;
	cin >> doubleRing;
	cout << doubleRing << endl;
	doubleRing.clear();

	

	try 
	{
		doubleRing.clear();
	}
	catch (Ring<int>::Range)
	{
		cout << "������ ��� �������!" << endl;
	}


	

	cout << endl;

	system("pause");

	return 0;
}