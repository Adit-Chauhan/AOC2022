#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

int part_one() {
  int score = 0;
  for (string line; getline(cin, line);) {
    int a = line[0] - 64, b = line[2] - 87;
    if (a == b)
      score += (b + 3);
    else if (b - a == 1)
      score += (b + 6);
    else if (b == 1 && a == 3)
      score += (b + 6);
    else
      score += b;
  }
  return score;
}

int part_two() {
  int score = 0;
  for (string line; getline(cin, line);) {
    int a = line[0] - 64, b = line[2] - 87;
    if (b == 2) {
      score += (a + 3);
    } else if (b == 1) {
      score += (a == 1) ? 3 : (a - 1);
    } else {
      score += (6 + ((a == 3) ? 1 : (a + 1)));
    }
  }
  return score;
}

int main() { cout << part_two() << '\n'; }
