#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

using namespace std;

class SqrtExc : public exception // Класс ошибки
{
public:
	SqrtExc(string m_) : m{ m_ } {}

	string getMessage() const
	{
		return m;
	}
	string m;
};

double sqrt2(double x)
{
	if (x > 0)
		return sqrt(x);
	else
		throw SqrtExc("Попытка извлечения корня из отрицательного числа " + to_string(x));
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Введите подкоренное выражение: ";
	try
	{
		double x = 0;
		cin >> x;
		cout << sqrt2(x);
	}
	catch (const SqrtExc& e)
	{
		cout << e.getMessage();
	}

}
