# <h1 align="center">TUGAS TEORI STRUKTUR DATA</h1>
<p align="center">Yasmine Alifta</p>

## CPMK 2 – SubCPMK 2

### 1. Terdapat tiga algoritma sorting yang umum digunakan yakni, Bubble Sort, Selection Sort, dan Merge Sort. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

JAWAB :

1. Bubble Sort

Bubble sort bekerja dengan cara membandingkan elemen pertama dengan elemen berikutnya dalam array, dan jika elemen pertama lebih besar dari elemen berikutnya, maka mereka diganti. Proses ini dilakukan secara berulang hingga akhir array. 

Best Case: O(n) - Karena dalam kasus terbaik, array sudah terurut dan tidak perlu dibandingkan lagi.

Worst Case: O(n^2) - Karena dalam kasus terburuk, array tidak terurut dan harus dibandingkan secara berulang hingga akhir array.

2. Selection Sort

Selection sort bekerja dengan cara memilih elemen terkecil dalam array dan menggantikan elemen pertama dengan elemen terkecil. Proses ini dilakukan secara berulang hingga akhir array. 

Best Case: O(n^2) - Karena dalam kasus terbaik, array tidak terurut dan harus dibandingkan secara berulang hingga akhir array.

Worst Case: O(n^2) - Karena dalam kasus terburuk, array tidak terurut dan harus dibandingkan secara berulang hingga akhir array.

3. Merge sort

Merge sort bekerja dengan cara membagi array menjadi dua bagian yang lebih kecil, kemudian mengurutkan masing-masing bagian, dan akhirnya menggabungkan bagian-bagian yang telah diurutkan. 

Best Case: O(n log n) - Karena dalam kasus terbaik, array dapat dibagi secara efisien dan diurutkan dengan cara yang efektif.

Worst Case: O(n log n) - Karena dalam kasus terburuk, array tidak terurut dan harus dibagi dan diurutkan secara berulang hingga akhir array.

### 2. Buatlah fungsi dari salah satu algoritma sorting pada soal nomor 1, dan berikan penjelasan pada program tersebut 

JAWAB :

```C++
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
```

Program di atas adalah algoritma Bubble Sort untuk mengurutkan array nama-nama warga Pak RT. Algoritma bubble sort bekerja dimulai dengan perulangan for pertama untuk memastikan semua elemen dibandingkan. Kemudian perulangan kedua digunakan untuk membandingkan elemen-elemen yang berdekatan dan dua elemen yang berdekatan akan dibandingkan. Jika elemen sebelah kiri lebih besar dari elemen sebelah kanan, maka kedua elemen ditukar sementara menggunakan temp. Setelah pengurutan selesai, array nama akan dicetak menggunakan perulangan for dan menggunakan fungsi cout untuk menampilkannya. Setelah program berjalan dengan baik dan benar, maka program akan mengembalikan nilai 0. Kompleksitas waktu algoritma Bubble Sort adalah O(n^2), di mana n adalah jumlah elemen dalam array. Hal ini berarti bahwa waktu yang dibutuhkan untuk mengurutkan array akan meningkat secara kuadrat dengan bertambahnya jumlah elemen. Pada program tersebut memiliki array dengan 10 elemen, maka akan membutuhkan waktu 100 langkah untuk mengurutkan array tersebut.

#### Output :

![Screenshot 2024-05-15 095613](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/e39c7282-1f42-4d1b-94b9-492d048a2f1d)

#### Full code :
![Screenshot 2024-05-15 095626](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/a0037c07-33e6-4086-9181-57cc77fca4b6)

### 3. Tulislah sebuah fungsi untuk mensorting dan mengecek dua buah array of strings, sehingga menghasilkan “anagram” dan “tidak anagram” 

JAWAB :

```C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string str1, string str2) {
  // Konversi string ke huruf kecil
  transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
  transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

  // Urutkan kedua string
  sort(str1.begin(), str1.end());
  sort(str2.begin(), str2.end());

  // Bandingkan kedua string yang telah diurutkan
  if (str1 == str2) {
    return true; // Merupakan anagram
  } else {
    return false; // Bukan anagram
  }
}

int main() {
  // Input string1 dan string2
  string string1, string2;
  cout << "Masukkan string 1: ";
  cin >> string1;
  cout << "Masukkan string 2: ";
  cin >> string2;

  // Periksa apakah string1 dan string2 anagram
  if (isAnagram(string1, string2)) {
    cout << string1 << " dan " << string2 << " adalah anagram." << endl;
  } else {
    cout << string1 << " dan " << string2 << " bukan anagram." << endl;
  }

  return 0;
}
```

