#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int size = numbers.size(),complement;
        unordered_map<int, int> arrMap; // value,index
        for (int i=0;i<size;i++)  {
            complement = target-numbers[i];
            if(arrMap.count(complement))
               return {arrMap[complement]+1, i+1};
            arrMap[numbers[i]]=i;
        }
        

        return {};  //Return empty array if no pair is found that add to target
    }
};