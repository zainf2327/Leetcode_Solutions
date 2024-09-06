#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }
        vector<bool> prime(n, false);
        for (int i = 3; i < n; i += 2) {
            prime[i] = true;
        }
        prime[2] = true;
        int count = n / 2;
        for (int i = 3; i * i < n; i += 2) {
            if (prime[i]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (prime[j]) {
                        prime[j] = false;
                        count--;
                    }
                }
            }
        }

        return count;
    }
};