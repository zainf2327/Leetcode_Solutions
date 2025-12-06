#include <string>
using namespace std;
class Solution {
int minSteps(int i,int j,string& s)    {
    if(i>=j) return 0;
    if(s[i]==s[j])
        return minSteps(i+1,j-1,s);
    else 
        return 1+min(minSteps(i+1,j,s),minSteps(i,j-1,s));
}
public:
    int minInsertions(string s) {
        return  minSteps(0,s.size()-1,s);  
    }
};

// O(2^n) +O(n)