#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class RandomizedSet {
private:
    vector <int> list;
    unordered_map<int, int> hashMap;

public:
    RandomizedSet() {}
    ~RandomizedSet() {}

    bool insert(int val) {
        if (hashMap.count(val))
            return false;
        hashMap[val] = list.size();
        list.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!hashMap.count(val))
            return false;
        int index = hashMap[val];
        int last = list.back();
        list[index] = last;
        hashMap[last] = index;
        hashMap.erase(val);
        list.pop_back();
        return true;
    }

    int getRandom() {
        int index = rand() % list.size();
        return list[index];
    }
};
