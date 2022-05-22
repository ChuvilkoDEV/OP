#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include "vector"
#include <utility>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <limits.h>
#include <assert.h>

using namespace std;


typedef struct unordered_array_set {
  int *data; // элементы множества
  size_t size; // количество элементов в множестве
  size_t capacity; // максимальное количество элементов в множестве
} unordered_array_set;

int compare_ints(const void *a, const void *b) {
  int arg1 = *(const int *) a;
  int arg2 = *(const int *) b;
  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

void inputArray_(int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
  for (size_t i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
  a[*n] = value;
  (*n)++;
}

void insert_(int *const a, size_t *const n, const size_t pos,
             const int value) {
  assert(pos < *n);
  if (*n != 0) {
    size_t lowBound = (pos == 0) ? ULONG_MAX : pos;
    (*n)++;
    for (size_t i = *n; i != lowBound; i--)
      a[i] = a[i - 1];
    a[pos] = value;
  } else {
    (*n)++;
    a[pos] = value;
  }
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
  for (size_t i = pos + 1; i < *n; i++)
    a[i] = a[i + 1];
  (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
  a[pos] = a[*n - 1];
  (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
  for (size_t i = 0; i < n; i++)
    if (a[i] == x)
      return i;
  return n;
}

int any_(const int *a, size_t n, int (*predicate)(int)) {
  for (size_t i = 0; i < n; i++)
    if (predicate(a[i]))
      return 1;
  return 0;
}

int all_(const int *a, size_t n, int (*predicate)(int)) {
  for (size_t i = 0; i < n; i++)
    if (!predicate(a[i]))
      return 0;
  return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate)(int)) {
  int count = 0;
  for (size_t i = 0; i < n; i++)
    count += predicate(a[i]);
  return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate)(int)) {
  size_t iRead = 0;
  while (iRead < *n && !deletePredicate(a[iRead]))
    iRead++;
  size_t iWrite = iRead;
  while (iRead < *n) {
    if (!deletePredicate(a[iRead])) {
      a[iWrite] = a[iRead];
      iWrite++;
    }
    iRead++;
  }
  *n = iWrite;
}

void forEach_(const int *source, int *dest,
              const size_t n, const int (*predicate)(int)) {
  for (size_t i = 0; i < n; i++)
    dest[i] = predicate(source[i]);
}

size_t binarySearch_(const int *a, size_t n, int x) {
  size_t left = 0;
  size_t right = n - 1;
  while (left <= right) {
    size_t middle = left + (right - left) / 2;
    if (a[middle] < x)
      left = middle + 1;
    else if (a[middle] > x)
      right = middle - 1;
    else
      return middle;
  }
  return n;
}

size_t binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
  if (a[0] >= x)
    return 0;
  size_t left = 0;
  size_t right = n;
  while (right - left > 1) {
    size_t middle = left + (right - left) / 2;
    if (a[middle] < x)
      left = middle;
    else
      right = middle;
  }
  return right;
}

// возвращает пустое множество для capacity элементов
unordered_array_set UOAS_create(size_t capacity) {
  return (unordered_array_set) {
    static_cast<int *>(malloc(sizeof(int) * capacity)),
    0,
    capacity
  };
}

// уменьшает вместимость множества a до его размера
void UOAS_shrinkToFit(unordered_array_set *a) {
  if (a->size != a->capacity) {
    a->data = (int *) realloc(a->data, sizeof(int) * a->size);
    a->capacity = a->size;
  }
}

// возвращает позицию элемента в множестве,
// если значение value имеется в множестве set,
// иначе - n
size_t UOAS_in(unordered_array_set *set, int value) {
  return linearSearch_(set->data, set->size, value);
}

// возвращает значение ’истина’, если элементы множеств set1 и set2 равны
// иначе - ’ложь’
bool UOAS_isEqual(unordered_array_set set1,
                  unordered_array_set set2) {
  if (set1.size != set2.size)
    return false;
  qsort(set1.data, set1.size, sizeof(int), compare_ints);
  qsort(set2.data, set2.size, sizeof(int), compare_ints);
  return memcmp(set1.data, set2.data, sizeof(int) * set1.size) == 0;
}

// возбуждает исключение, если в множество по адресу set
// нельзя вставить элемент
void UOAS_isAbleAppend(unordered_array_set *set) {
  assert(set->size < set->capacity);
}

// добавляет элемент value в множество set
void UOAS_insert(unordered_array_set *set, int value) {
  if (UOAS_in(set, value) == set->size) {
    UOAS_isAbleAppend(set);
    append_(set->data, &set->size, value);
  }
}

// возвращает множество, состоящее из элементов массива a размера size
unordered_array_set UOAS_create_from_array(const int *a, size_t size) {
  unordered_array_set set = UOAS_create(size);
  for (size_t i = 0; i < size; i++) {
    UOAS_insert(&set, a[i]);
  }
  UOAS_shrinkToFit(&set);
  return set;
}

// удаляет элемент value из множества set
void UOAS_deleteElement(unordered_array_set *set, int value) {
  size_t pos = UOAS_in(set, value);
  if (pos != set->size) {
    deleteByPosUnsaveOrder_(set->data, &set->size, pos);
  }
}

// возвращает объединение множеств set1 и set2
unordered_array_set UOAS_union(unordered_array_set set1,
                               unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size + set2.size);
  memcpy(set.data, set1.data, sizeof(int) * set1.size);
  set.size = set1.size;
  for (size_t i = 0; i < set2.size; i++) {
    UOAS_insert(&set, set2.data[i]);
  }
  return set;
}

