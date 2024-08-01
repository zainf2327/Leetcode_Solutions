#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int romanToInt(string s)    {
        unordered_map<char, short int> map;
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        int num = 0, n = s.size(), temp;
        for (int i = 0; i < n; i++)    {
            temp = map[s[i]];
            if (temp < map[s[i + 1]])
                num -= temp;
            else
                num += temp;
        }
        return num;
    }
};