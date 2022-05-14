#include <stdio.h>
#include <math.h>

#define EPS 0.00001

/////////////////
/// 1 Задание ///
/////////////////

// Возвращает модуль вещественного числа a
double dabs(const double a) {
  return a >= 0 ? a : -a;
}

/////////////////
/// 2 Задание ///
/////////////////

// Возвращает наибольшее число из двух введенных целочисленных
// переменных a и b
int max2(const int a, const int b) {
  return a > b ? a : b;
}

/////////////////
/// 3 Задание ///
/////////////////

// Возвращает наибольшее значение из трех введенных целочисленных переменных
// a, b и c
int max3(const int a, const int b, const int c) {
  return max2(max2(a, b), c);
}

/////////////////
/// 4 Задание ///
/////////////////

// Возвращает расстояние между двумя точками с координатами (х1, у1) и (х2, у2)
double getDistance(const int x1, const int y1,
                   const int x2, const int y2) {
  int dx = abs(x1 - x2); // дельта x
  int dy = abs(y1 - y2); // дельта у
  return sqrt(dx * dx + dy * dy);
}

/////////////////
/// 5 Задание ///
/////////////////

// Выводит корни квадратного уравнения, где a, b, c – коэффициенты.
void solveX2(const int a, const int b, const int c) {
  if (a == 0)
    printf("not quadratic");
  double D = pow(b, 2) - 4 * a * c;
  if (D < -EPS)
    printf("No solutions");
  else if (dabs(D) <= EPS)
    printf("x = %d", -b / (2 * a));
  else {
    double sqrtD = sqrt(D);
    double x1 = (-b + sqrtD) / (2 * a);
    double x2 = (-b - sqrtD) / (2 * a);
    printf("x1 = %lf\nx2 = %lf", x1, x2);
  }
}

/////////////////
/// 6 Задание ///
/////////////////

// Возвращает значение 1 (’истина’), если символ x - является цифрой,
// 0 (’ложь’) - в противном случае.
int isDigit(const char x) {
  return x >= '0' && x <= '9';
}

/////////////////
/// 7 Задание ///
/////////////////

// Обменивает значения двух переменных a и b типа float
void swap(float *a, float *b) {
  float t = *a;
  *a = *b;
  *b = t;
}

/////////////////
/// 8 Задание ///
/////////////////

// Сортирует значения a и b по возрастанию.
void sort2(float *a, float *b) {
  if (*a > *b)
    swap(a, b);
}

/////////////////
/// 9 Задание ///
/////////////////

// Сортирует значения а, b и c по возрастанию.
void sort3(float *a, float *b, float *c) {
  sort2(a, b);
  sort2(b, c);
  sort2(a, b);
}

//////////////////
/// 10 Задание ///
//////////////////

// Возвращает 1 (`Истина`), если треугольник со сторонами a, b и c существует.
// 0 (`Ложь`) - в обратном случае
int isTriangleExist(float a, float b, float c) {
  sort3(&a, &b, &c);
  return a + b > c;
}

//////////////////
/// 11 Задание ///
//////////////////

// Возвращает 0, если треугольник со сторонами a, b, c - является остроугольным,
// 1 — если прямоугольный, 2 — тупоугольным, -1 — если треугольник
// с такими сторонами не существует
int getTriangleTypeLength(float a, float b, float c) {
  sort3(&a, &b, &c);
  if (isTriangleExist(a, b, c) == 0)
    return -1;
  float pythagoreanTheorem = a * a + b * b - c * c;
  if (pythagoreanTheorem > EPS)
    return 0;
  else if (dabs(pythagoreanTheorem) <= EPS)
    return 1;
  else
    return 2;
}

//////////////////
/// 12 Задание ///
//////////////////

// Возвращает 1, если число a простое, 0 в обратном случае. Без оптимизаций
int isPrimeA(const int a) {
  if (a == 1)
    return 0;
  for (int divider = 2; divider < a; divider++)
    if (a % divider == 0)
      return 0;
  return 1;
}

// Возвращает 1, если число a простое, 0 в обратном случае. С оптимизацией
// перебора до √ 𝑁.
int isPrimeB(const int a) {
  if (a == 1)
    return 0;
  int sqrtA = (int) sqrt(a);
  for (int divider = 2; divider <= sqrtA; divider++)
    if (a % divider == 0)
      return 0;
  return 1;
}

