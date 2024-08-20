#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string mail;
        int i;
        set<string> mp;
        for (string& email : emails) {
             i = 0;
             mail="";
            int n = email.size();
            while (email[i] != '@') {
                if (email[i] == '+') {
                    while(email[i]!='@')  {
                        i++;
                    }
                    break;
                }
                if (email[i] == '.') {
                    i++;
                    continue;
                }
                mail.push_back(email[i]);
                i++;
            }
            while(i<n)  {
                mail.push_back(email[i]);
                i++;
            }
            
            mp.insert(mail);
        }
        return mp.size();
    }
};