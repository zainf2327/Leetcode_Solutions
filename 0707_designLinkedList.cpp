class MyLinkedList {
private:
    struct Node {
    public:
        int val;
        Node* next;
        Node(int val) : val(val), next(nullptr) {}
        ~Node() {}
    };
    Node* header;
    int size;

public:
    MyLinkedList() {
        header = new Node(-1);
        size = 0;
    }

    int get(int index) {
        int i = 0;
        Node* current = header->next;
        while (current) {
            if (i == index) {
                return current->val;
            }
            current = current->next;
            i++;
        }
        return -1;
    }

    void addAtHead(int val) {
        Node* temp = new Node(val);
        temp->next = header->next;
        header->next = temp;
        size++;
    }

    void addAtTail(int val) {
        Node* current = header;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(val);
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index < 0 || index > size)
            return;
        int i = 0;
        Node* current = header;
        while (current->next != nullptr) {
            if (i == index) {
                Node* temp = new Node(val);
                temp->next = current->next;
                current->next = temp;
                size++;
                return;
            }
            i++;
            current = current->next;
        }
        if (i == index) {
            current->next = new Node(val);
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= size)
            return;
        int i = 0;
        Node* current = header;
        while (current->next != nullptr) {
            if (i == index) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            i++;
            current = current->next;
        }
        size--;
    }
    ~MyLinkedList() {
        Node* temp;
        while (header) {
            temp = header;
            header = header->next;
            delete temp;
        }
    }
};

