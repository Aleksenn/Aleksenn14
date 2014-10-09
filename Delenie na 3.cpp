#include "stdafx.h"
#include <iostream>
using namespace std;



int main(void)
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "¬ведите произвольное число " << endl;
	cin >> n;
	if (n % 3 == 0)
	{
		cout << "„исло делитс€ нацело на 3" << endl;
	}
	else
	{
		cout << "„исло не делитс€ нацело на 3" << endl;
	}
	return 0;
}
