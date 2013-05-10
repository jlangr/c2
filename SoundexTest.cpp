// START_HIGHLIGHT
#include <string>
// END_HIGHLIGHT

class Soundex
{
// START_HIGHLIGHT
public:
   std::string encode(const std::string& word) const {
      return "";
   }
// END_HIGHLIGHT
};

#include "gmock/gmock.h"

// START:test
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

// START_HIGHLIGHT
   ASSERT_THAT(encoded, testing::Eq("A")); 
// END_HIGHLIGHT
}
// END:test

