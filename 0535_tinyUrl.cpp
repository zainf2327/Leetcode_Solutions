#include <iostream>
#include <vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
private:
    const string NAME = "https://decentraldevelopers.com/";
    unordered_map<string, string> encodeMap;
    unordered_map<string, string> decodeMap;

public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        if (encodeMap.count(longUrl)) {
            return NAME + encodeMap[longUrl];
        }
        string shortUrl = to_string(encodeMap.size());
        encodeMap[longUrl] = shortUrl;
        decodeMap[shortUrl] = longUrl;
        return NAME + encodeMap[longUrl];
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl = shortUrl.substr(NAME.size());
        return decodeMap[shortUrl];
    }
};