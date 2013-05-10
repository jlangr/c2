#include "gmock/gmock.h" 

#include <string>

// START:Soundex
class Soundex
{
// START:encode
public:
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return zeroPad(word);
// END_HIGHLIGHT
   }

private:
// START_HIGHLIGHT
   std::string zeroPad(const std::string& word) const {
      return word + "000";
   }
// END_HIGHLIGHT
// END:encode
};
// END:Soundex

// START:test
using ::testing::Eq;
// START_HIGHLIGHT
using ::testing::Test;
// END_HIGHLIGHT

// START_HIGHLIGHT
class SoundexEncoding: public Test {
public:
   Soundex soundex;
};
// END_HIGHLIGHT

// START_HIGHLIGHT
TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
// END_HIGHLIGHT
   auto encoded = soundex.encode("A");

   ASSERT_THAT(encoded, Eq("A000")); 
}

// START_HIGHLIGHT
TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
// END_HIGHLIGHT
   auto encoded = soundex.encode("I");

   ASSERT_THAT(encoded, Eq("I000"));
}
// END:test
