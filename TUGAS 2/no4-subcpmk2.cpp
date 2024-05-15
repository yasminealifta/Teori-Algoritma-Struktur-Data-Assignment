#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void mergeSortedArrays(vector<int>& A, const vector<int>& B) {
    // Menggabungkan array B ke dalam array A
    A.insert(A.end(), B.begin(), B.end());
    
    // Mengurutkan array A setelah penggabungan
    sort(A.begin(), A.end());
}

int main() {
    // Contoh penggunaan fungsi mergeSortedArrays
    vector<int> A = {1, 3, 5, 7};
    vector<int> B = {2, 4, 6};

    mergeSortedArrays(A, B);

    // Mencetak hasil gabungan yang telah diurutkan
    cout << "Array setelah penggabungan dan pengurutan: ";
    for (int num : A) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}