#include <iostream>
#include <conio.h>
#include <cmath>
#include <cstdlib>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;

class Triangle
{
public:

	int x1, x2, x3, y1, y2, y3;
	double a, b, c, alpha, beta, gama, xM, yM, area;

	Triangle(int tx1, int ty1, int tx2, int ty2, int tx3, int ty3) 
	{
		x1 = tx1;
		y1 = ty1;
		x2 = tx2;
		y2 = ty2;
		x3 = tx3;
		y3 = ty3;

		c = sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		b = sqrt((double)(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
		a = sqrt((double)(x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));

		alpha = ( (x3-x1)*(x2-x1) + (y3-y1)*(y2-y1) )/b/c;
		beta = ( (x1-x2)*(x3-x2) + (y1-y2)*(y3-y2) )/a/c;
		gama = ( (x1-x3)*(x2-x3) + (y1-y3)*(y2-y3) )/b/a;

		xM = (double)(x1 + x2 + x3) / 3;
		yM = (double)(y1 + y2 + y3) / 3;

		area = abs((double)((x1-x3)*(y2-y3) - (x2-x3)*(y1-y3))/2);
	}

	void showPoints()
	{
		cout << "x1 = " << x1 << endl;
		cout << "y1 = " << y1 << endl;
		cout << "x2 = " << x2 << endl;
		cout << "y2 = " << y2 << endl;
		cout << "x3 = " << x3 << endl;
		cout << "y3 = " << y3 << endl;
	}

	void showSides()
	{
		cout << "a = " << a << setprecision(3) << endl;
		cout << "b = " << b << setprecision(3) << endl;
		cout << "c = " << c << setprecision(3) << endl;
	}

	void showAngles()
	{
		cout << "cos a = " << alpha << setprecision(6) << endl;
		cout << "cos b = " << beta << setprecision(6) << endl;
		cout << "cos c = " << gama << setprecision(6) << endl;
	}

	void showMass()
	{
		cout << "cos xM = " << xM << setprecision(6) << endl;
		cout << "cos yM = " << yM << setprecision(6) << endl;
	}

	void showArea()
	{
		cout << "Ïëîùàäü = " << area << setprecision(6) << endl;
	}
};

int main()
{

	char choice;
	int x1, x2, x3, y1, y2, y3;
	double a, b, c;
	setlocale(LC_ALL, "Russian");

	cout << "x1 = ";
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
	a = sqrt((double)(x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
	b = sqrt((double)(x1-x3)*(x1-x3) + (y1-y3)*(y1-y3));
	c = sqrt((double)(x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
	if ( (a + b > c) && (a + c > b) && (b + c > a) ) {
		cout << "Òðåóãîëüíèê ñîçäàí";
		_getch();
	}
	else {
		cout << "Òàêîãî íå áûâàåò";
		_getch();
		exit(0);
	}
	Triangle object(x1, y1, x2, y2, x3, y3);

	do
	{
		system("cls");
		cout << "1 - Âûâåñòè âåðøèíû òðåóãîëüíèêà" << endl;
		cout << "2 - Âûâåñòè ñòîðîíû òðåóãîëüíèêà" << endl;
		cout << "3 - Âûâåñòè óãëû òðåóãîëüíèêà" << endl;
		cout << "4 - Âûâåñòè öåíòð ìàññ òðåóãîëüíèêà" << endl;
		cout << "5 - Âûâåñòè ïëîùàäü òðåóãîëüíèêà" << endl;
		cout << "0 - Âûéòè" << endl;
		cout << endl;

		choice = getch();

		switch(choice)
		{
			case '1':
				object.showPoints();
				_getch();
				break;
			case '2':
				object.showSides();
				_getch();
				break;
			case '3':
				object.showAngles();
				_getch();
				break;
			case '4':
				object.showMass();
				_getch();
				break;
			case '5':
				object.showArea();
				_getch();
				break;

		}
	}while(choice != '0');

	return 0;
}
