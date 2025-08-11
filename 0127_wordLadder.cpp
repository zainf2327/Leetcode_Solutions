#include<vector>
#include<queue>
#include<string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
    unordered_set<string> visited(wordList.begin(),wordList.end());
       
        queue<pair<int, string>> q;
        q.push({1, beginWord});
        while (!q.empty()) {
            string curr = q.front().second;
            int cl = q.front().first;
            if (curr == endWord)
                return cl;
            q.pop();
            for (int i = 0; i < curr.length(); i++) {
                string temp = curr;
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (visited.count(temp)) {
                        q.push({cl + 1, temp});
                       visited.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

// TC: O(N*L*26)
// SC: O(N*L+N*L)