#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string kalimat;
  char huruf;
  int low, high, mid;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  cin >> kalimat;

  // Input huruf yang ingin dicari
  cout << "Masukkan huruf yang ingin dicari: ";
  cin >> huruf;

  // Sort kalimat
  sort(kalimat.begin(), kalimat.end());

  // Inisialisasi variabel
  low = 0;
  high = kalimat.length() - 1;

  // Lakukan binary search
  while (low <= high) {
    mid = (low + high) / 2;

    // Jika huruf ditemukan
    if (kalimat[mid] == huruf) {
      cout << "Huruf " << huruf << " ditemukan pada indeks " << mid << endl;
      break;
    }

    // Jika huruf yang dicari lebih kecil dari huruf tengah
    else if (huruf < kalimat[mid]) {
      high = mid - 1;
    }

    // Jika huruf yang dicari lebih besar dari huruf tengah
    else {
      low = mid + 1;
    }
  }

  // Jika huruf tidak ditemukan
  if (low > high) {
    cout << "Huruf " << huruf << " tidak ditemukan" << endl;
  }

  return 0;
}