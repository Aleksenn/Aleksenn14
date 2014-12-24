#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;

bool formatText(string rPath, string wPath) {
	fstream rFile, rFileTemp;
	ofstream wFile;
	string tempString, tempString1;
	char check;
	int tempLength = 0, limit = 80, tempStringLen = 0;

	wFile.open (wPath);
	rFile.open(rPath);
	if (rFile) {
		while (!rFile.eof()) {
			rFile >> tempString;
			tempLength += tempString.length() + 1;
			cout << tempLength << ' ';
			if ( (tempLength-1) <= limit )
						wFile << tempString << ' ';
					else { 
						tempLength = 0;
						wFile << '\n' << tempString<< ' ';
					}
			check = rFile.get();
			if ( (int)check == 10 )
				wFile << char(10); 
		}
		wFile.close();
		rFile.close();
		return 1;
	}
	else 
		return 0;
}

int main() {
	string rPath, wPath;
	cout << "Enter path of read file: ";
	cin >> rPath;
	cout << "Enter path of write file: ";
	cin >> wPath;
	if ( formatText(rPath, wPath) )
		cout << "Check your file";
	else
		cout << "Can't find file";
	_getch();
}
