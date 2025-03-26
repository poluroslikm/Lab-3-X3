#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

//3 задание
using namespace std;

struct coord
{
	virtual ~coord() = default;
	virtual double evaluate() const = 0;
};
struct decart : coord
{
	decart(coord const* x,

		coord const* y) :x_(x), y_(y)
	{
		assert(x_ && y_);
	}

	coord const* x() const { return x_; }
	coord const* y() const { return y_; }
	double evaluate() const
	{
		cout << x << y;
	}
	~decart() {
		delete x_;
		delete y_;
	}
private:
	coord const* x_;
	coord const* y_;
};

int main()
{
}
