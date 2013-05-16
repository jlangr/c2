#include "gmock/gmock.h"

#include <string>
#include "CharUtil.h"

using namespace std;
using namespace testing;
using namespace charutil;

TEST(AChar, IsAVowelForSixSpecificLetters) {
   ASSERT_TRUE(isVowel('A'));
   ASSERT_TRUE(isVowel('E'));
   ASSERT_TRUE(isVowel('I'));
   ASSERT_TRUE(isVowel('O'));
   ASSERT_TRUE(isVowel('U'));
   ASSERT_TRUE(isVowel('Y'));
}

TEST(AChar, IsAVowelForLowercaseLetters) {
   ASSERT_TRUE(isVowel('a'));
   ASSERT_TRUE(isVowel('e'));
   ASSERT_TRUE(isVowel('i'));
   ASSERT_TRUE(isVowel('o'));
   ASSERT_TRUE(isVowel('u'));
   ASSERT_TRUE(isVowel('y'));
}

TEST(AChar, IsNotAVowelForAnyOtherCharacter) {
   ASSERT_FALSE(isVowel('b'));
}

TEST(AChar, AnswersAppropriateUpperCaseLetter) {
   ASSERT_THAT(upper('a'), Eq('A'));
}

TEST(AChar, HandlesAlreadyUppercasedLetters) {
   ASSERT_THAT(upper('B'), Eq('B'));
}

TEST(AChar, IgnoresNonLettersWhenUppercasing) {
   ASSERT_THAT(upper('+'), Eq('+'));
}

TEST(AChar, AnswersAppropriateLowerCaseLetter) {
   ASSERT_THAT(lower('A'), Eq('a'));
}

TEST(AChar, HandlesAlreadyLowercased) {
   ASSERT_THAT(lower('b'), Eq('b'));
}

TEST(AChar, IgnoresNonLettersWhenLowercasing) {
   ASSERT_THAT(lower('+'), Eq('+'));
}
