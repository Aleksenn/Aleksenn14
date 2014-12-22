#include "stdafx.h"

#include <iostream>
using namespace std;
int main(void)
{
	int to;
	cout << "the day: \n";
	cin >> to;
	if ((to>7)||(to<1)) 
        {       cout << "incorrectly input" << endl;
		return 0;
	}
           cout << "tomorrow: " << ((to == 7) ? "1" : to + 1) << endl;
           cout << "yesterday: " << ((to == 1) ? "7" : to - 1) << endl;
           return 0;
}        
