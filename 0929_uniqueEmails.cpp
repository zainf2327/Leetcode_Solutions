#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        string mail;
        int i, n;
        for (string& email : emails) {
            i = 0;
            mail = "";
            n = email.size();
            while (email[i] != '@') {
                if (email[i] == '+') {
                    while (email[i] != '@') {
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
            while (i < n) {
                mail.push_back(email[i]);
                i++;
            }

            email = mail;
        }
        sort(emails.begin(), emails.end());
        int count = 1;
        for (int i = 1; i < emails.size(); i++) {
            if (emails[i] != emails[i - 1]) {
                count++;
            }
        }
        return count;
    }
};
