#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
using namespace std;
class RandomizedCollection {
private:
    unordered_map<int, set<int>> map;
    vector<int> list;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        map[val].insert(list.size());
        list.push_back(val);
        return map[val].size() == 1;
    }

    bool remove(int val) {
        if (!map.count(val) || map[val].size() == 0)
            return false;
        int index = *map[val].rbegin();
        int last = list.back();
        list[index] = last;
        map[last].erase(list.size() - 1);
        map[last].insert(index);
        map[val].erase(index);
        list.pop_back();
        return true;
    }

    int getRandom() {
        int index = rand() % list.size();
        return list[index];
    }
    ~RandomizedCollection() {}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */