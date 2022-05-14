#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;

  int levelReplace = 0;
  for (auto &i: s) {
    switch (levelReplace) {
      case 0:
        switch (i) {
          case '(':
            cout << '{';
            levelReplace++;
            break;
          case ')':
            perror("\nExpected: '('");
            return 1;
          default:
            cout << i;
        }
        break;
      case 1:
        switch (i) {
          case '(':
            cout << '[';
            levelReplace++;
            break;
          case ')':
            cout << '}';
            levelReplace--;
            break;
          default:
            cout << i;
        }
        break;
      case 2:
        switch (i) {
          case '(':
            cout << '(';
            levelReplace++;
            break;
          case ')':
            cout << ']';
            levelReplace--;
            break;
          default:
            cout << i;
        }
        break;
      case 3:
        switch (i) {
          case '(':
            perror("\nExpected: '('");
            return 2;
          case ')':
            cout << ')';
            levelReplace--;
            break;
          default:
            cout << i;
        }
        break;
    }
  }

  if (levelReplace != 0)
    perror("\nExpected: ')'");

  return 0;
}
