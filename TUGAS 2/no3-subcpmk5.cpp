#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* createLinkedList(int arr[], int n) {
  Node* head = NULL;
  Node* tail = NULL;

  for (int i = 0; i < n; i++) {
    Node* newNode = new Node;
    newNode->data = arr[i];
    newNode->next = NULL;

    if (head == NULL) {
      head = newNode;
      tail = newNode;
    } else {
      tail->next = newNode;
      tail = newNode;
    }
  }

  return head;
}

void printLinkedList(Node* head) {
  Node* temp = head;

  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

bool isPalindrome(Node* head) {
  // Menemukan tengah linked list
  Node* slow = head;
  Node* fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
  }

  // Mereverse bagian kedua dari linked list
  Node* prev = NULL;
  Node* curr = slow;
  Node* next;

  while (curr != NULL) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  // Membandingkan elemen dari awal dan akhir linked list
  Node* left = head;
  Node* right = prev;

  while (left != NULL && right != NULL) {
    if (left->data != right->data) {
      return false;
    }

    left = left->next;
    right = right->next;
  }

  return true;
}

int main() {
  int arr[] = {1, 2, 2, 1};
  int n = sizeof(arr) / sizeof(arr[0]);

  Node* head = createLinkedList(arr, n);

  cout << "Linked list: ";
  printLinkedList(head);

  bool isPalindrom = isPalindrome(head);

  if (isPalindrom) {
    cout << "Linked list adalah palindrom" << endl;
  } else {
    cout << "Linked list bukan palindrom" << endl;
  }

  return 0;
}