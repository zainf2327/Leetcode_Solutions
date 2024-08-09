#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3)
            return false;
        bool contains_vowel = false, contains_consonant = false;
        for (int i = 0; i < n; i++) {
            if (word[i] == '@' || word[i] == '$' || word[i] == '#')
                return false;
            if (word[i] >= '0' && word[i] <= '9') {
                continue;
            }
            char temp = tolower(word[i]);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' ||
                temp == 'u') {
                contains_vowel = true;
            } else {
                contains_consonant = true;
            }
        }
        return (contains_vowel && contains_consonant);
    }
};