#### Output :
![Screenshot 2024-05-15 100233](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/0f81d8d8-61e0-4eaf-bc8e-3f7834e7ea07)
![Screenshot 2024-05-15 100241](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/a7e24a1d-b1b4-4263-95d2-fbd28ffc7cfa)

#### Full code:
![Screenshot 2024-05-15 095931](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/33909d65-435a-48f2-9d8e-ab77e7bc32da)

### 4. Tulislah sebuah fungsi program dengan asumsi sebagai berikut:
### Terdapat dua buah sorted array A dan B yang memiliki tipe data sama, dimana array A memiliki indeks yang cukup untuk menampung array B. Gabungkan array B kedalam array A, kemudian urutkan array tersebut! 

JAWAB :

```C++
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
```

#### Output :
![Screenshot 2024-05-15 100526](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/3aa937e7-693a-49d6-aac7-87e9aae71869)

#### Full code:
![Screenshot 2024-05-15 100501](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/87e093e7-8970-4d21-b782-aefe546a41ec)

## CPMK 2 – SubCPMK 3

### 1. Terdapat dua algoritma searching yang umum digunakan yakni, Binary Search dan Linear Search. Berikan penjelasan alur dari masing-masing algoritma tersebut, dan jelaskan runtime dari best case dan worst case masing-masing algoritma! 

JAWAB :

1. Binary Search

Binary Search adalah algoritma pencarian yang efisien untuk menemukan elemen spesifik dalam array yang telah diurutkan dengan cara membagi interval pencarian menjadi dua bagian secara terus-menerus hingga elemen target ditemukan. Algoritma mulai dengan mendefinisikan interval pencarian sebagai array yang lengkap. Lalu, algoritma menghitung indeks tengah dari interval tersebut. Kemudian algoritma membandingkan elemen di indeks tengah dengan elemen target. Jika elemen target ditemukan di indeks tengah, algoritma mengembalikan indeks tersebut. Jika elemen target tidak ditemukan di indeks tengah, algoritma mengurangi interval pencarian menjadi setengah. Hal ini dilakukan dengan menyesuaikan indeks awal dan akhir menjadi setengah bawah atau setengah atas dari interval sebelumnya, tergantung apakah elemen target lebih kecil atau lebih besar dari elemen tengah. Proses tersebut diulangi hingga elemen target ditemukan atau interval pencarian menjadi kosong, yang menunjukkan bahwa elemen tidak ada dalam array.

Best Case: Kompleksitas waktu terbaik dari Binary Search adalah O(1), yang terjadi ketika elemen target ditemukan pada perbandingan pertama (elemen yang dicari berada di tengah array pada iterasi pertama).

Worst Case: Kompleksitas waktu terburuk dari Binary Search adalah O(log n), yang terjadi ketika elemen target berada di akhir array dan algoritma harus mencari melalui array yang lengkap.

2. Linear Search

Linear Search adalah algoritma yang sederhana yang memeriksa setiap elemen dalam daftar secara berurutan hingga menemukan cocok atau menghabiskan daftar. Algoritma mulai dengan mengatur variabel untuk mengikuti indeks elemen target dalam daftar. Algoritma melakukan iterasi melalui setiap elemen dalam daftar, mulai dari elemen pertama. Untuk setiap elemen, algoritma memeriksa apakah elemen tersebut cocok dengan elemen target. Jika elemen tersebut cocok dengan elemen target, algoritma mengembalikan indeks elemen tersebut. Jika elemen tersebut tidak cocok dengan elemen target, algoritma melanjutkan ke elemen berikutnya dalam daftar. Jika algoritma menghabiskan daftar tanpa menemukan elemen target, algoritma mengembalikan nilai yang menunjukkan elemen tidak ditemukan.

Best Case: Kompleksitas waktu terbaik dari Linear Search adalah O(1), yang terjadi ketika elemen target berada di posisi pertama dalam array.

Worst Case: Kompleksitas waktu terburuk dari Linear Search adalah O(n), yang terjadi ketika elemen target berada di posisi terakhir dalam daftar dan algoritma harus memeriksa setiap elemen secara berurutan.

### 2. Buatlah fungsi dari salah satu algoritma searching pada soal nomor 1, dan berikan penjelasan pada program tersebut 

JAWAB :

```C++
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
```

