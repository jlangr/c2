#include <string>

class Soundex
{
public:
// START:encode
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return "A";
// END_HIGHLIGHT
   }
// END:encode
};

// START:test
#include "gmock/gmock.h"

// START_HIGHLIGHT
using ::testing::Eq;
// END_HIGHLIGHT

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

// START_HIGHLIGHT
   ASSERT_THAT(encoded, Eq("A")); 
// END_HIGHLIGHT
}
// END:test

