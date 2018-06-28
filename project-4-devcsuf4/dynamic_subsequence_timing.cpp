///////////////////////////////////////////////////////////////////////////////
// dynamic_subsequence_timing.cpp
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
#include <random>
#include <vector>

#include "timer.hpp"

#include "dynamic_subsequence.hpp"

std::string random_letter_string(int seed, int size, int distinct_letters) {

  assert(size >= 0);
  assert(distinct_letters > 0);
  assert(distinct_letters <= 26);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist('a', 'a' + distinct_letters - 1);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}

void print_bar() {
  std::cout << std::string(79, '-') << std::endl;
}

int main() {

  const int n = 50;

  assert(n > 0);

  std::string a(random_letter_string(1, n, 4)),
              b(random_letter_string(2, n, 4));

  double elapsed;
  Timer timer;

  print_bar();
  std::cout << "n = " << n << std::endl
            << "a='" << a << "'" << std::endl
            << "b='" << b << "'" << std::endl;

  print_bar();
  std::cout << "longest substring" << std::endl;
  timer.reset();
  auto substring = dynamic_longest_substring(a, b);
  elapsed = timer.elapsed();
  std::cout << "longest substring='" << substring << "'"
            << " of length=" << substring.size() << std::endl;
  std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;

  print_bar();
  std::cout << "longest subsequence" << std::endl;
  timer.reset();
  auto subsequence = dynamic_longest_subsequence(a, b);
  elapsed = timer.elapsed();
  std::cout << "longest subsequence='" << subsequence << "'"
            << " of length=" << subsequence.size() << std::endl;
  std::cout << "elapsed time=" << elapsed << " seconds" << std::endl;

  print_bar();

  return 0;
}
