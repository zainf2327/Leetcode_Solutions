#include <vector>
#include <string>
using namespace std;
class Solution {
int f(int i,int j,string& s,string& t)  {
    if(i==0 && j==0) return 0;
    if(i==0 &&j>0) return j;
    if(j==0 && i>0) return i;
    if(s[i-1]==t[j-1])  {
        return f(i-1,j-1,s,t);
    }
    else {
        return 1+min(f(i,j-1,s,t),f(i-1,j,s,t));
    }
}
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        return f(n,m,word1,word2);
        
    }
};

// TC: O(2^(m+n))
//SC: O(m+n)