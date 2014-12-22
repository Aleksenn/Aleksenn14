#include <string>
#include <ifstream>
#include <iostream>

using namespace

string readFile(string path) {
	ifstream input(path);
	input.seekg(0, std::ios::end); //перешли в конец
	int len = input.tellg(); //получаем длину файла
	input.seekg(0, std::ios::beg); //перешли в начало
	char * buf = new char [len];
	input.read(buf, len);
	return string(buf);
}

string operateStr(string base) {
	int i = 0, space = -1, len = base.length();
	if(len < 80) return;
	while(i < base.length()) {
		if(base[i] == ' ') space = i;
		if(i == 80 && space != -1) {
			base[space] = '\n';
			i = space + 1;
			space = -1;
		}
	}
	return base;
}
