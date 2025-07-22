#include<vector>
#include<algorithm>
using namespace std;


class Solution {
   public:
    int rowWithMax1s(vector<vector<int>>& mat) {
        int rowIndex = -1;
        int maxOnes = 0;
        int m = mat[0].size();
        for (int i = 0; i < mat.size(); i++) {
            int firstOneIndex = lower_bound(mat[i].begin(),mat[i].end(), 1) - mat[i].begin();
            int countOnes = m - firstOneIndex;
            if (countOnes > maxOnes) {
                rowIndex = i;
                maxOnes = countOnes;
            }
        }
        return rowIndex;
    }
   
};