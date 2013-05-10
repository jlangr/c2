#include "gmock/gmock.h"

#include <string>

// START:encode
class Soundex
{
// START_HIGHLIGHT
public:
   std::string encode(const std::string& word) const {
      return "";
   }
// END_HIGHLIGHT
};
// END:encode

TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
// START_HIGHLIGHT
   auto encoded = soundex.encode("A");
// END_HIGHLIGHT
}

