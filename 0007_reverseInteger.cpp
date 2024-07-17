#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(long long int n) {
        int rev = 0;
        int Max = INT_MAX / 10, Min = INT_MIN / 10, rem;
        while (n) {
            rem = n % 10;
            if (rev > Max || rev == Max && rem > (INT_MAX % 10))
                return 0;
            if (rev < Min || rev == Min && rem < (INT_MIN % 10))
                return 0;
            rev = (rev * 10) + rem;
            n /= 10;
        }
        return rev;
    }
};
