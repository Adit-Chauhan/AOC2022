#include "../aoc.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Range {
public:
  int start, stop;
  Range(string line) {
    int delim = line.find('-');
    start = stoi(line.substr(0, delim));
    stop = stoi(line.substr(delim + 1));
  }
  bool full_contains(Range *other) {
    return other->start >= start && other->stop <= stop;
  }
  bool partital_contains(Range *other) {
    return other->start <= stop && other->stop >= start;
  }
};

int part_one(vector<string> *inp) {
  int score = 0;
  for (string pair : *inp) {
    int delim = pair.find(',');
    Range r1(pair.substr(0, delim)), r2(pair.substr(delim + 1));
    score += r1.full_contains(&r2) || r2.full_contains(&r1);
  }
  return score;
}

int part_two(vector<string> *inp) {
  int count = 0;
  for (string pair : *inp) {
    int delim = pair.find(',');
    Range r1(pair.substr(0, delim)), r2(pair.substr(delim + 1));
    count += r1.partital_contains(&r2) || r2.partital_contains(&r1);
  }
  return count;
}

int main() {
  vector<string> inp = get_input();
  cout << part_one(&inp) << '\n' << part_two(&inp);
}
