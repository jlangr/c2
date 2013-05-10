// START_HIGHLIGHT
class Soundex {
};
// END_HIGHLIGHT

#include "gmock/gmock.h" 

// START:test
TEST(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   Soundex soundex;
   
// START_HIGHLIGHT
   auto encoded = soundex.encode("A");
// END_HIGHLIGHT
}
// END:test

