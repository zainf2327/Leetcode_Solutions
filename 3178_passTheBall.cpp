#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfChild(int n, int time) {
        int N = 2*n -2;
        int T = time % N;
        if (T<n) {
            return T;
        } else {
            return N-T;
        }
    }
};