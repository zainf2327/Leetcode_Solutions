#include <iostream>
using namespace std;
class Solution {
public:
    int numberOfChild(int n, int time) {
        int currentPosition = 0;
        int currentTime = 0;
        int direction = 1; //  1 means Forward , -1 means reverse
        while (currentTime != time) {
            if (currentPosition + direction >= n ||
                currentPosition + direction < 0) {
                direction *= -1;
            }
            currentPosition += direction;
            currentTime++;
        }
        return currentPosition;
    }
};