#include "stdafx.h"

#include <iostream>
using namespace std;
int main(void)
{
	int to, tm, ye;
	cout << "the day: \n";
	cin >> to;
	if ((to>7)||(to<1)) 
        {       cout « "Некорректный ввод" « endl;
		return 0;
	}
	to = to % 7;
	if (to == 7) {
		to = to + 7;
		cout << "today:\n" << endl;
	}
	tm = to + 1;
	cout << "tomorrow:\n" << tm<< endl;
	ye = to - 1;
	if (ye <= 0) {
		ye = ye + 7;
	}
	cout <<"yesterday:\n"<< ye << endl;
	return 0;

}
