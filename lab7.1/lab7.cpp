#include <iostream>
#include <cassert>
#include <string>
#include <cmath>

using namespace std;

struct Expression
{
	virtual ~Expression() = default;
	virtual double evaluate() const = 0;
};
struct Number : Expression
{
	Number(double value) : value_(value) {}
	double value() const { return value_; }
	double evaluate() const { return value_; }
private:
	double value_;
};
struct BinaryOperation : Expression
{
	enum {
		PLUS = '+',
		MINUS = '-',
		DIV = '/',
		MUL = '*'
	};
	BinaryOperation(Expression const* left, int op,

		Expression const* right) :left_(left), op_(op), right_(right)

	{
		assert(left_ && right_);
	}
	~BinaryOperation()
	{
		delete left_;
		delete right_;
	}
	Expression const* left() const { return left_; }
	Expression const* right() const { return right_; }
	int operation() const { return op_; }

	double evaluate() const
	{
		double left = left_->evaluate();
		double right = right_->evaluate();
		switch (op_)
		{
		case PLUS: return left + right;
		case MINUS: return left - right;
		case DIV: return left / right;
		case MUL: return left * right;
		}
		assert(0);
		return 0.0;
	}
private:
	Expression const* left_;
	Expression const* right_;
	int op_;
};

struct FunctionCall : Expression
{
	//string name;

	FunctionCall(string name1, Expression const* arg) :name_(name1), arg_(arg)
	{
		assert(arg_);
	}

	Expression const* arg() const { return arg_; }
	/**
	* @name – это имя функции, возможные варианты
	* "sqrt" и "abs".
	*
	* Объекты, std::string можно

	* сравнивать с C-строками используя
	* обычный синтаксис ==.
	*
	* @arg – выражение-аргумент функции
	*/
	// реализуйте оставшиеся методы из
	// интерфейса структуры Expression и не забудьте
	// удалить arg_, как это сделано в классе BinaryOperation
	//также реализуйте предложенные ниже методы
	std::string const& name() const
	{
		return name_;
	}
	double evaluate() const
	{
		double arg = arg_->evaluate();
		if (name_=="sqrt")
			return sqrt(arg);
		else
			if (name_ == "abs")
				return abs(arg);
			else
				assert(0);
				return 0.0;
	}
	~FunctionCall() {
		delete arg_;
	}
private:
	Expression const* arg_;
	string name_;
};

int main()
{
	Expression* n32 = new Number(32.0);
	Expression* n16 = new Number(16.0);
	Expression* minus = new BinaryOperation(n32, BinaryOperation::MINUS, n16);
	Expression* callSqrt = new FunctionCall("sqrt", minus);
	Expression* n2 = new Number(2.0);
	Expression* mult = new BinaryOperation(n2, BinaryOperation::MUL, callSqrt);
	Expression* callAbs = new FunctionCall("abs", mult);
	cout << callAbs->evaluate() << endl;
}
