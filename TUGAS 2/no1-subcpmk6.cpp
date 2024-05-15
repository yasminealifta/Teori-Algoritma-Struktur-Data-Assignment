#include <iostream>

using namespace std;

template <typename T>
class Stack {
private:
  // Array untuk menyimpan elemen stack
  T data[100];

  // Posisi elemen teratas
  int top;

public:
  // Konstruktor untuk menginisialisasi stack kosong
  Stack() {
    top = -1;
  }

  // Fungsi untuk mendorong elemen ke stack
  void push(T element) {
    if (isFull()) {
      cout << "Stack sudah penuh!" << endl;
      return;
    }

    top++;
    data[top] = element;
  }

  // Fungsi untuk mengambil elemen teratas dan menghapusnya dari stack
  T pop() {
    if (isEmpty()) {
      cout << "Stack kosong!" << endl;
      return -1;
    }

    T element = data[top];
    top--;
    return element;
  }

  // Fungsi untuk memeriksa apakah stack kosong
  bool isEmpty() {
    return top == -1;
  }

  // Fungsi untuk memeriksa apakah stack penuh
  bool isFull() {
    return top == 100 - 1;
  }

  // Fungsi untuk melihat elemen teratas tanpa menghapusnya
  T peek() {
    if (isEmpty()) {
      cout << "Stack kosong!" << endl;
      return -1;
    }

    return data[top];
  }
};

int main() {
  // Deklarasi stack dengan tipe data integer
  Stack<int> myStack;

  // Menambahkan elemen ke stack
  myStack.push(1);
  myStack.push(2);
  myStack.push(3);

  // Menampilkan elemen teratas
  cout << "Elemen teratas: " << myStack.peek() << endl;

  // Mengambil elemen dari stack
  cout << "Elemen yang dihapus: " << myStack.pop() << endl;

  // Memeriksa apakah stack kosong
  if (myStack.isEmpty()) {
    cout << "Stack kosong!" << endl;
  } else {
    cout << "Stack tidak kosong" << endl;
  }

  return 0;
}