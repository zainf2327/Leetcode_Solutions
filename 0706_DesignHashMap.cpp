#include <iostream>
#include<vector>
using namespace std;
class MyHashMap {
private:
    struct Node {
    public:
        int key;
        int value;
        Node* next;
        Node(int key, int value, Node* next = nullptr) : key(key), value(value), next(next) {}
        ~Node() {}
    };
    const int SIZE = 1000;
    vector<Node*> list;
public:
    MyHashMap()  {
        list.resize(SIZE,nullptr);
    }

    void put(int K, int V) {
        int index = K % SIZE;
        if (list[index] == nullptr) {
            list[index] = new Node(K, V);
        } else {
            Node* current = list[index];
            while (current->next != nullptr && current->key != K) {
                current = current->next;
            }
            if (current->key == K) {
                current->value = V; // Update value if key exists
            } else {
                current->next = new Node(K, V);
            }
        }
    }

    int get(int K) {
        int index = K % SIZE;
        Node* ptr = list[index];
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
        Node*current =list[index];
        if (current == nullptr) {
    
        } else if (current->key == K) {
            list[index] = current->next;
            delete current;    
        } else {
            while(current->next!=nullptr && current->next->key!=K)  {
                current=current->next;
            }
            if(current->next!=nullptr)  {
                Node*temp=current->next;
                current->next=current->next->next;
                delete temp;
            }
        }
    }
    ~MyHashMap()    {
        for(auto& head: list)   {
            while(head!=nullptr)    {
                Node* temp=head;
                head=head->next;
                delete temp;
            }
        }
    }
};