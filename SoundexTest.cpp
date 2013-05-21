#include "gmock/gmock.h" 

#include "Soundex.h"

using namespace testing;

class SoundexEncoding: public Test {
public:
   Soundex soundex;
};

TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_THAT(soundex.encode("A"), Eq("A000")); 
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits) {
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

// START:ReplacesConsonants
TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
// START_HIGHLIGHT
   ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
// END_HIGHLIGHT
}
// END:ReplacesConsonants

