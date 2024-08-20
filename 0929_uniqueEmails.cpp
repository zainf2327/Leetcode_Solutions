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
        int count = 0;
        for (int i = 0; i < emails.size(); i++) {
            bool is_unique = true;
            for (int j = 0; j < i; j++) {
                if (emails[j] == emails[i]) {
                    is_unique = false;
                    break;
                }
            }
            if (is_unique) {
                count++;
            }
        }
        return count;
    }
};