// возвращает пересечение множеств set1 и set2
unordered_array_set UOAS_intersection(unordered_array_set set1,
                                      unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size);
  for (int i = 0; i < set1.size; i++) {
    size_t pos = linearSearch_(set2.data, set2.size, set1.data[i]);
    if (pos != set2.size)
      UOAS_insert(&set, set2.data[pos]);
  }
  return set;
}

// возвращает разность множеств set1 и set2
unordered_array_set UOAS_difference(unordered_array_set set1,
                                    unordered_array_set set2) {
  unordered_array_set set = UOAS_create(set1.size);
  for (int i = 0; i < set1.size; i++) {
    size_t pos = UOAS_in(&set2, set1.data[i]);
    if (pos == set2.size)
      UOAS_insert(&set, set1.data[i]);
  }
  return set;
}

// возвращает симметрическую разность множеств set1 и set2
unordered_array_set UOAS_symmetricDifference(unordered_array_set set1,
                                             unordered_array_set set2) {
  return UOAS_union(UOAS_difference(set1, set2),
                    UOAS_difference(set2, set1));
}

// возвращает значение "истина", если множество
// set является подмножеством subset
bool UOAS_isSubset(unordered_array_set set,
                   unordered_array_set subset) {
  for (int i = 0; i < subset.size; i++) {
    if (UOAS_in(&set, subset.data[i]) == set.size)
      return false;
  }
  return true;
}

// возвращает дополнение до универсума множества set
unordered_array_set UOAS_complement(unordered_array_set set,
                                    unordered_array_set universumSet) {
  assert(UOAS_isSubset(universumSet, set));
  return UOAS_difference(universumSet, set);
}

// вывод множества set
void UOAS_print(unordered_array_set set) {
  printf("{");
  if (set.size == 0)
    printf("}\n");
  else {
    for (int i = 0; i < set.size; i++) {
      printf("%d, ", set.data[i]);
    }
    printf("\b\b}\n");
  }
}

// освобождает память, занимаемую множеством set
void UOAS_delete(unordered_array_set set) {
  free(set.data);
}

// Структура, которая хранит оператор и его приоритет
struct priority {
  char operator_;
  int priority_;
};


class PolishEntry {
  private:
  string standardExpression_{};
  string polishExpression_{};
  stack<priority> operators_{};
  stack<char> operands_{};
  int ptr = 0;

  void setPolish() {
    polishExpression_.push_back(standardExpression_[0]);
    ptr++;
    for (; ptr < standardExpression_.size(); ptr++) {
      char c = standardExpression_[ptr];
      if (c == '(') {
        PolishEntry p{};
        p.setExpression((string &) (standardExpression_[ptr]));
        ptr += p.getPtr();
        string tmp = p.getPolish();
        for (auto &j: tmp)
          polishExpression_.push_back(j);
      } else if (c == ')') {
        break;
      } else if (c == '!') {
        if (!operands_.empty()) {
          polishExpression_.push_back(operands_.top());
          operands_.pop();
          polishExpression_.push_back(c);
        } else {
          operators_.push((priority) {c, 1});
        }
      } else if (c == '&' || c == '^' || c == '-') {
        while (!operators_.empty() && !operands_.empty() && operators_.top().priority_ <= 2) {
          polishExpression_.push_back(operands_.top());
          operands_.pop();
          polishExpression_.push_back(operators_.top().operator_);
          operators_.pop();
        }
        if (!operators_.empty() && operators_.top().priority_ == 3) {
          polishExpression_.push_back(operands_.top());
          operands_.pop();
        }
        operators_.push((priority) {c, 2});
      } else if (c == 'u') {
        while (!operators_.empty() && !operands_.empty() && operators_.top().priority_ <= 3) {
          polishExpression_.push_back(operands_.top());
          operands_.pop();
          polishExpression_.push_back(operators_.top().operator_);
          operators_.pop();
        }
        operators_.push((priority) {c, 3});
      } else {
        operands_.push(c);
      }
    }
    while (!operands_.empty()) {
      polishExpression_.push_back(operands_.top());
      operands_.pop();
    }
    while (!operators_.empty()) {
      polishExpression_.push_back(operators_.top().operator_);
      operators_.pop();
    }
  }

  char getOperand() {
    char tmp = operands_.top();
    operands_.pop();
    return tmp;
  }

  public:
  void setExpression(string &s) {
    standardExpression_ = s;
    setPolish();
    ptr = 0;
  }

  int getPtr() const {
    return ptr;
  }

  string getPolish() {
    return polishExpression_;
  }
};

int main() {
  PolishEntry p;
  string s = "A-B-CuA&B-CuC-A-B";
  p.setExpression(s);

  cout << p.getPolish();
}

// (0) A-B-CuA&B-CuC-A-B
// (1) A&!Cu!A&!B&C
// (2) A-CuC-A-B
// (3) !(!(A-C)&!(C-A-B))
// (4) (A-C)u(C-A-B)