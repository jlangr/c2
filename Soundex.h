#ifndef Soundex_h
#define Soundex_h

#include <string>

// START:Soundex
class Soundex
{
public:
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return zeroPad(head(word) + encodedDigits(word));
// END_HIGHLIGHT
   }

private:
// START_HIGHLIGHT
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }
// END_HIGHLIGHT

// START_HIGHLIGHT
   std::string encodedDigits(const std::string& word) const {
      if (word.length() > 1) return "1";
      return "";
   }
// END_HIGHLIGHT

   std::string zeroPad(const std::string& word) const {
   // ...
// END:Soundex
      auto zerosNeeded = 4 - word.length();
      return word + std::string(zerosNeeded, '0');
// START:Soundex
   }
};
// END:Soundex

#endif
