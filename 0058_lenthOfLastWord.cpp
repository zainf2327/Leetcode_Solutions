#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size(),count=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]==' ' && count==0) continue;
            if(s[i]!=' '){
                 count++;
            }
            else 
              return count;     
        }
        return count;
        
    }
};