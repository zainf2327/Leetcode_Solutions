#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
void buildPaths ( unordered_map<string, vector<string>>& parent,string word,string beginWord,vector<vector<string>>& paths,vector<string>list)    {
    list.push_back(word);
    if(word==beginWord){
        paths.push_back(list);
        return;
    }
   
    for(auto& p:parent[word])   {
        buildPaths(parent,p,beginWord,paths,list);
    }
}
public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> isPresent(wordList.begin(), wordList.end());
        if(!isPresent.count(endWord)) return {};
        unordered_map<string, int> steps; //({word,steps to reach it});
        unordered_map<string, vector<string>> parent;
        queue<string> q;
        q.push(beginWord);
        parent[beginWord];
        steps[beginWord] = 1;
        bool isFound = false;
        while (!q.empty() && !isFound) {
            int size = q.size(); // number of words in current level

            while (size--) {
                string curr = q.front();
                if (curr == endWord)
                    isFound = true;
                q.pop();

                for (int i = 0; i < curr.length(); i++) {
                    string temp = curr;
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (temp[i] == c)
                            continue;
                        temp[i] = c;
                        if (!isPresent.count(temp))
                            continue;
                        if (!steps.count(temp)) {
                            steps[temp] = steps[curr] + 1;
                            parent[temp].push_back(curr);
                            q.push(temp);
                        } else if (steps[temp] == steps[curr] + 1) {
                            parent[temp].push_back(curr);
                        }
                    }
                }
            }
        }
        if(!isFound) return {};
        vector<vector<string> >paths;
        buildPaths(parent,endWord,beginWord,paths,{});
        for(auto& path:paths)   {
            reverse(path.begin(),path.end());
        }
        return paths;
        
    }
};
//TC: O(N*L*26+P*L) P*L can be quite bigger than normally dfs because we are not marking any word visited we have to visit every path P that has the average length of L