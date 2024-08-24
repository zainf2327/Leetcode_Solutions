#include <iostream>
#include <vector>
using namespace std;
class MyHashMap {
private:
    struct Node {
    public:
        int key;
        int value;
        Node* next;
        Node(int key, int value, Node* next = nullptr)
            : key(key), value(value), next(next) {}
        ~Node() {}
    };
    const int SIZE = 1007;
    vector<Node*> list;

public:
    MyHashMap() {
        list.resize(SIZE);
        for (auto& header : list) {
            header = new Node(-1, -1);
        }
    }

    void put(int K, int V) {
        int index = K % SIZE;
        Node* current = list[index];
        while (current->next) {
            if (current->next->key == K) {
                current->next->value = V;
                return;
            }
            current = current->next;
        }
        current->next = new Node(K, V);
    }

    int get(int K) {
        int index = K % SIZE;
        Node* ptr = list[index]->next; // head of linked list
        while (ptr) {
            if (ptr->key == K) {
                return ptr->value;
            }
            ptr = ptr->next;
        }
        return -1;
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
    ~MyHashMap() {
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
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */