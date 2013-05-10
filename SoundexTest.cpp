#include "gmock/gmock.h"    

#include <string>

// START:Soundex
class Soundex
{
public:
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return word;
// END_HIGHLIGHT
   }
};
// END:Soundex

// START:test
using ::testing::Eq;

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

   ASSERT_THAT(encoded, Eq("A")); 
}
// END:test

