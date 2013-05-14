#include "gmock/gmock.h" 

#include "Soundex.h"

using namespace ::testing;

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

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits) {
   ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics) {
   ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits) {
   ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters) {
   ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u)); 
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters) {
   ASSERT_THAT(soundex.encode("Caeiouhycdl"), Eq("C234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings) {
   ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
   ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
   ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

   ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

// START:Uppercases
TEST_F(SoundexEncoding, UppercasesFirstLetter) {
   ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}
// END:Uppercases
