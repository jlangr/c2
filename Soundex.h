// START_HIGHLIGHT
#ifndef Soundex_h
#define Soundex_h
// END_HIGHLIGHT

#include <string>

class Soundex
{
public:
   std::string encode(const std::string& word) const {
      auto encoded = word.substr(0, 1);
      if (word.length() > 1)
         encoded += "1";
      return zeroPad(encoded);      
   }

private:
// START:zeroPad
   std::string zeroPad(const std::string& word) const {
// START_HIGHLIGHT
      auto zerosNeeded = 4 - word.length();
      return word + std::string(zerosNeeded, '0');
// END_HIGHLIGHT
   }
// END:zeroPad
};

// START_HIGHLIGHT
#endif
// END_HIGHLIGHT
