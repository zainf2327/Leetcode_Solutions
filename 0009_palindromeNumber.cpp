#include<iostream>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x==0) return true;
        if( x < 0||x % 10==0) return false;
        int rev= 0;  
        while(x>rev)  {             //reversing second half part of number and comapring it with first half part that is remaining.
            rev=(rev*10)+x%10;
            x/=10;
        }
        return (x==rev || x==rev/10); //for odd number of digits,the rev part would contain middle digit,which we want to skip,so then would truncate the last digit.
        
    }
};