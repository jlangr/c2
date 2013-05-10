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


#include "gmock/gmock.h"

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
   auto encoded = soundex.encode("A");

   ASSERT_THAT(encoded, testing::Eq("A")); 
}

