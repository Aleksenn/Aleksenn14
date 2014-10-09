#include "stdafx.h"
#include <iostream>


int main(void)
{
	int a, a1, b = 0, b1 = 1, c, k = 1;
	setlocale(LC_ALL, "Russian");
	std::cout << "Введите любое число: " << std::endl;
	std::cin >> a;
	if (std::cin.fail())
	{
		std::cout << "Неккоректный ввод!" << std::endl;
		return 0;
	}
	a1 = a;
	while (a1 != 0)
	{
		b = b + 1;
		a1 /= 10;
	}
	a1 = a;
	c = b / 2;
 	for (int i = 0; i < c; i++)
	{
		while (a1 > 9 || a1 < -9)
		{
			a1 /= 10;
		}
		if (a1 != (a % 10))
		{
			std::cout << "Число не палиндром!" << std::endl;
      		return 0;
		}
		while (k < b)
		{
			b1 *= 10;
			k++;
		}
		a = a - b1 * a1;
		a /= 10;
		a1 = a;
		b = b - 2;
		b1 = 1;
		k = 1;
	}
	std::cout << "Число палиндром!" << std::endl;
	return 0;
}
