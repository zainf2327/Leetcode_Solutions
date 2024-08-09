#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int sign = 1;
        int i = 0;
        while(i < n && s[i] == ' ') {   // Ignoring any blank spaces(if any)
              i++;
        }
        if (i < n && s[i] == '-')  {    // Determining the sign of number(+ve if not given)
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            sign = 1;
            i++;
        }
        long  num = 0;
        while(i < n)  {
            if(!(s[i] >= '0' && s[i] <= '9'))   break;     // breaking loop as soon as non-numeric character is encountered(if any)
            num = (num*10) + (s[i]-'0');
            if(num > INT_MAX ) {
                if(sign==1 ) return INT_MAX;
                if(sign==-1 ) return INT_MIN;
            }             
            i++;
        }
        
        return num*sign;                     // sign will  assign magnitude to the num.
    }
};