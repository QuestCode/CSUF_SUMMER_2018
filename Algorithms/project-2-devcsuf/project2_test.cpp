///////////////////////////////////////////////////////////////////////////////
// project2_test.cpp
//
// Unit tests for project2.hpp
//
///////////////////////////////////////////////////////////////////////////////

#include <string>

#include "rubrictest.hpp"

#include "project2.hpp"

int main() {

  Rubric rubric;

  std::string a("a"),
              cats("cats and dogs"),
              hakuna("hakuna matata");

  std::string words_txt, warandpeace_txt;
  bool words_txt_ok = read_text_file(words_txt, "words.txt"),
       warandpeace_txt_ok = read_text_file(warandpeace_txt, "warandpeace.txt");

  rubric.criterion("read_text_file still works", 1,
   [&]() {
     TEST_TRUE("words.txt", words_txt_ok);
     TEST_EQUAL("words.txt size", 971578, words_txt.size());

     TEST_TRUE("warandpeace.txt", warandpeace_txt_ok);
     TEST_EQUAL("warandpeace.txt size", 3359550, warandpeace_txt.size());
   });

  rubric.criterion("vowel_count", 2,
   [&]() {
     TEST_EQUAL("empty", 0, vowel_count(""));
     TEST_EQUAL(a, 1, vowel_count(a));
     TEST_EQUAL(cats, 3, vowel_count(cats));
     TEST_EQUAL(hakuna, 6, vowel_count(hakuna));
     TEST_EQUAL("mixed case", 4, vowel_count("AaEe"));
     TEST_EQUAL("words.txt", 304513, vowel_count(words_txt));
     TEST_EQUAL("warandpeace.txt", 943031, vowel_count(warandpeace_txt));
   });

   rubric.criterion("longest_oreo", 3,
    [&]() {
      TEST_EQUAL(a, std::string("a"), longest_oreo(a));
      TEST_EQUAL(cats, std::string("s and dogs"), longest_oreo(cats));
      TEST_EQUAL(hakuna, std::string("akuna matata"), longest_oreo(hakuna));
      TEST_EQUAL("words.txt", 971577, longest_oreo(words_txt).size());
      TEST_EQUAL("warandpeace.txt", 3359546, longest_oreo(warandpeace_txt).size());
    });

    rubric.criterion("longest_repeated_substring", 3,
     [&]() {
       TEST_EQUAL(a, std::string(""), longest_repeated_substring(a));
       TEST_EQUAL(cats, std::string("a"), longest_repeated_substring(cats));
       TEST_EQUAL(hakuna, std::string("ata"), longest_repeated_substring(hakuna));
     });

  return rubric.run();
}
