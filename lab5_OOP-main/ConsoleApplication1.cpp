#include <iostream>
#include <locale>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

class point
{
private:
	// int value;
	int s = 0;
	int data[2] = { x, y };
public:
	int x, y;

	point(int x1, int y1);  // объявляем конструктор
	point();

	// Объявляем функции для чтения полей:
	void SetS(int z);
	void show_coord();
	int distance();
	void new_coord(int a, int b);
	void skalyar(int z);

	int& operator[](int index)
	{
		if (index > 1)
		{
			throw out_of_range("Index out of range");
		}
		return data[index];
	}

	point& operator++(int)
	{
		point temp = *this;
		++x;
		++y;
		return *this;
	}

	point& operator--(int)
	{
		point temp = *this;
		--x;
		--y;
		return *this;
	}

	point operator+(int z )
	{
		return point(x + z, y + z);
	}

	explicit operator bool()
	{
		point pr;
		if (pr.x == this->x && pr.y == this->y)
		{
			return true;
		}
		return false;
	}


};
point::point(int x1, int y1) {
	x = x1;
	y = y1;
}

point::point() {
	x = 0;
	y = 0;
}

void point::show_coord()
{
	cout << "Координаты точки (" << x << "," << y << ")\n";
}

int point::distance()
{
	return (pow(x, 2) + (pow(y, 2)));
}

void point::new_coord(int a, int b)
{
	x = a;
	y = b;
}

void point::skalyar(int z)
{
	y = z * y;
	x = z * x;
}

void point::SetS(int z)
{
	s = z;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	point Test;
	Test++;
	Test.show_coord();

	point test2;
	test2.SetS(2);
	test2 = Test + 2;
	test2.show_coord();

	if (Test)
	{
		cout << "true\n";
	}
	else
	{
		cout << "false\n";
	}

}
