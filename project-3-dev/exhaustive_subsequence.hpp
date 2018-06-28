///////////////////////////////////////////////////////////////////////////////
// exhaustive_subsequence.hpp
//
// Exhaustive search algorithms for the longest substring, and longest
// subsequence, problems.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <string>
#include <cstring>
#include <math.h>

// Helper function
// finds the longest string that appears at the begining of both string
std::string longest_common_substring(std::string s, std::string t) {
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

std::string exhaustive_longest_substring(const std::string& a,
                                         const std::string& b) {
    // create variable for best result and lengths of each string
    std::string best = "";
    const unsigned long int m = a.length();
    const unsigned long int n = b.length();
    
    // loop through first string
    for(int i = 0; i < m; ++i){
        // loop through second string
        for(int j = 0; j < n; ++j){
            // store longest substring found
            std::string x = longest_common_substring(a.substr(i,m),b.substr(j,n));
            // compare to best stored
            if (x.length() > best.length()) { best = x; }
        }
    }

    return best;
}

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

bool detect_subsequence(const std::string& candidate_subsequence,
                        const std::string& candidate_supersequence) {
    
    // create a char array to store string
    char *cand_subseqPtr = new char[candidate_subsequence.size() + 1];
    char *cand_supersubseqPtr = new char[candidate_supersequence.size() + 1];
    
    std::strcpy(cand_subseqPtr, candidate_subsequence.c_str());
    std::strcpy(cand_supersubseqPtr, candidate_supersequence.c_str());
    
    // loop through each string until both reach a null character
    while (*cand_subseqPtr && *cand_supersubseqPtr){
        // find a matching character in both
        if (*cand_subseqPtr == *cand_supersubseqPtr++) {
            // if cound increment through first string
            cand_subseqPtr++;
        }
    }
    
    return !*cand_subseqPtr;
}

// Create a helper function to get powersets of a string
std::vector<std::string> generate_powersets(std::string s) {
    std::vector<std::string> results;
    //set_size of power set to 2^n
    unsigned int pow_set_size = pow(2, s.length());
    
    // find powerset computer science help
    // https://en.wikipedia.org/wiki/Power_of_two
    // run from counter 000..0 to 111..1
    for(int i = 0; i < pow_set_size; i++){
        // tempString is need to store each power set that is created
        std::string tempString = "";
        for(int j = 0; j < s.length(); j++) {
            // check if jth bit in the counter is set
            // if set then pront jth element from set
            if(i & (1<<j))
                tempString += s[j];
        }
        results.push_back(tempString);
    }
    return results;
}


std::string exhaustive_longest_subsequence(const std::string& a,
                                           const std::string& b) {

    std::string best = "";
    std::string shorter = "";
    std::string longer = "";
    
    // find the shortest string inputted
    if (a.length() > b.length()) { shorter = b; longer = a; }
    else { shorter = a; longer = b; }
    
    // create powerset of shorter string
    std::vector<std::string> candSub = generate_powersets(shorter);
    
    for (std::string sub : candSub) {
        if (detect_subsequence(sub, longer) && sub.length() > best.length()) {
            best = sub;
        }
    }
    
    return best;
}
