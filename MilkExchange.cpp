#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

vector<ll> containerSizes;
vector<ll> directions;
vector<ll> excessAmounts;

int determineType(int index) {
  int leftNeighbor, rightNeighbor;
  leftNeighbor = index - 1; rightNeighbor = index + 1;
  if (leftNeighbor < 0) leftNeighbor = directions.size() - 1;
  if (rightNeighbor >= directions.size()) rightNeighbor = 0;

  if (directions[leftNeighbor] == 1) {
    if (directions[rightNeighbor] == -1) {
      return 1;
    } else {
      return 0;
    }
  } else {
    if (directions[rightNeighbor] == -1) {
      return 0;
    } else {
      return -1;
    }
  }
}

int main() {
  int numOfBuckets, maxOverflow; cin >> numOfBuckets >> maxOverflow;
  ll sum = 0;
  char direction; int size;
  for (int i = 0; i < numOfBuckets; i++) {
    cin >> direction;
    directions.push_back(direction == 'R' ? 1 : -1);
  }
  for (int i = 0; i < numOfBuckets; i++) {
    cin >> size;
    containerSizes.push_back(size);
    sum += size;
  }

  ll currentIdx, foundOverflow, totalLink;
  for (int i = 0; i < numOfBuckets; i++) {
    if (determineType(i) == 1) {
      if (directions[i] == 1) {
        foundOverflow = true; totalLink = 0;
        currentIdx = i - 1; if (currentIdx < 0) currentIdx = numOfBuckets - 1;
        while (directions[currentIdx] == 1) {
          if (currentIdx == i) {
            foundOverflow = false;
            break;
          }
          totalLink += containerSizes[currentIdx];
          currentIdx--; if (currentIdx < 0) currentIdx = numOfBuckets - 1;
        }
      } else {
        foundOverflow = true; totalLink = 0;
        currentIdx = i + 1; if (currentIdx >= numOfBuckets) currentIdx = 0;
        while (directions[currentIdx] == -1) {
          if (currentIdx == i) {
            foundOverflow = false;
            break;
          }
          totalLink += containerSizes[currentIdx];
          currentIdx++; if (currentIdx >= numOfBuckets) currentIdx = 0;
        }
      }
      excessAmounts.push_back(totalLink);
    }
  }

  for (auto overflow : excessAmounts) {
    sum -= min(overflow, static_cast<ll>(maxOverflow));
  }
  cout << sum;
}