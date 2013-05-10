// START_HIGHLIGHT
#ifndef Soundex_h
#define Soundex_h
// END_HIGHLIGHT

#include <string>

class Soundex
{
public:
   std::string encode(const std::string& word) const {
      return zeroPad(word);
   }

private:
   std::string zeroPad(const std::string& word) const {
      return word + "000";
   }
};

// START_HIGHLIGHT
#endif
// END_HIGHLIGHT
