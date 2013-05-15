#ifndef Soundex_h
#define Soundex_h

#include <string>
#include <unordered_map>

class Soundex
{
public:
   static const size_t MaxCodeLength{4};

   std::string encode(const std::string& word) const {
      return zeroPad(upperFront(head(word)) + encodedDigits(tail(word)));
   }

private:
   std::string head(const std::string& word) const {
      return word.substr(0, 1);
   }
   
   std::string tail(const std::string& word) const {
      return word.substr(1);
   }

   const std::string NonEncodableCharacter{""};

   std::string encodedDigits(const std::string& word) const {
      std::string encoding;
      for (auto letter: word) {
         if (isComplete(encoding)) break;

         auto digit = encodedDigit(letter);
         if (digit != NonEncodableCharacter && digit != lastDigit(encoding))
            encoding += digit;
      }
      return encoding;
   }

   std::string lastDigit(const std::string& encoding) const {
      if (encoding.empty()) return "";
      return std::string(1, encoding.back());
   }

   bool isComplete (const std::string& encoding) const {
      return encoding.length() == MaxCodeLength - 1; 
   }

public:
// START:encodedDigit
   std::string encodedDigit(char letter) const {
      const std::unordered_map<char, std::string> encodings {
         {'b', "1"}, {'f', "1"}, {'p', "1"}, {'v', "1"},
         // ...
// END:encodedDigit
         {'c', "2"}, {'g', "2"}, {'j', "2"}, {'k', "2"}, {'q', "2"},
                     {'s', "2"}, {'x', "2"}, {'z', "2"},
         {'d', "3"}, {'t', "3"},
         {'l', "4"},
         {'m', "5"}, {'n', "5"},
         {'r', "6"}
// START:encodedDigit
      };
// START_HIGHLIGHT
      auto it = encodings.find(lower(letter));
// END_HIGHLIGHT
      return it == encodings.end() ? NonEncodableCharacter : it->second;
   }

private:
// START_HIGHLIGHT
   char lower(char c) const {
      return std::tolower(static_cast<unsigned char>(c));
   }
// END_HIGHLIGHT
// END:encodedDigit

   std::string zeroPad(const std::string& word) const {
      auto zerosNeeded = MaxCodeLength - word.length();
      return word + std::string(zerosNeeded, '0');
   }

   std::string upperFront(const std::string& string) const {
      return std::string(1, 
            std::toupper(static_cast<unsigned char>(string.front())));
   }
};

#endif