// Возвращает 1, если число a простое, 0 - в обратном случае. С оптимизацией
// перебора до √ 𝑁 с шагом 2.
int isPrimeC(const int a) {
  if ((a % 2 == 0 || a == 1) && a != 2)
    return 0;
  int sqrtA = (int) sqrt(a);
  for (int divider = 3; divider <= sqrtA; divider += 2)
    if (a % divider == 0)
      return 0;
  return 1;
}

//////////////////
/// 13 Задание ///
//////////////////

// Возвращает число, которое будет получено, после удаление цифр digit из
// восьмеричной записи числа
int deleteOctNumber(int a, const int digit) {
  int afterProcessA = 0, octIndex = 0;
  while (a > 0) {
    int iDigit = a & 7;
    if (iDigit != digit)
      afterProcessA += iDigit << (3 * octIndex++);
    a >>= 3;
  }
  return afterProcessA;
}

//////////////////
/// 14 Задание ///
//////////////////

// Возвращает число, которое будет получено, после того, как соседние цифры
// в двоичной записи числа a, начиная с младших разрядов, поменяются местами
int swapPairBites(int a) {
  int afterProcessA = 0, quaIndex = 0;
  while (a > 0) {
    if (a == 1)
      afterProcessA += 1 << (2 * quaIndex++);
    else {
      int iDigit = a & 3;
      if (iDigit == 1 || iDigit == 2)
        iDigit = 3 - iDigit;

      afterProcessA += iDigit << (2 * quaIndex++);
    }
    a >>= 2;
  }
  return afterProcessA;
}

//////////////////
/// 15 Задание ///
//////////////////

// Возвращает длину числа a, записанного в (2^n)-ой системе счисления
int lengthN(int a, const int n) {
  int lengthHex = 0;
  while (a > 0) {
    lengthHex++;
    a >>= n;
  }
  return lengthHex;
}

// Возвращает число, которое будет получено, после того, как цифры в
// шестнадцатеричном представлении числа a будут записаны в обратном порядке
int invertHex(int a) {
  int afterProcessA = 0;
  for (int i = lengthN(a, 4) - 1; i >= 0; i--) {
    int iDigit = a & 15;
    afterProcessA += iDigit << (4 * i);
    a >>= 4;
  }
  return afterProcessA;
}

//////////////////
/// 16 Задание ///
//////////////////

// Возвращает значение 1, если число x является палиндромом в
// двоичном представлении, иначе - 0.
int isBinPoly(const int x) {
  int isPoly = 0, tmp = x, afterProcessX = 0;
  while (tmp > 0) {
    if (afterProcessX != 0)
      afterProcessX <<= 1;
    afterProcessX += tmp & 1;
    tmp >>= 1;
  }
  if (x == afterProcessX)
    isPoly = 1;
  return isPoly;
}

//////////////////
/// 17 Задание ///
//////////////////

// Возвращает целое число, последовательность нечетных битов которого
// представляет собой значение sh1, а последовательность четных – значение sh2.
int twoBitHybrid(short sh1, short sh2) {
  int result = 0;
  char shift = 0;
  while (sh1 > 0 || sh2 > 0) {
    result += (sh2 & 1) << shift;
    result += (sh1 & 1) << (shift + 1);
    shift += 2;
    sh2 >>= 1;
    sh1 >>= 1;
  }
  return result;
}

//////////////////
/// 18 Задание ///
//////////////////

// Выводит восьмеричное представление числа х
void octNum(int x) {
  int l = lengthN(x, 3);
  for (int i = 0; i < l; i++)
    printf("%d", (x >> 3 * (l - i - 1)) & 7);
}

//////////////////
/// 19 Задание ///
//////////////////

// Возвращает максимальную длину последовательности подряд идущих битов
// равных единице в двоичном представлении числа x.
int binSequence(int x) {
  int maxSequence = 0, lastSequence = 0;
  while (x > 0) {
    if (x & 1) {
      lastSequence++;
      maxSequence = max2(lastSequence, maxSequence);
    } else
      lastSequence = 0;

    x >>= 1;
  }
  return maxSequence;
}

int main() {
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);

  solveX2(a, b, c);

  return 0;
}