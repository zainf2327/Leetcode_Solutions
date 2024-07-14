#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        int Max = INT_MAX / 10, Min = INT_MIN / 10;
        while (n) {

            if (rev > Max || rev < Min)  return 0;
            rev = (rev * 10) + (n % 10);
            n /= 10;
        }
        return rev;
    }
};
