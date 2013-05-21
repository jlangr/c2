#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>

class Soundex
{
public:
   static const size_t MaxCodeLength{4};

// START:encode
   std::string encode(const std::string& word) const {
// START_HIGHLIGHT
      return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
// END_HIGHLIGHT
   }
// END:encode

private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }
   
   std::string tail(const std::string& word) const {
      return word.substr(1);
   }

// START:encodedDigits
// START_HIGHLIGHT
   const std::string NotADigit{"*"};
// END_HIGHLIGHT

   std::string encodedDigits(const std::string& word) const {
      std::string encoding;
      for (auto letter: word) {
         if (isComplete(encoding)) break;

// START_HIGHLIGHT
         auto digit = encodedDigit(letter);
         if (digit != NotADigit && digit != lastDigit(encoding))
            encoding += digit;
// END_HIGHLIGHT
      }
      return encoding;
   }

   std::string lastDigit(const std::string& encoding) const {
// START_HIGHLIGHT
      if (encoding.empty()) return NotADigit;
// END_HIGHLIGHT
      return std::string(1, encoding.back());
   }
   // ...
// END:encodedDigits

   bool isComplete (const std::string& encoding) const {
      return encoding.length() == MaxCodeLength - 1; 
   }

public:
// START:encodedDigits
   std::string encodedDigit(char letter) const {
      const std::unordered_map<char, std::string> encodings {
         {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
         // ...
// END:encodedDigits
         {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                     {'s', "2"}, {'x', "2"}, {'z', "2"},
         {'d', "3"}, {'t', "3"},
         {'l', "4"},
         {'m', "5"}, {'n', "5"},
         {'r', "6"}
// START:encodedDigits
      };
      auto it = encodings.find(letter);
// START_HIGHLIGHT
      return it == encodings.end() ? NotADigit : it->second;
// END_HIGHLIGHT
   }
// END:encodedDigits

private:
   std::string zeroPad(const std::string& word) const {
      auto zerosNeeded = MaxCodeLength - word.length();
      return word + std::string(zerosNeeded, '0');
   }
// START:encode

// START_HIGHLIGHT
   std::string upperFront(const std::string& string) const {
      return std::string(1, 
            std::toupper(static_cast<unsigned char>(string.front())));
   }
// END_HIGHLIGHT
// END:encode
};
// END:Soundex

#endif
