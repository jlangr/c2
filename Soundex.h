#ifndef Soundex_h
#define Soundex_h

#include <string>

// START:Soundex
class Soundex
{
public:
   static const size_t MaxCodeLength{4};

   std::string encode(const std::string& word) const {
      return zeroPad(head(word) + encodedDigits(word));
   }

private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }

// START:encodedDigits
   std::string encodedDigits(const std::string& word) const {
// START_HIGHLIGHT
      if (word.length() > 1) return encodedDigit(word[1]);
// END_HIGHLIGHT
      return "";
   }

// START_HIGHLIGHT
   std::string encodedDigit(char letter) const {
      if (letter == 'c') return "2";
// END_HIGHLIGHT
      return "1";
   }
// END:encodedDigits

   std::string zeroPad(const std::string& word) const {
      auto zerosNeeded = MaxCodeLength - word.length();
      return word + std::string(zerosNeeded, '0');
   }
};
// END:Soundex

#endif
