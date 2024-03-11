#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> differences;

int main() {
  int numEntries, queries; cin >> numEntries >> queries;
  int timeEntry;
  int maxDifference = -1;
  for (int i = 0; i < numEntries; i++) {
    cin >> timeEntry;
    differences.push_back(timeEntry);
    maxDifference = max(maxDifference, timeEntry);
  }

  for (int i = 0; i < numEntries; i++) {
    cin >> timeEntry;
    differences[i] -= timeEntry;
  }

  sort(differences.begin(), differences.end());

  int required, threshold;
  while (queries--) {
    cin >> required >> threshold;
    vector<int>::iterator it = upper_bound(differences.begin(), differences.end(), threshold);
    if (numEntries - (it - differences.begin()) >= required) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}