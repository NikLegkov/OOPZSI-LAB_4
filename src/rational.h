#include <iostream>

class Rational
{
	private:
		int nominator, denominator;
	void Cancellation();
	public:
		Rational(int, int);
		Rational(int);
		Rational();

		int GetNominator() const;
		int GetDenominator() const;

		friend std::ostream& operator<<(std::ostream &out, const Rational &ex);
		friend std::istream& operator>>(std::istream &in, Rational &ex);
		Rational operator+(Rational &expr);
		Rational operator-(Rational &expr);
		Rational operator*(Rational &expr);
		Rational operator/(Rational &expr);
};
