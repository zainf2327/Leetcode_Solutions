#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfChild(int n, int time) {
        int fullRotations = time / (n - 1);
        int extraSteps = time % (n - 1);
        if (fullRotations % 2 == 0) {
            return extraSteps;
        } else {
            return n - 1 - extraSteps;
        }
    }
};