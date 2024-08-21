#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int i) {
        vector<int> row(i + 1, 1);
        long cef = 1;
        for (int j = 1; j < i; j++) {
            cef = cef * (i - j + 1) / j;
            row[j] = cef;
        }
        return row;
    }
};
