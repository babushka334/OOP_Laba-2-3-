#pragma once
#include "FileC.h"

using namespace std;

template <class T>
struct Struct
{
	T value;//информационная часть
	Struct* next;//указатель на следующий элемент
	Struct* prev;//указатель на предыдущий элемент
};

template <class T>
class Ring
{
protected:
	Struct<T>* first;//указатель на первый элемент
	Struct<T>* last;//указатель на последний элемент
	double size;//размер кольца
public:
	Struct<T>* getElement(double pos);//получения указателя на элемент с индексом pos
	class Range{};
	class Mem{};
	class NoExist{};
	Ring();//конструктор по умолчанию
	~Ring();//деструктор
	void show_straight();//вывод кольца на экран с начала
	void show_reverse();//вывод кольца на экран с конца
	void add_begin(T Value);//добавление элемента в начало кольца
	void add_end(T Value);//добавление элемента в конец кольца
	void del_begin();//удаление первого элемента кольца
	void del_end();//удаление последнего элемента кольца
	void del(double pos);//удаление элемента с индексом pos
	double getSize();//получение размера кольца
	void clear();//очистка кольца
	T& operator[](double pos);//перегрузка оператора индексирования
	T& getElem(double pos);//получения информационной части элемента с индексом pos
	double getPos(string log);
	Ring& operator=(const Ring<T>& object);//перегрузка оператора присваивания
	void sort_0_2(int choise);
	void add_begin(T left_range, T right_range);
	Struct<T>* getFirst();
	void writeRing(const string path);
	void readRing(const string path);
};

template <class T>
Ring<T>& Ring<T>::operator=(const Ring& object)
{
	if (first) clear();
	for (double i = 0; i < object.getSize(); i++)
	{
		add_end(object[i]);
	}
	return *this;
}

template <class T>
Struct<T>* Ring<T>::getElement(double pos)
{
	Struct<T>* temp;
	temp = first;
	if (pos >= size)
		throw Range();
	for (double i = 0; i < pos; i++)
		temp = temp->next;
	return temp;
}

template <class T>
Ring<T>::Ring()
{
	first = NULL;
	last = NULL;
	size = 0;
}
template<class T>
Ring<T>::~Ring()
{
	Struct<T>* temp;
	while (first != last)
	{
		temp = first;
		first = first->prev;
		delete temp;
	}
	delete last;
}

template<class T>
void Ring<T>::show_straight()
{
	double number = 0;
	T tmpishe;
	Struct<T>* temp = first;
	for (double i = 0; i < getSize(); i++)
	{
		cout << "\t" << temp->value << endl;
		temp = temp->next;
		number++;
	}
}

template<class T>
void Ring<T>::show_reverse()
{
	double number = 0;
	T tmpishe;
	Struct<T>* temp = last;
	for (double i = 0; i < getSize(); i++)
	{
		cout << "\t" << temp->value;
		temp = temp->prev;
		number++;
	}
}

template<class T>
void Ring<T>::add_begin(T Value)
{
	Struct<T>* temp = new Struct<T>;
	temp->value = Value;
	if (first)
	{
		temp->next = first;
		first->prev = last->next = temp;
		temp->prev = last;
		first = temp;
	}
	else
	{
		first = last = temp;
		first->next = first->prev = last;
		last->next = last->prev = first;
	}
	++size;
}
template<class T>
void Ring<T>::add_begin(T left_range, T right_range)
{
	Struct<T>* temp = new Struct<T>;
	T number;
	if ((!(cin >> number)) || number > right_range || number < left_range)
		throw Range();
	temp->value = number;
	if (first)
	{
		temp->next = first;
		first->prev = last->next = temp;
		temp->prev = last;
		first = temp;
	}
	else
	{
		first = last = temp;
		first->next = first->prev = last;
		last->next = last->prev = first;
	}
	++size;
}

template<class T>
void Ring<T>::add_end(T Value)
{
	Struct<T>* temp = new Struct<T>;
	temp->value = Value;
	if (last)
	{
		temp->prev = last;
		last->next = first->prev = temp;
		temp->next = first;
		last = temp;
	}
	else
	{
		first = last = temp;
		first->next = first->prev = last;
		last->next = last->prev = first;
	}
	++size;
}

template<class T>
void Ring<T>::del_begin()
{
	del(0);
}

template<class T>
void Ring<T>::del_end()
{
	del(size - 1);
}

template<class T>
void Ring<T>::del(double pos)
{
	if (!first) return;

	Struct<T>* temp;
	temp = getElement(pos);

	if (temp->next == temp) first = last = NULL;
	else
	{
		if (temp == last) last = last->prev;
		if (temp == first) first = first->next;
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		delete temp;
	}
	size--;
}

template<class T>
double Ring<T>::getSize()
{
	return size;
}

template<class T>
Struct<T>* Ring<T>::getFirst()
{
	return first;
}

template<class T>
void Ring<T>::clear()
{
	if (last == NULL && first == NULL)
		throw Range();
	while (first->prev != last)
	{
		Struct<T>* temp = first->prev;
		first = first->prev;
		delete temp;
	}
	last = NULL;
	first = NULL;
	cout << "Кольцо очищено" << endl;
}

