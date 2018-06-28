///////////////////////////////////////////////////////////////////////////////
// project2.hpp
//
// Implementations of algorithms for counting vowels, longest "oreo" problem,
// and longest repeated substring problem.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cctype>
#include <fstream>
#include <random>
#include <string>

bool read_text_file(std::string& result, const std::string& path) {

  std::ifstream f(path);
  if (!f) {
    return false;
  }

  result.clear();

  for (char ch; f.get(ch);) {
    result.push_back(ch);
  }

  return true;
}

std::string random_string(int seed, int size) {

  assert(size >= 0);

  std::string s;

  std::mt19937 gen(seed);
  std::uniform_int_distribution<> dist(0x00, 0xFF);

  for (int i = 0; i < size; ++i) {
    char ch;
    do {
      ch = dist(gen);
    } while (!isprint(ch));

    s.push_back(ch);
  }

  return s;
}

int vowel_count(const std::string& s) {
    // Create a variable to store the amount of vowel and set to zero
    int vowel_count = 0;
    
    // Iterate through string and check for vowels
    for (int i = 0; i < s.length(); ++i) {
        // Check if lowercase character at postion is a lowercase vowel
        // If vowel is found increase amount of vowels by one
        if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u' )
            vowel_count++;
    }
    // return amount of values
    return vowel_count;
}

std::string longest_oreo(const std::string& s) {
    // Check if the string isn't empty
    assert(s.size() > 0);
    // Create a variable to store the result of the longest_oreo and set to empty
    std::string result = "";
    
    // Iterate through string and check for common character at the current postion and last position
    for (int i = 0; i < s.length(); ++i) {
        // Check if lowercase character at postion is the same as lowercase character at the last postion
        if (tolower(s[i]) == tolower(s[s.length() - 1])) {
            // Iterate through string starting at the matching postion
            for (int j = i; j < s.length(); ++j) {
                // Add character at position to result string
                result += tolower(s[j]);
            }
            // return a non empty result
            return result;
        }
    }
    // return empty result
    return result;
}

// Helper function
// finds the longest string that appears at the begining of both string
std::string longest_common_prefix(std::string s, std::string t) {
    // determine which string is shorter
    const unsigned long int n = std::min(s.length(), t.length());
    
    // Iterate through strings until a non match isn't found
    for (int i = 0; i < n; i++) {
        // if non match is found
        if (s.at(i) != t.at(i))
            // return substring from 0 to nonmatch index
            return s.substr(0, i);
    }
    // return smallest of the two substring
    return s.substr(0, n);
}

std::string longest_repeated_substring(const std::string& s) {
    // Check if the string isn't empty
    assert(s.size() > 0);
    
    // create variable to store the s length
    const unsigned long int n = s.length();
    
    // Create a variable to store the result of the longest_repeated_substring and set to empty
    std::string res = "";
    
    // iterate through string starting at first postion
    for (int i = 0; i< n; i++) {
        // iterate through string starting at the current [i + 1] position
        for (int j = i + 1; j < n; j++) {
            // check to see if the substring starting at i or j has a longer substring
            std::string lcp = longest_common_prefix(s.substr(i,n),s.substr(j,n));
            // check if lcp length is larger than current result stored
            // if true set result to lcp
            if (lcp.length() > res.length()) { res = lcp; }
        }
    }
    // return result
    return res;
}
