#ifndef AOC_H_
#define AOC_H_
#include <fstream>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <vector>

std::vector<std::string> get_input() {
  std::vector<std::string> inp;
  std::ifstream infile("input");
  for (std::string line; getline(infile, line);)
    inp.push_back(line);
  return inp;
}

#endif // AOC_H_
