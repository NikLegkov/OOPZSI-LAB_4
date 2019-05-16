#include <iostream>
#include <math.h>
#include "rational.h"

using namespace std;

Rational::Rational(int _nominator, int _denominator) : nominator(_nominator), denominator(_denominator) { Cancellation(); }
Rational::Rational(int _nominator) : nominator(_nominator), denominator(0) { Cancellation(); }
Rational::Rational() : nominator(0), denominator(1) { Cancellation(); }

int Rational::GetNominator() const
{
	return nominator;
}

int Rational::GetDenominator() const
{
	return denominator;
}

void Rational::Cancellation()
{

	if (nominator != 0)
	{
		int m = denominator,
			n = nominator,
			ost = m % n;
		while (ost != 0)	//ищем нод
		{
			m = n; n = ost;
			ost = m % n;
		}
		int nod = n;
		if (nod != 1)
		{
			nominator /= nod; denominator /= nod; //сокращаем дробь
		}
	}
}

ostream& operator<<(ostream &out, const Rational &ex)
{
	out << ex.nominator << "/" << ex.denominator;
	return out;
}

istream& operator>>(istream &in, Rational &ex)
{
	in >> ex.denominator >> ex.denominator;
	return in;
}

Rational Rational::operator+(Rational &ex)
{
	Rational res;
	res.nominator = nominator * ex.denominator + ex.nominator * denominator;
	res.denominator = denominator * ex.denominator;
	/*if (res.nominator < 0)
	{
		res.nominator *= -1; res.sign = -1;//выносим знак в знаковую переменную
	}*/
	//res.GetMixedView(); //приводим к смешанному виду
	res.Cancellation();
	return res;
}

Rational Rational::operator*(Rational &a) //перегрузка операции умножения для двух дробей
{
	Rational res;
	res.nominator = nominator * a.nominator;
	res.denominator = denominator * a.denominator;

	res.Cancellation();
	return res;
}



/*
Rational Rational::operator+(Rational &ex)
{
	return Rational(re + ex.Re(), im + ex.Im());
}

Rational Rational::operator-(Rational &ex)
{
	return Rational(re - ex.Re(), im - ex.Im());
}

Rational Rational::operator*(Rational &ex)
{
	return Rational( re * ex.Re() - im * ex.Im(), re * ex.Im() + im * ex.Re() );
}

Rational Rational::operator/(Rational &ex)
{
		double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();

		return Rational( ( re * ex.Re() + im * ex.Im() ) / r, ( im * ex.Re() - re * ex.Im() ) / r );
}*/
