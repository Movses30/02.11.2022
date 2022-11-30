#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  bool valid(string str) {
    vector<char> stak;
    for (int i = 0; str[i] != '\0'; i++) {
      switch (str[i]) {
      case '(':
      case '{':
      case '[':
        stak.push_back(str[i]);
        break;
      case ')':
        if (stak.empty() || stak.back() != '(')
          return false;
        stak.pop_back();
        break;
      case '}':
        if (stak.empty() || stak.back() != '{')
          return false;
        stak.pop_back();
        break;
      case ']':
        if (stak.empty() || stak.back() != '[')
          return false;
        stak.pop_back();
        break;
      }
    }
    return stak.empty();
  }
};

int main()
{
  Solution test;
  cout << boolalpha << test.valid("()") << "\n";
  cout << boolalpha << test.valid("(}") << "\n";
  cout << boolalpha << test.valid("(]") << "\n";
  cout << boolalpha << test.valid("())") << "\n";
  cout << boolalpha << test.valid("{}") << "\n";
  cout << boolalpha << test.valid("{]") << "\n";
  cout << boolalpha << test.valid("[]") << "\n";
  return 0;
}