#include <iostream>
#include <vector>
using namespace std;
class MyHashSet {
private:
    struct Node {
    public:
        int key;
        Node* next;
        Node(int key, Node* next = nullptr) : key(key), next(next) {}
        ~Node() {}
    };
    const int SIZE = 1007;
    vector<Node*> list;

public:
    MyHashSet() {
        list.resize(SIZE);
        for (auto& header : list) {
            header = new Node(-1);
        }
    }

    void add(int K) {
        int index = K % SIZE;
        Node* current = list[index];
        while (current->next) {
            if (current->next->key == K) {
                return;
            }
            current = current->next;
        }
        current->next = new Node(K);
    }

    void remove(int K) {
        int index = K % SIZE;
        Node* current = list[index];
        while (current->next) {
            if (current->next->key == K) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }
    }

    bool contains(int K) {
        int index = K % SIZE;
        Node* ptr = list[index]->next;
        while (ptr) {
            if (ptr->key == K) {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
    ~MyHashSet() {
        Node* temp;
        for (auto& header : list) {
            while (header) {
                temp = header;
                header = header->next;
                delete temp;
            }
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */