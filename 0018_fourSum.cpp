#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<int>temp;
        set <vector<int>> rec;
        int n =nums.size();
        for(int i =0;i<n-3;i++) {
            for(int j=i+1;j<n-2;j++)    {
                for(int k =j+1;k<n-1;k++)   {
                    for(int l =k+1;l<n;l++) {
                        long long int sum= nums[i] + nums[j];
                        sum+=nums[k];
                        sum+=nums[l];
                        if(sum==target) {
                            temp={nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            rec.insert(temp);
                        }
                    }
                }
            }
        }

        vector<vector<int>> res (rec.begin(),rec.end());
        return res;
    }
};
