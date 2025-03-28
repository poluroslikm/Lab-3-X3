#include <iostream>
#include<clocale>
#include<string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	char task;
	int t=0;
	int door=0;
	int lamp=0;
	int power = 0;
	int time = 0;
	for (;t==0;)
	{
		cout << "Нажать кнопку (1)\nИзменить положение двери(2)\nОстановить программу (3)\n";
		cin >> task;
		switch (task)
		{
		case '1':
			if (door == 0)
				if (time == 0)
				{
					lamp = 1;
					time = 60;
					power = 1;
				}
				else
					time += 60;
			else
				cout << "<<<Ничего не произошло>>>\n";
			break;
		case '2':
			if (door == 0)
			{
				door = 1;
				time = 0;
				lamp = 0;
				cout << "<<<Дверь открыта>>>\n";
			}
			else
			{
				door = 0;
				cout << "<<<Дверь закрыта>>>\n";
			}
			break;
		case '3':
			t = 1;
			break;
		default:
			cout << "<<<Неизвестная команда>>>\n";
			break;
		}
	}
}
