///////////////////////////////////////////////////////////////////////////////
// project2_timing.cpp
//
// Example code showing how to run each algorithm while measuring
// elapsed times precisely. You should modify this program to gather
// all of your experimental data.
//
///////////////////////////////////////////////////////////////////////////////

#include <algorithm>
#include <cassert>
#include <climits>
#include <iostream>
#include <vector>

#include "timer.hpp"

#include "project2.hpp"

void print_bar() {
  std::cout << std::string(79, '-') << std::endl;
}

void print_abbreviated(const std::string& s) {
  if (s.size() < 80) {
    std::cout << s;
  } else {
    std::cout << s.substr(0, 50)
              << "..."
              << s.substr(s.size() - (79-50-3));
  }
  std::cout << std::endl;
}

int main() {

  const int n = 10*1000;
  assert(n > 0);

  std::string str(random_string(0xBEEF, n));

  double elapsed;
  Timer timer;

  print_bar();
  std::cout << "n = " << n << std::endl
            << "input string:" << std::endl;
  print_abbreviated(str);

  print_bar();
  timer.reset();
  int count = vowel_count(str);
  elapsed = timer.elapsed();
  std::cout << "vowel count = " << count << std::endl;
  std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;

  print_bar();
  timer.reset();
  auto oreo = longest_oreo(str);
  elapsed = timer.elapsed();
  std::cout << "longest oreo:" << std::endl;
  print_abbreviated(oreo);
  std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;

  print_bar();
  timer.reset();
  auto repeat = longest_repeated_substring(str);
  elapsed = timer.elapsed();
  std::cout << "longest repeat:" << std::endl;
  print_abbreviated(repeat);
  std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;

  print_bar();

  return 0;
}
