#include <iostream>

// Struktur node dalam linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk membuat node baru
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Fungsi untuk menambahkan node ke akhir linked list
void appendNode(Node*& head, int value) {
    Node* newNode = createNode(value);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Fungsi untuk mencari node di tengah linked list
Node* findMiddleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Fungsi untuk menghapus node di tengah linked list
void deleteMiddleNode(Node*& head, int value) {
    Node* middleNode = findMiddleNode(head);
    if (middleNode == head) {
        head = head->next;
    } else {
        Node* current = head;
        while (current->next != middleNode) {
            current = current->next;
        }
        current->next = middleNode->next;
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);

    std::cout << "Linked List sebelum menghapus node di tengah: ";
    printList(head);

    deleteMiddleNode(head, 3);

    std::cout << "Linked List setelah menghapus node di tengah: ";
    printList(head);

    return 0;
}