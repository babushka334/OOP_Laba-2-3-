#include "Player.h"

double inputNumberDouble(double left_range, double right_range)
{
	double number;
	while ((!(cin >> number)) || (number < left_range || number > right_range))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������������ ����. ����������,������� ����� ��" << left_range << " �� " << right_range << endl;
	}
	return number;
}

int inputNumber(int left_range, int right_range)
{
	int number;
	while ((!(cin >> number)) || (number < left_range || number > right_range))
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������������ ����. ����������,������� ����� ��" << left_range << " �� " << right_range << endl;
	}
	return number;
}

Player::Player()                           //�����������
{
	fio = "������ ���� ��������";
	number = 00;
	age = 18;
	height = 180;
	weight = 75;
}

//--------------------------------------������ ������������-------------------------------------------------------
//--------------------------------------
string Player::get_fio()
{
	return this->fio;
}
void Player::set_fio(string fio)
{
	this->fio = fio;
}
void Player::change_fio()
{
	string fio;
	cout << "������� ��� ������" << endl << "-> ";
	cin >> fio;
	this->set_fio(fio);
}
//--------------------------------------
int Player::get_number()
{
	return this->number;
}
void Player::set_number(int number)
{
	this->number = number;
}
void Player::change_number()
{
	int number;
	cout << "������� ����� ������" << endl << "-> ";
	cin >> number;
	this->set_number(number);
}
//--------------------------------------
int Player::get_age()
{
	return this->age;
}
void Player::set_age(int age)
{
	this->age = age;
}
void Player::change_age()
{
	int age;
	cout << "������� ������� ������" << endl << "-> ";
	cin >> age;
	this->set_age(age);
}
//--------------------------------------
int Player::get_height()
{
	return this->height;
}
void Player::set_height(int height)
{
	this->height = height;
}
void Player::change_height()
{
	int height;
	cout << "������� ���� ������" << endl << "-> ";
	cin >> height;
	this->set_height(height);
}
//--------------------------------------
int Player::get_weight()
	{
		return this->weight;
	}
	void Player::set_weight(int weight)
	{
		this->weight = weight;
	}
	void Player::change_weight()
	{
		int weight;
		cout << "������� ��� ������" << endl << "-> ";
		cin >> weight;
		this->set_weight(weight);
	}


//--------------------------------------������ ����������-------------------------------------------------------
//--------------------------------------
ostream& operator<<(ostream& os, Player& obj)
{
	string fio = obj.get_fio();
	int number = obj.get_number(), age = obj.get_age(),
		height = obj.get_height(), weight = obj.get_weight();

	os << "|" << std::setw(8) << fio << "|"
		<< std::setw(15) << number << "|"
		<< std::setw(15) << age << "|"
		<< std::setw(15) << height << "|"
		<< std::setw(15) << weight << "|";
	return os;
}
//--------------------------------------!!!�������� ����������!!!
istream& operator>>(istream& is, Player& obj)
{
	cout << "������� ��� ������" << endl << "-> ";
	getline(is, obj.fio);
	cout << "������� ����� ������" << endl << "-> ";
	obj.number = inputNumber(is, 0, 99);
	cout << "������� ����� ������" << endl << "-> ";
	obj.age = inputNumber(is, 15, 35);
	cout << "������� ���� ������" << endl << "-> ";
	obj.height = inputNumber(is, 140, 210);
	cout << "������� ��� ������" << endl << "-> ";
	obj.weight = inputNumber(is, 50, 120);
	return is;
}
int inputNumber(istream& is, int left_range, int right_range)
{
	int number;
	while ((!(is >> number)) || (number < left_range || number > right_range))
	{
		is.clear();
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "������������ ����. ����������,������� ����� ��" << left_range << " �� " << right_range << endl;
	}
	return number;
}

ofstream& operator<<(ofstream& ofs, Player& obj)
{
	string fio = obj.get_fio();
	int number = obj.get_number(), age = obj.get_age(),
		height = obj.get_height(), weight = obj.get_weight();
	
	ofs << fio << "|"
		<< number << "|"
		<< age << "|"
		<< height << "|"
		<< weight;
	return ofs;
}
ifstream& operator>>(ifstream& ifs, Player& obj)
{
	string buf;
	
	getline(ifs, buf, '|');
	obj.set_fio(buf);
	
	getline(ifs, buf, '|');
	obj.set_number(atoi(buf.c_str()));

	getline(ifs, buf, '|');
	obj.set_age(atoi(buf.c_str()));

	getline(ifs, buf, '|');
	obj.set_height(atoi(buf.c_str()));

	getline(ifs, buf);
	obj.set_weight(atoi(buf.c_str()));

	return ifs;
}

