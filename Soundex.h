#ifndef Soundex_h
#define Soundex_h

#include <string>

// START:Soundex
class Soundex
{
public:
// START:MaxCodeLength
   static const size_t MaxCodeLength{4};
   // ...
// END:MaxCodeLength

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
      if (word.length() > 1) return encodedDigit();
// END_HIGHLIGHT
      return "";
   }

// START_HIGHLIGHT
   std::string encodedDigit() const {
      return "1";
   }
// END_HIGHLIGHT
// END:encodedDigits

// START:MaxCodeLength
   std::string zeroPad(const std::string& word) const {
// START_HIGHLIGHT
      auto zerosNeeded = MaxCodeLength - word.length();
// END_HIGHLIGHT
      return word + std::string(zerosNeeded, '0');
// END:MaxCodeLength
   }
};
// END:Soundex

#endif