template<class T>
T& Ring<T>::operator[](double pos)
{
	if (!first)
	{
		T empty;
		return empty;
	}
	return (getElement(pos))->value;
}

template <class T>
T& Ring<T>::getElem(double pos)
{
	Struct<T>* temp;
	temp = first;
	for (double i = 0; i < pos; i++)
		temp = temp->next;
	return temp->value;
}

template <class T>
double Ring<T>::getPos(string log)
{

	if (first == NULL)
		return -1;
	Struct<T>* temp;
	temp = first;
	double k = 0;
	if (temp->value.GetLogin() == log)
		return k;
	k++;
	temp = temp->next;
	while (temp != last->next)
	{

		if (temp->value.GetLogin() == log)
			return k;
		k++;
		temp = temp->next;
	}
}

template <class T>
void Ring<T>::sort_0_2(int choise)
{
	Struct<T>* temp;
	bool flag = true;
	T tempp;
	switch (choise)
	{
	case 1:
		while (flag)
		{
			flag = false;
			Struct<T>* temp;

			temp = first;
			temp->next = first->next;
			temp->prev = first->prev;
			while (temp != last)
			{
				if ((temp->value).get_fio() > (temp->next->value).get_fio())
				{
					swap(temp->value, temp->next->value);
					flag = true;
				}
				temp = temp->next;
			}
		}
		break;
	case 2:
		while (flag)
		{
			flag = false;
			Struct<T>* temp;

			temp = first;
			temp->next = first->next;
			temp->prev = first->prev;
			while (temp != last)
			{
				if ((temp->value).get_number() > (temp->next->value).get_number())
				{
					swap(temp->value, temp->next->value);
					flag = true;
				}
				temp = temp->next;
			}
		}
		break;
	case 3:
		while (flag)
		{
			flag = false;
			Struct<T>* temp;

			temp = first;
			temp->next = first->next;
			temp->prev = first->prev;
			while (temp != last)
			{
				if ((temp->value).get_age() > (temp->next->value).get_age())
				{
					swap(temp->value, temp->next->value);
					flag = true;
				}
				temp = temp->next;
			}
		}
		break;
	case 4:
		while (flag)
		{
			flag = false;
			Struct<T>* temp;

			temp = first;
			temp->next = first->next;
			temp->prev = first->prev;
			while (temp != last)
			{
				if ((temp->value).get_height() > (temp->next->value).get_height())
				{
					swap(temp->value, temp->next->value);
					flag = true;
				}
				temp = temp->next;
			}
		}
		break;
	case 5:
		while (flag)
		{
			flag = false;
			Struct<T>* temp;

			temp = first;
			temp->next = first->next;
			temp->prev = first->prev;
			while (temp != last)
			{
				if ((temp->value).get_weight() > (temp->next->value).get_weight())
				{
					swap(temp->value, temp->next->value);
					flag = true;
				}
				temp = temp->next;
			}
		}
		break;
	case -1:
		while (flag)
		{
			flag = false;
			Struct<T>* temp;

			temp = first;
			temp->next = first->next;
			temp->prev = first->prev;
			while (temp != last)
			{
				if ((temp->value).get_height() < (temp->next->value).get_height())
				{
					swap(temp->value, temp->next->value);
					flag = true;
				}
				temp = temp->next;
			}
		}
		break;
	}
}

template <class T>
ostream& operator<<(ostream& os, Ring<T>& obj)
{
	T tmpishe;
	Struct<T>* temp = obj.getFirst();
	for (int i = 0; i < obj.getSize(); i++)
	{
		if (i % 4 == 0) {
			os << setw(5) << right << showpos << temp->value;
			os.unsetf(ios::showpos);
		}
		else
			if (i % 4 == 1) {
				os << setw(5) << left << hex << temp->value;
				os.unsetf(ios::hex);
			}
			else
				if (i % 4 == 2) {
					os << setw(5) << right << scientific << temp->value;
					os.unsetf(ios::scientific);
				}
				else {
					os << setw(5) << left << oct<< showbase << temp->value;
					os.unsetf(ios::oct);
				}
		temp = temp->next;
		cout << "|";
	}
	return os;
}

template <class T>
istream& operator>>(istream& is, Ring<T>& obj)
{
	T tmpishe;
	Struct<T>* temp = obj.getFirst();
	for (double i = 0; i < obj.getSize(); i++)
	{
		cout << "Вводите значение: ";
		is >> temp->value;
		temp = temp->next;
	}
	return is;
}

template <class T>
void Ring<T>::writeRing(const string path)
{
	Struct<T>* temp;
	temp = first;
	FileC f(path);
	f.delData();
	bool flag = true;
	if (first == last) 
	{
		f.write(temp->value, false);
	}
	else
	{
		while (temp != last)
		{
			f.write(temp->value, flag);
			temp = temp->next;
		}
		flag = false;
		f.write(temp->value, flag);

		cout << "Данные успешно записаны в файл" << endl;
	}
}

template <class T>
void Ring<T>::readRing(const string path)
{
	Player ob;
	ifstream f(path);
	if (!(f.is_open()))
		throw NoExist();
	int n = 0;
	while (!f.eof())
	{
		n++;
		f >> ob;
		this->add_end(ob);
	}
	if (!n)
		throw NoExist();
	cout << "Файл успешно прочитан" << endl;
}



