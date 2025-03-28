#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

//3 задание
using namespace std;

struct coord
{
	virtual ~coord() = default;
	virtual double call() const = 0;
};

struct decart : coord
{
	decart(double x, double y) :x_(x), y_(y)
	{
		assert(x_ && y_);
	}

	double x() const { return x_; }
	double y() const { return y_; }
	double call() const
	{
		cout << '(' << x_ << ',' << y_ << ")\n";
		return 0;
	}
	~decart() { }
private:
	double x_;
	double y_;
};

struct polar : coord
{
	polar(double r, double p) :r_(r), p_(p)
	{
		assert(r_ && p_);
	}

	double r() const { return r_; }
	double p() const { return p_; }
	double call() const
	{
		cout << '(' << r_ << ',' << p_ << " degree)\n";
		return 0;
	}
	~polar() { }
private:
	double r_;
	double p_;
};

struct natural : coord
{
	natural(double r, double n, double b) :r_(r), n_(n), b_(b)
	{
		assert(r_ && n_ && b_);
	}

	double r() const { return r_; }
	double n() const { return n_; }
	double b() const { return b_; }
	double call() const
	{
		cout << '(' << r_ << ',' << n_ << ',' << b_ << ")\n";
		return 0;
	}
	~natural() { }
private:
	double r_;
	double n_;
	double b_;
};

int main()
{
	double x=0, y=0;
	double p, r;
	double n, b;
	coord* n1;
	setlocale(LC_ALL, "russian");
	int task;
	cout << "Введите вид координат (1, 2, 3): ";
	cin >> task;
	switch (task)
	{
	case 1:
		cout << "Введите x и y: ";
		cin >> x >> y;
		n1 = new decart(x, y);
		break;
	case 2:
		cout << "Введите r и p: ";
		cin >> r >> p;
		n1 = new polar(r, p);
		break;
	case 3:
		cout << "Введите r, n и b: ";
		cin >> r >> n >> b;
		n1 = new natural (r, n, b);
		break;
	default:
		cout << "Неизвестная операция";
		return 0;
	}
	n1->call();
}
