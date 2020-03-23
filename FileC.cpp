#include "FileC.h"

FileC::FileC(const string path)
{
	this->path = path;
}

void FileC::write(Player obj, bool flag)
{
	ofstream outf(this->path, ios::out | ios::app);
	outf << obj;
	if (flag)
	{
		outf << endl;
	}
}
void FileC::delData()
{
	ofstream fout;
	fout.open(this->path);
	fout.close();
}

void FileC::read(ifstream& in, Player& obj)
{
	in >> obj;
}