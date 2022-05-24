#include "Fraction.h"

using namespace std;
class Fraction {
  private:
  int numerator;
  int denumerator;

  public:
// Осуществляет ввод структуры Fraction
  void inputFraction(Fraction *f) {
    scanf("%d %d", &f->numerator, &f->denumerator);
  }

// Осуществляет ввод массива структуры Fraction
  void inputFractions(Fraction *f, size_t n) {
    for (size_t i = 0; i < n; i++)
      inputFraction(&f[i]);
  }

// Выводит структуру Fraction
  void outputFraction(Fraction f) {
    printf("%d/%d", f.numerator, f.denumerator);
  }

// Выводит массив структуры Fraction
  void outputFractions(Fraction *f, size_t n) {
    for (size_t i = 0; i < n; i++) {
      outputFraction(f[i]);
      if (i < n - 1)
        printf(", ");
    }
    printf("\n");
  }

  void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
  }

  void sort2(int *a, int *b) {
    if (a > b)
      swap(a, b);
  }

// Возвращает наибольший общий делитель чисел a и b
  int gcd(int a, int b) {
    sort2(&a, &b);
    if (b % a == 0)
      return a;
    int gcd = 1;
    for (int i = 2; i <= (int) sqrt(b); i++)
      if (a % i == 0 && b % i == 0)
        gcd = i;
    return gcd;
  }

// Возвращает наименьшее общее кратное чисел a и b
  int lcm(int a, int b) {
    sort2(&a, &b);
    int d = gcd(a, b);
    if (d == 1)
      return a * b;
    else if (d == a)
      return b;
    return b * a / d;
  }

// Возвращает упрощенную дробь f структуры Fraction
  void simpleFraction(Fraction *f) {
    assert(f->denumerator != 0);
    int d = gcd(f->numerator, f->denumerator);
    f->numerator /= d;
    f->denumerator /= d;
  }

// Возвращает дробь, которая является результатом произведения дроби f1 и f2
  Fraction mulFractions(Fraction f1, Fraction f2) {
    assert(f1.denumerator != 0 && f2.denumerator != 0);
    Fraction f3;
    Fraction n1 = (Fraction) {f1.numerator, f2.denumerator};
    Fraction n2 = (Fraction) {f2.numerator, f1.denumerator};
    simpleFraction(&n1);
    simpleFraction(&n2);
    f3.numerator = n1.numerator * n2.numerator;
    f3.denumerator = n1.denumerator * n2.denumerator;
    return f3;
  }

// Возвращает дробь, которая является результатом делением дроби f1 на f2
  Fraction divFraction(Fraction f1, Fraction f2) {
    assert(f1.denumerator != 0 && f2.denumerator != 0);
    return mulFractions(f1, (Fraction) {f2.denumerator, f2.numerator});
  }

// Возвращает дробь, которая является суммой дроби f1 и f2
  Fraction addFraction(Fraction f1, Fraction f2) {
    assert(f1.denumerator != 0 && f2.denumerator != 0);
    Fraction f3;
    int d = lcm(f1.denumerator, f2.denumerator);
    f3.numerator = f1.numerator * (d / f1.denumerator) +
                   f2.numerator * (d / f2.denumerator);
    f3.denumerator = d;
    simpleFraction(&f3);
    return f3;
  }

// Возвращает дробь, которая является разницей f1 и f2
  Fraction subFraction(Fraction f1, Fraction f2) {
    return addFraction(f1, (Fraction) {-f2.numerator, f2.denumerator});
  }

// Возвращает сумму дробей массива f размера n структуры Fraction
  Fraction sumFractions(Fraction *f, size_t n) {
    Fraction f3 = f[0];
    for (size_t i = 1; i < n; i++) {
      assert(f->denumerator != 0);
      f3 = addFraction(f3, f[i]);
    }
    return f3;
  }
};