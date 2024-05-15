#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

class Queue {
private:
  Node* head;
  Node* tail;

public:
  Queue() {
    head = tail = nullptr;
  }

  bool isEmpty() {
    return head == nullptr;
  }

  void enqueue(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
      head = tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  int dequeue() {
    if (isEmpty()) {
      cout << "Antrian kosong!" << endl;
      return -1;
    }

    int front = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr) {
      tail = nullptr;
    }

    return front;
  }

  void peek() {
    if (isEmpty()) {
      cout << "Antrian kosong!" << endl;
      return;
    }

    cout << "Elemen depan: " << head->data << endl;
  }

  void display() {
    if (isEmpty()) {
      cout << "Antrian kosong!" << endl;
      return;
    }

    Node* current = head;
    cout << "Antrian: ";
    while (current != nullptr) {
      cout << current->data << " ";
      current = current->next;
    }
    cout << endl;
  }
};

int main() {
  Queue queue;

  // Menambahkan elemen ke antrian
  queue.enqueue(15);
  queue.enqueue(30);
  queue.enqueue(45);

  // Menampilkan isi antrian
  queue.display();

  // Mengambil elemen terdepan dari antrian
  int front = queue.dequeue();
  cout << "Elemen yang dihapus: " << front << endl;

  // Menampilkan isi antrian setelah penghapusan
  queue.display();

  // Mengintip elemen terdepan tanpa menghapusnya
  queue.peek();

  // Mengosongkan antrian
  while (!queue.isEmpty()) {
    queue.dequeue();
  }

  // Menampilkan isi antrian setelah pengosongan
  queue.display();

  return 0;
}