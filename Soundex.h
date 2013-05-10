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

   std::string encodedDigits(const std::string& word) const {
      if (word.length() > 1) return "1";
      return "";
   }

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
