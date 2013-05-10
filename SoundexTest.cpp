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

using ::testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

   ASSERT_THAT(encoded, Eq("A000")); 
}

TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
   Soundex soundex;

   auto encoded = soundex.encode("I");

   ASSERT_THAT(encoded, Eq("I000"));
}

