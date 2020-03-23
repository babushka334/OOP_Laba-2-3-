#pragma once
#include "Player.h"
//using namespace std;

class FileC
{
	string path;
public:
	FileC(const string path);
	~FileC() {};
	void read(ifstream& in, Player& obj);
	void write(Player, bool);
	void delData();
};
