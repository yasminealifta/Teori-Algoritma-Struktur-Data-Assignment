#include <iostream>
#include <unordered_set>

using namespace std;

// Definisi struktur node dari singly linked list
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Fungsi untuk menghapus node duplikat dari linked list
void removeDuplicates(Node* head) {
    if (head == nullptr) return;
    
    unordered_set<int> seen;
    Node* current = head;
    Node* prev = nullptr;
    
    while (current != nullptr) {
        // Jika data sudah terlihat sebelumnya, hapus node saat ini
        if (seen.find(current->data) != seen.end()) {
            prev->next = current->next;
            delete current;
        } else {
            // Jika data belum terlihat sebelumnya, tambahkan ke set
            seen.insert(current->data);
            prev = current;
        }
        current = prev->next;
    }
}

// Fungsi untuk mencetak linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Fungsi utama
int main() {
    // Membuat linked list: 10 -> 12 -> 11 -> 11 -> 12 -> 11 -> 10
    Node* head = new Node(10);
    head->next = new Node(12);
    head->next->next = new Node(11);
    head->next->next->next = new Node(11);
    head->next->next->next->next = new Node(12);
    head->next->next->next->next->next = new Node(11);
    head->next->next->next->next->next->next = new Node(10);

    cout << "Linked list before removing duplicates: ";
    printList(head);

    removeDuplicates(head);

    cout << "Linked list after removing duplicates: ";
    printList(head);

    // Menghapus semua node untuk menghindari memory leak
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}