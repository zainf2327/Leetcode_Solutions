#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int n = nums.size();
       unordered_map <int,int>count;
       for(int i =0;i<n;i++)  {
            count[nums[i]]++;
       }
       int threshold = n/2;
       for(auto pair: count)   {
            if(pair.second >threshold){
                return pair.first;
            }
        }

        return -1; // -1 if there is no majority element
    }

};