#include <iostream>
#include <stack>

using namespace std;

// Fungsi untuk mensortir stack
void sortStack(stack<int>& input) {
    stack<int> tempStack;

    while (!input.empty()) {
        // Ambil elemen teratas dari stack input
        int temp = input.top();
        input.pop();

        // Pindahkan elemen dari tempStack ke input sampai menemukan posisi yang benar untuk temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            input.push(tempStack.top());
            tempStack.pop();
        }

        // Temp ditempatkan di tempStack
        tempStack.push(temp);
    }

    // Pindahkan kembali elemen dari tempStack ke input (input sekarang terurut)
    while (!tempStack.empty()) {
        input.push(tempStack.top());
        tempStack.pop();
    }
}

int main() {
    stack<int> myStack;
    myStack.push(34);
    myStack.push(3);
    myStack.push(31);
    myStack.push(98);
    myStack.push(92);
    myStack.push(23);

    cout << "Sebelum diurutkan: ";
    stack<int> displayStack = myStack; // Salinan stack untuk menampilkan isi stack
    while (!displayStack.empty()) {
        cout << displayStack.top() << " ";
        displayStack.pop();
    }
    cout << endl;

    sortStack(myStack);

    cout << "Setelah diurutkan: ";
    while (!myStack.empty()) {
        cout << myStack.top() << " ";
        myStack.pop();
    }
    cout << endl;

    return 0;
}