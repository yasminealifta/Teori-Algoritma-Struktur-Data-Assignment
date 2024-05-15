#include <iostream>

using namespace std;

int main() 
{
  // Array untuk menyimpan nama-nama warga
  string nama[10] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Jumlah elemen dalam array
  int n = sizeof(nama) / sizeof(nama[0]);

  // Melakukan Bubble Sort
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      // Membandingkan dua elemen yang berdekatan
      if (nama[j] > nama[j + 1]) {
        // Menukar dua elemen jika tidak dalam urutan yang benar
        string temp = nama[j];
        nama[j] = nama[j + 1];
        nama[j + 1] = temp;
      }
    }
  }

  // Mencetak nama-nama yang sudah diurutkan
  cout << "Nama-nama warga yang sudah diurutkan: " << endl;
  for (int i = 0; i < n; i++) {
    cout << nama[i] << "\n";
  }

  cout << endl;

  return 0;
}