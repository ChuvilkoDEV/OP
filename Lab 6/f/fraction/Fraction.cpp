#include "Fraction.h"

using namespace std;

Fraction::Fraction(int n, int d) {
  numerator = n;
  denumerator = d;
}

Fraction::Fraction(Fraction &f) {
  numerator = f.numerator;
  denumerator = f.denumerator;
}

Fraction::Fraction() {
  numerator = 0;
  denumerator = 0;
}

// Осуществляет ввод структуры Fraction
void Fraction::inputFraction() {
  cin >> numerator >> denumerator;
}

// Выводит структуру Fraction
void Fraction::outputFraction() const {
  cout << numerator << '/' << denumerator;
}

// Возвращает упрощенную дробь f структуры Fraction
void Fraction::simpleFraction() {
  assert(denumerator != 0);
  int d = gcd(numerator, denumerator);
  numerator /= d;
  denumerator /= d;
}

// Возвращает дробь, которая является результатом произведения дроби f1 и f2
Fraction Fraction::operator*(Fraction &other) const {
  Fraction res(this->numerator * other.numerator,
               this->denumerator * other.denumerator);
  res.simpleFraction();
  return res;
}

// Возвращает дробь, которая является результатом делением дроби f1 на f2
Fraction Fraction::operator/(Fraction &other) const {
  Fraction tmp1(other.denumerator, other.numerator);
  Fraction tmp2((Fraction &) *this);
  Fraction res;
  res = tmp2 * tmp1;
  return res;
}

Fraction Fraction::operator+(Fraction &f) const {
  int d = lcm(this->denumerator, f.denumerator);
  Fraction res(this->numerator * (d / this->denumerator) +
               f.numerator * (d / f.denumerator),
               d);
  res.simpleFraction();
  return res;
}

Fraction Fraction::operator-(Fraction &f) {
  Fraction temp(-f.numerator, f.denumerator);
  Fraction res;
  res = temp + *this;
  return res;
}