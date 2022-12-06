#include "../aoc.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

int common_func(string &s, int num_uniq) {
  for (int i = num_uniq; i < s.size(); i++) {
    set<char> uniq(s.begin() + (i - num_uniq), s.begin() + i);
    if (uniq.size() == num_uniq)
      return i;
  }
  return -1;
}

int part_one(string &s) { return common_func(s, 4); }
int part_two(string &s) { return common_func(s, 14); }
int main() {
  string inp = get_input()[0];
  cout << part_one(inp) << ' ' << part_two(inp);
}
