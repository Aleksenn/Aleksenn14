#include <string>
#include <fstream>
#include <iostream>
#include <conio.h>

using namespace std;

bool formatText(string rPath, string wPath) { // Рабочая функция, в качестве параметров принимает две строки - адрес файла для чтения и для записи
	fstream rFile; // Переменная файла для чтения
	ofstream wFile; // Переменная файла для записи
	string tempString;
	char check;
	int tempLength = 0, limit = 80;

	wFile.open(wPath.c_str()) ; // Открыть файл для записи, в случае, если такого не существеут, он автоматически создастся
	rFile.open(rPath.c_str()); // Открыть файл для чтения
	if (rFile) { // Проверка, что файл открылся
		while (!rFile.eof()) { // До тез пор, пока файл не кончился производим считывания
			rFile >> tempString; // Считываем из файла целое слово в переменную tempString
			tempLength += tempString.length() + 1; // Подсчитываем длину текущей строки, включая пробелы
			if ( (tempLength-1) <= limit ) // Если ее длина меньше limit = 80
						wFile << tempString << ' '; // То записываем в файл текущее слово
					else { 
						tempLength = 0; // Иначе обнуляем длину текущей строки
						wFile << '\n' << tempString<< ' '; // И продолжаем запись с новой строки
					}
			check = rFile.get(); // Считывем символ, следующий за словом
			if ( (int)check == 10 ) // Если это символ перевода строки
				wFile << char(10);  // То переводим строку и в новом файле. Это нужно для сохранения строк, длина которых меньше 80 без изменения.
		}
		wFile.close(); // Закрываем файл чтения
		rFile.close(); // Закрываем файл записи
		return 1;
	}
	else 
		return 0;
}

int main() {
	string rPath, wPath;
	cout << "Enter path of read file: ";
	cin >> rPath; // Считывем адрес файла для чтения
	cout << "Enter path of write file: ";
	cin >> wPath; // Считывем адрес файла для записи
	if ( formatText(rPath, wPath) ) // Если файл найден, то пишем, что все норм
		cout << "Check your file";
	else // Если не найден, то сообщаем ооб этом
		cout << "Can't find file";
	_getch();
}
L