Program diatas adalah program untuk mencari sebuah huruf pada sebuah kalimat yang diinputkan oleh user menggunakan binary search. Program akan meminta user untuk memassukkan kalimat menggunakan fungsi cout dan menyimpannya kedalam variabel kalimat menggunakan fungsi cin. Kemudian user akan diminta untuk memasukkan satu huruf yang akan dicari menggunakan fungsi cout dan menyimpannya di variabel huruf menggunakan fungsi cin. Untuk melakukan pencarian sebuah huruf dengan binary search harus melakukan pengurutan terlebih dahulu, disini kalimat yang telah dimasukkan tadi diurutkan secara ascending menggunakan fungsi sort. Untuk melakukan proses binary search perlu melakukan pendeklarasian variabel. Low dideklarasikan untuk menandai indeks awal pencarian, high dideklarasikan untuk menandai indeks akhir pencarian, dan mid dideklarasikan untuk menandai indeks tengah. Pada saat melakukan perulangan binary search, program akan bekerja dengan membagi menjadi dua bagian sama besar pada setiap iterasi, kemudian program akan membandingkan huruf yang ingin dicari dengan huruf pada tengah kalimat. jika huruf yang ingin dicari sama dengan huruf pada tengah kalimat, maka pencarian selesai. Jika huruf yang ingin dicari lebih besar dari huruf pada tengah kalimat, maka cari pada bagian kanan kalimat. Jika huruf yang ingin dicari lebih kecil dari huruf tengah pada kalimat, maka cari pada bagian kiri kalimat. Jika perulangan selesai dan huruf tidak ditemukan, maka program akan mencetak pesan bahwa huruf tidak ditemukan. Jika perulangan selesai dan huruf ditemukan, maka program akan mencetak pesan bahwa huruf tersebut ditemukan beserta letak index nya. Setelah program selesai berjalan dengan baik maka program tersebut akan mengembalikan nilai 0.

#### Output :
![Screenshot 2024-05-15 100909](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/3e369d9e-0bd4-4d03-b28b-5f6bd828ac95)

#### Full code:
![Screenshot 2024-05-15 100800](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/455e1e32-2304-43df-94c3-2c1f5942d9c1)

### 3. Tulislah sebuah fungsi program dengan kondisi sebagai berikut:
### Terdapat sebuah sorted array of strings yang mana terdapat string kosong diantaranya, carilah lokasi/indeks dari kata yang dicari! 

JAWAB :

```C++
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
```

#### Output :
![Screenshot 2024-05-15 101218](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/0dee5a7f-1e2d-4025-99de-53dbafebd021)

#### Full code:
![Screenshot 2024-05-15 101204](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/2362c86c-442f-404a-a1f6-d53b675b8f1a)

## CPMK 2 – SubCPMK 4

### 1. Berikan penjelasan dari struct dan buatlah sebuah contoh program dari struct!

JAWAB :

Struct adalah tipe data bentukan yang terdiri dari kumpulan tipe data lain. Struct mirip seperti array, tapi struct bisa memiliki nama dan dapat digunakan sebagai variabel. 

```C++
#include <iostream>

using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku[5];
    string pengarang[5];
    string penerbit[5];
    int tebalHalaman[5];
    int hargaBuku[5];
};

int main() {
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku[0] = "Ayah";
    favorit.judulBuku[1] = "Harry Potter and the Order of Phoenix";
    favorit.judulBuku[2] = "Percy Jackson and the Lightning Thief";
    favorit.judulBuku[3] = "Delirium";
    favorit.judulBuku[4] = "Hujan";

    favorit.pengarang[0] = "Andrea Hirata";
    favorit.pengarang[1] = "J.K. Rowlings";
    favorit.pengarang[2] = "Rick Riordan";
    favorit.pengarang[3] = "Lauren Oliver";
    favorit.pengarang[4] = "Tere Liye";

    favorit.penerbit[0] = "Bentang Pustaka";
    favorit.penerbit[1] = "Gramedia Pustaka Utama";
    favorit.penerbit[2] = "Puffin Books";
    favorit.penerbit[3] = "Mizan Fantasi";
    favorit.penerbit[4] = "Gramedia Pustaka Utama";

    favorit.tebalHalaman[0] = 412;
    favorit.tebalHalaman[1] = 1200;
    favorit.tebalHalaman[2] = 377;
    favorit.tebalHalaman[3] = 515;
    favorit.tebalHalaman[4] = 320;

    favorit.hargaBuku[0] = 79000;
    favorit.hargaBuku[1] = 189000;
    favorit.hargaBuku[2] = 148000;
    favorit.hargaBuku[3] = 99000;
    favorit.hargaBuku[4] = 90000;

    // Menampilkan informasi buku favorit 
    cout << "\t\t\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku ke-" << i + 1 << endl;
        cout << "\t\tJudul Buku : " << favorit.judulBuku[i] << endl;
        cout << "\t\tPengarang : " << favorit.pengarang[i] << endl;
        cout << "\t\tPenerbit : " << favorit.penerbit[i] << endl;
        cout << "\t\tTebal Halaman: " << favorit.tebalHalaman[i] << " halaman" << endl;
        cout << "\t\tHarga Buku : Rp " << favorit.hargaBuku[i] << endl;
        cout << endl;
    }

    return 0;
}
```

