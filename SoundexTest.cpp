#include <string>

// START:Soundex
class Soundex
{
public:
// START:encode
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return word + "000";
// END_HIGHLIGHT
   }
// END:encode
};
// END:Soundex


#include "gmock/gmock.h" 

using ::testing::Eq;

// START:RetainsSoleLetter
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

// START_HIGHLIGHT
   ASSERT_THAT(encoded, Eq("A000")); 
// END_HIGHLIGHT
}
// END:RetainsSoleLetter

// START:PadsWithZeros
TEST(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
   Soundex soundex;

   auto encoded = soundex.encode("I");

   ASSERT_THAT(encoded, Eq("I000"));
}
// END:PadsWithZeros
