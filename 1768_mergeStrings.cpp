#include <iostream>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int ptr1 = 0, ptr2 = 0;
        string word(m + n, '0');
        int ptr = 0;
        while (ptr1 < m || ptr2 < n) {
            if (ptr1 < m) {
                word[ptr++] = word1[ptr1++];
            }
            if (ptr2 < n) {
                word[ptr++] = word2[ptr2++];
            }
        }
        return word;
    }
};