#### Output :
![Screenshot 2024-05-15 102220](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/b090fbb9-437d-43f0-9a19-935b5ad0d2e4)
![Screenshot 2024-05-15 102250](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/f1e27f45-7fbb-4ebf-9580-3152e3e51664)

#### Full code:
![Screenshot 2024-05-15 102131](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/183b3d53-1ca0-48fa-9690-6b7bff71b531)

## CPMK 2 – SubCPMK 5

### 1. Buatlah sebuah fungsi program untuk menghilangkan duplikasi data pada unsorted linked list (single atau double atau circular)

JAWAB :

unsorted single linked list

```C++
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
```

#### Output :
![Screenshot 2024-05-15 102722](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/a8706bc2-43d9-46ae-ab3d-ad21c4492fb5)

#### Full code:
![Screenshot 2024-05-15 102702](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/3f3f3e93-d223-40f0-8f13-7fbf5a60e477)

### 2. Buatlah sebuah algoritma dan fungsi program untuk menghapus node di tengah single linked list! 

JAWAB :

Algoritma : 

-Inisialisasi head sebagai nullptr.

-Tambahkan node dengan nilai 1 hingga 5 ke linked list (appendNode).

-Cetak "Linked List sebelum menghapus node di tengah" dan linked list (printList).

-Hapus node di tengah linked list (deleteMiddleNode).

-Cetak "Linked List setelah menghapus node di tengah" dan linked list (printList).

-Buat dan kembalikan node baru dengan nilai input dan next nullptr.

-Buat node baru.

-Jika head kosong, set ke node baru.

-Jika tidak, iterasi ke node terakhir dan tambahkan node baru di akhir.

-Inisialisasi slow dan fast sebagai head.

-Iterasi: slow maju satu langkah, fast maju dua langkah.

-Kembalikan slow (node tengah).

-Temukan node tengah (findMiddleNode).

-Jika node tengah adalah head, set head ke head->next.

-Jika tidak, iterasi ke node sebelum node tengah dan set next-nya.

-Iterasi dan cetak data setiap node.

-Cetak baris baru.

Fungsi :

```C++
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
```

#### Output :

![Screenshot 2024-05-15 103304](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/9a637b2a-78de-4043-aea9-94eb3eaab81a)

#### Full code:
![Screenshot 2024-05-15 103247](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/e97a5a97-299b-4f1b-8c64-18baa87cb6ff)

### 3. Buatlah sebuah program untuk mengecek apakah linked list adalah sebuah palindrom! 

JAWAB :

```C++
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
```

#### Output :
![Screenshot 2024-05-15 103339](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/e1d54e1e-e8eb-422a-a10f-72261d739f65)

#### Full code:
![Screenshot 2024-05-15 103317](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/3b2ff13b-5f56-410b-bbc5-2f1dd51e14b1)

## CPMK 2 – SubCPMK 6

### 1. Tulislah sebuah program dari operasi stack seperti pop, push, isEmpty, isFull, dll(min 5)! 

JAWAB :

```C++
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
```

#### Output :
![Screenshot 2024-05-15 103824](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/af53e140-d4c4-46b8-b44b-f61e07ea8f7d)

#### Full code:
![Screenshot 2024-05-15 103809](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/f17a0b93-c53a-44bd-86a0-695f2e1acc0d)

### 2. Tulislah sebuah program untuk mensortir sebuah stack, sehingga item dengan nilai terkecil menjadi top pada stack tersebut! Diperbolehkan menggunakan tambahan temporary stack, namun tidak diperbolehkan untuk menyalin dari struktur data yang lain seperti array.  Program stack yang dibuat dapat menggunakan operasi stack seperti push, pop, peek, dan isEmpty.

