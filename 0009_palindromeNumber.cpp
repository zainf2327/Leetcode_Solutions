#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        int num = x;
        unsigned int rev= 0.0;  // rev can be made unsigned int or long long int since reverse of signed int can be out of range of signed int but as number would be +ve only, so using unsigned int or long long would increase its range.
        while(num)  {
            rev=(rev*10)+num%10;
            num/=10;
        }
        return rev==x;
        
    }
};