#include "gmock/gmock.h" 

// START_HIGHLIGHT
#include "Soundex.h"
// END_HIGHLIGHT

// START_HIGHLIGHT
using namespace ::testing;
// END_HIGHLIGHT

// START_HIGHLIGHT
class SoundexEncoding: public Test {
// END_HIGHLIGHT
public:
   Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
// START_HIGHLIGHT
   ASSERT_THAT(soundex.encode("A"), Eq("A000")); 
// END_HIGHLIGHT
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
// START_HIGHLIGHT
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
// END_HIGHLIGHT
}