JAWAB :

```C++
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
```

#### Output :
![Screenshot 2024-05-15 103849](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/e4217ebc-69e5-442b-a241-6c811d005a13)

#### Full code:
![Screenshot 2024-05-15 103835](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/9fe245a7-acfa-4593-9365-bf242f062a86)
## CPMK 2 – SubCPMK 7

### 1. Tulislah sebuah program dari operasi queue seperti enqueue/add, dequeue/remove, isEmpty, isFull, dll(min 5)! 

JAWAB :

```C++
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
```

#### Output :
![Screenshot 2024-05-15 104618](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/760623ea-dc36-404a-8e8d-37f38963f1d9)

#### Full code:
![Screenshot 2024-05-15 104554](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/bbaddddc-8289-455a-8b7f-9829187f51a3)

### 2. Sebuah selter hewan terlantar, yang mana hanya menerima kucing dan anjing, menerapkan konsep “first in, first out” dalam proses adopsi. Orang-orang yang hendak mengadopsi harus mengikuti aturan berikut:  1. mengadopsi hewan yang paling “tua” (berdasarkan waktu masuk ke selter) dan tidak dapat memilih kucing atau anjing; 2. memilih antara kucing atau anjing, namun akan menerima yang paling tua. Buatlah data struktur untuk mengimplementasikan kondisi tersebut, silahkan menggunakan beberapa operasi queue seperti enquee, dequeueAny, dequeueDog, dan dequeueCat. 

JAWAB :

```C++
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class AnimalShelter {
private:
    queue<pair<string, string>> cats; // Queue untuk kucing dengan pasangan (nama, waktu masuk)
    queue<pair<string, string>> dogs; // Queue untuk anjing dengan pasangan (nama, waktu masuk)
    string timestamp; // Penanda waktu masuk untuk setiap hewan

public:
    AnimalShelter() {
        timestamp = "0"; // Inisialisasi waktu masuk
    }

    void enqueue(string animalType, string animalName) {
        timestamp; // Update timestamp
        if (animalType == "cat") {
            cats.push({animalName, timestamp}); // Tambah kucing ke dalam queue
        } else if (animalType == "dog") {
            dogs.push({animalName, timestamp}); // Tambah anjing ke dalam queue
        }
    }

    pair<string, string> dequeueAny() {
        if (cats.empty() && dogs.empty()) {
            return {"", ""}; // Return empty pair jika tidak ada hewan di dalam shelter
        } else if (cats.empty()) {
            pair<string, string> dog = dogs.front(); // Dequeue anjing jika tidak ada kucing
            dogs.pop();
            return dog;
        } else if (dogs.empty()) {
            pair<string, string> cat = cats.front(); // Dequeue kucing jika tidak ada anjing
            cats.pop();
            return cat;
        } else {
            // Jika terdapat kucing dan anjing, dequeue yang lebih lama
            if (cats.front().second < dogs.front().second) {
                pair<string, string> cat = cats.front();
                cats.pop();
                return cat;
            } else {
                pair<string, string> dog = dogs.front();
                dogs.pop();
                return dog;
            }
        }
    }

    string dequeueCat() {
        if (!cats.empty()) {
            string catName = cats.front().first;
            cats.pop();
            return catName;
        } else {
            return ""; // Return empty string jika tidak ada kucing di dalam shelter
        }
    }

    string dequeueDog() {
        if (!dogs.empty()) {
            string dogName = dogs.front().first;
            dogs.pop();
            return dogName;
        } else {
            return ""; // Return empty string jika tidak ada anjing di dalam shelter
        }
    }
};

int main() {
    AnimalShelter shelter;

    shelter.enqueue("cat", "Whiskers");
    shelter.enqueue("dog", "Buddy");
    shelter.enqueue("cat", "Fluffy");
    shelter.enqueue("dog", "Max");

    cout << "Adopted: " << shelter.dequeueAny().first << endl; // Whiskers atau Buddy
    cout << "Adopted cat: " << shelter.dequeueCat() << endl; // Fluffy
    cout << "Adopted dog: " << shelter.dequeueDog() << endl; // Max

    return 0;
}
```

#### Output :
![Screenshot 2024-05-15 105310](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/75da042a-0fd4-45cd-aae5-be6a28633a38)

#### Full code:
![Screenshot 2024-05-15 105035](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/ba574415-7a61-4c06-b027-b0f6f4d57808)

