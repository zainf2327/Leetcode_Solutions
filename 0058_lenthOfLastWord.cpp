#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
       int n = s.size()-1,count=0;
        while(s[n]==' ') --n;
        while(n >= 0 && s[n]!=' '){
            count++;
            n--;
        }
        return count;  
    }
};