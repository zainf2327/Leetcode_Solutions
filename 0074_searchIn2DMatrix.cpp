#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();   // number of rows
        int n = matrix[0].size();  // size of each row
        int size = m * n;
        int l = 0, h = size - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            int r = mid / n;          // map each element to its row and column in 2D matrix
            int c = mid % n;
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                h = mid - 1;
            } else
                l = mid + 1;
        }
        return false;
    }
};