#include <iostream>
#include <string>

using namespace std;

int main() {
  int numCases; cin >> numCases;
  string inputStr;
  while (numCases--) {
    cin >> inputStr;
    if (inputStr.back() == '0') {
      cout << "E" << endl;
    } else {
      cout << "B" << endl;
    }
  }
}