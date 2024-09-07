#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
#include <random>
using namespace std;

class Solution {
private:
    string getRandomAlphaNumericString(int length) {
        const string alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                "abcdefghijklmnopqrstuvwxyz"
                                "0123456789";
        random_device rd;        // Seed for the random number engine
        mt19937 generator(rd()); // Mersenne Twister random number generator
        uniform_int_distribution<> distr(0,alphanum.size() - 1); // Unifrom Distribution
        string randomStr;
        for (int i = 0; i < length; ++i) {
            randomStr +=
                alphanum[distr(generator)]; // Append a random character
        }

        return randomStr;
    }
    const string NAME = "https://decentraldevelopers.com/";
    const int LENGTH = 6;
    unordered_map<string, string> encodeMap;
    unordered_map<string, string> decodeMap;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encodeMap.count(longUrl)) {
            return NAME + encodeMap[longUrl];
        }
        string shortUrl;
        do {
            shortUrl = getRandomAlphaNumericString(LENGTH);
        } while (decodeMap.count(shortUrl));
        encodeMap[longUrl] = shortUrl;
        decodeMap[shortUrl] = longUrl;
        return NAME + encodeMap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl = shortUrl.substr(NAME.size(), LENGTH);
        return decodeMap[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));