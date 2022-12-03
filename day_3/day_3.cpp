#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
using namespace std;

int score_calc(vector<char> *common) {
  int score = 0;
  for (char c : *common) {
    if (c > 96) {
      score += c - 96;
      continue;
    }
    score += c - 64 + 26;
  }
  return score;
}

int part_one() {
  ifstream infile("input");

  set<char> uno, dos;
  vector<char> common;

  for (string line; getline(infile, line);) {
    int len = line.size();
    for (int i = 0; i < len; i++) {
      if (i < len / 2)
        uno.insert(line[i]);
      else
        dos.insert(line[i]);
    }
    set_intersection(uno.begin(), uno.end(), dos.begin(), dos.end(),
                     back_inserter(common));
    uno.clear();
    dos.clear();
  }
  return score_calc(&common);
}

int part_two() {
  ifstream infile("input");

  vector<char> common;
  for (string line; getline(infile, line);) {
    set<char> uno, dos, tres;
    vector<char> temp;
    uno.insert(line.begin(), line.end());
    getline(infile, line);
    dos.insert(line.begin(), line.end());
    getline(infile, line);
    tres.insert(line.begin(), line.end());
    set_intersection(uno.begin(), uno.end(), dos.begin(), dos.end(),
                     back_inserter(temp));
    set_intersection(temp.begin(), temp.end(), tres.begin(), tres.end(),
                     back_inserter(common));
  }
  return score_calc(&common);
}

int main() { cout << part_one() << ' ' << part_two(); }
