#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cariIndeksKata(const vector<string>& arr, const string& kata) {
    int kiri = 0;
    int kanan = arr.size() - 1;

    while (kiri <= kanan) {
        int tengah = kiri + (kanan - kiri) / 2;

        // Temukan indeks pertama di mana string tidak kosong
        while (arr[tengah] == "" && tengah >= kiri)
            tengah--;

        // Jika kita sampai di elemen yang tidak kosong, kita lakukan pencarian biner biasa
        if (tengah < kiri || arr[tengah] < kata)
            kiri = tengah + 1;
        else if (arr[tengah] > kata)
            kanan = tengah - 1;
        else
            return tengah;
    }
    return -1; // Jika tidak ditemukan
}

int main() {
    vector<string> arr = {"Adi", "", "", "", "bermain", "", "bola", "", "", "sedang"};
    string kata = "bola";
    int indeks = cariIndeksKata(arr, kata);
    if (indeks != -1)
        cout << "Output: " << indeks << endl;
    else
        cout << "Kata tidak ditemukan." << endl;
    
    return 0;
}