// START_HIGHLIGHT
#ifndef Soundex_h
#define Soundex_h
// END_HIGHLIGHT

#include <string>

class Soundex
{
public:
// START:encode
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      auto encoded = word.substr(0, 1);
      if (word.length() > 1)
         encoded += "1";
      return zeroPad(encoded);      
// END_HIGHLIGHT
   }
// END:encode

private:
   std::string zeroPad(const std::string& word) const {
      return word + "000";
   }
};

// START_HIGHLIGHT
#endif
// END_HIGHLIGHT
