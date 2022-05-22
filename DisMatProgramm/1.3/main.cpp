#include <iostream>
#include <stack>
#include <string>
#include <cassert>

#include "libs/UOAS/UOAS.h"

using namespace std;

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
  int ptr = 0;

  void setPolish() {
    for (; ptr < standardExpression_.size(); ptr++) {
      char c = standardExpression_[ptr];
      switch (c) {
        case '(':
          operators_.push((priority) {c, 4});
          break;
        case ')':
          while (operators_.top().operator_ != '(') {
            push(operators_.top().operator_);
          }
          operators_.pop();
          break;
        case '!':
          operators_.push((priority) {c, 1});
          break;
        case '&':
        case '^':
        case '-':
          pushLessPriority(2);
          operators_.push((priority) {c, 2});
          break;
        case 'u':
          pushLessPriority(3);
          operators_.push((priority) {c, 3});
          break;
        default:
          polishExpression_.push_back(c);
      }
    }
    while (!operators_.empty())
      push(operators_.top().operator_);
  }

  void push(char c) {
    polishExpression_.push_back(c);
    operators_.pop();
  }

  void pushLessPriority(int p) {
    while (!operators_.empty() && operators_.top().priority_ <= p)
      push(operators_.top().operator_);
  }

  public:
  explicit PolishEntry(string &s) {
    setExpression(s);
  }

  PolishEntry() = default;

  void setExpression(string &s) {
    standardExpression_ = s;
    setPolish();
    ptr = 0;
  }

  string getPolish() {
    return polishExpression_;
  }
};

void test_setPolish_0() {
  string s = "A-B-CuA&B-CuC-A-B";
  PolishEntry p{s};

  assert(p.getPolish() == "AB-C-AB&C-uCA-B-u");
}

void test_setPolish_1() {
  string s = "A&!Cu!A&!B&C";
  PolishEntry p{s};

  assert(p.getPolish() == "AC!&A!B!&C&u");
}

void test_setPolish_2() {
  string s = "A-CuC-A-B";
  PolishEntry p{s};

  assert(p.getPolish() == "AC-CA-B-u");
}

void test_setPolish_3() {
  string s = "!(!(A-C)&!(C-A-B))";
  PolishEntry p{s};

  assert(p.getPolish() == "AC-!CA-B-!&!");
}

void test_setPolish_4() {
  string s = "(A-C)u(C-A-B)";
  PolishEntry p{s};

  assert(p.getPolish() == "AC-CA-B-u");
}

void tests_setPolish() {
  test_setPolish_0();
  test_setPolish_1();
  test_setPolish_2();
  test_setPolish_3();
  test_setPolish_4();
}

void tests() {
  tests_setPolish();
}

int main() {
  tests();
}

// (0) A-B-CuA&B-CuC-A-B    // Ответ: AB-C-AB&C-uCA-B-u
// (1) A&!Cu!A&!B&C         // Ответ: AC!&A!B!&C&u
// (2) A-CuC-A-B            // Ответ: AC-CA-B-u
// (3) !(!(A-C)&!(C-A-B))   // Ответ: AC-!CA-B-!&!
// (4) (A-C)u(C-A-B)        // Ответ: AC-CA-B-u