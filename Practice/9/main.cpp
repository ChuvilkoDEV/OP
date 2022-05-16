#include <iostream>
#include <string>
#include <utility>

using namespace std;

enum WorkResult {
  OK,
  expectedOpeningBracket,
  expectedClosingBracket
};

WorkResult replaceBrace(string &sOrig) {
  int levelReplace = 0;
  string s = move(sOrig);

  for (auto &i: s) {
    switch (levelReplace) {
      case 0:
        switch (i) {
          case '(':
            i = '{';
            levelReplace++;
            break;
          case ')':
            return expectedOpeningBracket;
          default:
            continue;
        }
        break;
      case 1:
        switch (i) {
          case '(':
            i = '[';
            levelReplace++;
            break;
          case ')':
            i = '}';
            levelReplace--;
            break;
          default:
            continue;
        }
        break;
      case 2:
        switch (i) {
          case '(':
            levelReplace++;
            break;
          case ')':
            i = ']';
            levelReplace--;
            break;
          default:
            continue;
        }
        break;
      default:
        switch (i) {
          case '(':
            levelReplace++;
          case ')':
            levelReplace--;
            break;
          default:
            continue;
        }
        break;
    }
  }

  if (levelReplace != 0)
    return expectedClosingBracket;

  sOrig = move(s);

  return OK;
}

int main() {
  string s;
  cin >> s;

  WorkResult r = replaceBrace(s);
  if (r == OK)
    cout << s;
  else if (r == expectedOpeningBracket)
    perror("Expected: '('");
  else
    perror("Expected: ')'");

  return 0;
}
