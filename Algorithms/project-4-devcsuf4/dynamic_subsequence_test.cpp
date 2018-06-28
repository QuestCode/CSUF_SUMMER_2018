///////////////////////////////////////////////////////////////////////////////
// dynamic_subsequence_test.cpp
//
// Unit tests for dynamic_subsequence.hpp
//
///////////////////////////////////////////////////////////////////////////////

#include <string>

#include "rubrictest.hpp"

#include "dynamic_subsequence.hpp"

int main() {

  Rubric rubric;

  rubric.criterion("dynamic_longest_substring trivial instances", 1,
   [&]() {
     TEST_EQUAL("empty-empty", "", dynamic_longest_substring("", ""));
     TEST_EQUAL("empty-nonempty", "", dynamic_longest_substring("", "abc"));
     TEST_EQUAL("nonempty-nonempty", "", dynamic_longest_substring("abc", ""));
     TEST_EQUAL("same string", "abc", dynamic_longest_substring("abc", "abc"));
   });

   rubric.criterion("dynamic_longest_substring non-trivial instances", 3,
    [&]() {
      TEST_EQUAL("ababc babca",
                 "babc",
                 dynamic_longest_substring("ababc", "babca"));
      TEST_EQUAL("hakuna matata",
                 "a",
                 dynamic_longest_substring("hakuna", "matata"));
      TEST_EQUAL("the rain in spain",
                 "ain",
                 dynamic_longest_substring("the rain", "in spain"));
      TEST_EQUAL("bottle otter",
                 "ott",
                 dynamic_longest_substring("bottle", "otter"));
    });

    rubric.criterion("dynamic_longest_subsequence trivial instances", 3,
     [&]() {
       TEST_EQUAL("empty-empty", "", dynamic_longest_subsequence("", ""));
       TEST_EQUAL("empty-nonempty", "", dynamic_longest_subsequence("", "abc"));
       TEST_EQUAL("nonempty-nonempty", "", dynamic_longest_subsequence("abc", ""));
       TEST_EQUAL("same string", "abc", dynamic_longest_subsequence("abc", "abc"));
    });

    rubric.criterion("dynamic_longest_subsequence non-trivial instances", 3,
     [&]() {
       TEST_EQUAL("banana atana",
                  "aana",
                  dynamic_longest_subsequence("banana", "atana"));
       TEST_EQUAL("banana atana",
                  "aana",
                  dynamic_longest_subsequence("atana", "banana"));

       TEST_EQUAL("agcat gac",
                  "ga",
                  dynamic_longest_subsequence("agcat", "gac"));

       TEST_EQUAL("gac agcat",
                  "ac",
                  dynamic_longest_subsequence("gac", "agcat"));

       TEST_EQUAL("abcdgh aedfhr",
                  "adh",
                  dynamic_longest_subsequence("abcdgh", "aedfhr"));
       TEST_EQUAL("aedfhr abcdgh",
                  "adh",
                  dynamic_longest_subsequence("aedfhr", "abcdgh"));

       TEST_EQUAL("aggtab gxtxayb",
                  "gtab",
                  dynamic_longest_subsequence("aggtab", "gxtxayb"));
       TEST_EQUAL("gxtxayb aggtab",
                  "gtab",
                  dynamic_longest_subsequence("gxtxayb", "aggtab"));
     });

  return rubric.run();
}
