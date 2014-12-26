#include <iostream>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class Triangle //Класс треугольник
{
public:

	int x1, x2, x3, y1, y2, y3; // переменные координат вершин
	double a, b, c, alpha, beta, gama, xM, yM, area; // длины сторон, углы, координаты центра масс, площадь

	Triangle(int tx1, int ty1, int tx2, int ty2, int tx3, int ty3) // Конструктор класса, в нем по координатам высчитываются все нужные величины
	{
		x1 = tx1;
		y1 = ty1;
		x2 = tx2;
		y2 = ty2;
		x3 = tx3;
		y3 = ty3;

		c = sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); // Вычисление сторон
		b = sqrt((double)(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
		a = sqrt((double)(x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));

		alpha = ( (x3-x1)*(x2-x1) + (y3-y1)*(y2-y1) )/b/c; // Вычисление углов
		beta = ( (x1-x2)*(x3-x2) + (y1-y2)*(y3-y2) )/a/c;
		gama = ( (x1-x3)*(x2-x3) + (y1-y3)*(y2-y3) )/b/a;

		xM = (double)(x1 + x2 + x3) / 3; // Вычисление координат центра масс
		yM = (double)(y1 + y2 + y3) / 3;

		area = abs((double)((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3))/2); // Вычисление площади
	}

	void showPoints() // Метод класса - вывод вершин
	{
		cout << "x1 = " << x1 << endl;
		cout << "y1 = " << y1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "y2 = " << y2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "y3 = " << y3 << endl;
	}

	void showSides() // Метод класса - вывод длин сторон
	{
		cout << "a = " << a << setprecision(3) << endl;
		cout << "b = " << b << setprecision(3) << endl;
		cout << "c = " << c << setprecision(3) << endl;
	}

	void showAngles() // Метод класса - вывод углов
	{
		cout << "cos a = " << alpha << setprecision(6) << endl;
		cout << "cos b = " << beta << setprecision(6) << endl;
		cout << "cos c = " << gama << setprecision(6) << endl;
	}

	void showMass()  // Метод класса - вывод координат центра масс
	{
		cout << "cos xM = " << xM << setprecision(6) << endl;
		cout << "cos yM = " << yM << setprecision(6) << endl;
	}

	void showArea() // Метод класса - вывод площади
	{
		cout << "Площадь = " << area << setprecision(6) << endl;
	}
};

int main()
{

	char choice;
	int x1, x2, x3, y1, y2, y3;
	double a, b, c;
	setlocale(LC_ALL, "Russian"); // Локализация для использования руссого языа

	cout << "x1 = "; // Задание координат вершин
	cin >> x1;
	cout << "y1 = "; 
	cin >> y1;
	cout << "x2 = ";
	cin >> x2;
	cout << "y2 = ";
	cin >> y2;
	cout << "x3 = ";
	cin >> x3;
	cout << "y3 = ";
	cin >> y3;
	a = sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)); // Вычисление длин сторон для проверки существования треугольника
	b = sqrt((double)(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
	c = sqrt((double)(x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	if ( (a + b > c) && (a + c > b) && (b + c > a) ) { // Прроверка существования треугольника
		cout << "Треугольник создан";
		_getch();
	}
	else {
		cout << "Такого не бывает";
		_getch();
		exit(0);
	}
	Triangle object(x1, y1, x2, y2, x3, y3);

	do
	{
		system("cls"); // Чистка экрана
		cout << "1 - Вывести вершины треугольника" << endl;
		cout << "2 - Вывести стороны треугольника" << endl;
		cout << "3 - Вывести углы треугольника" << endl;
		cout << "4 - Вывести центр масс треугольника" << endl;
		cout << "5 - Вывести площадь треугольника" << endl;
		cout << "0 - Выйти" << endl;
		cout << endl;

		choice = getch(); // Считывания символа в переменную choice без вывода на экран

		switch(choice) // Организация меню - дальнейшее действие зависит от значения choice
		{
			case '1':
				object.showPoints(); // Вызов метода класса для вывода координат вершин
				_getch();
				break;
			case '2':
				object.showSides(); // Вызов метода класса для вывода длин сторон
				_getch();
				break;
			case '3':
				object.showAngles(); // Вызов метода класса для вывода углов
				_getch();
				break;
			case '4':
				object.showMass(); // Вызов метода класса для вывода координат центра масс
				_getch();
				break;
			case '5':
				object.showArea(); // Вызов метода класса для вывода площади
				_getch();
				break;

		}
	}while(choice != '0'); // В случае нуля - выход

	return 0;
}
