# <h1 align="center">TUGAS 3</h1>
<p align="center">Yasmine Alifta</p>

## SOAL
### 1. Berikan penjelasan dan contoh program(beserta penjelasan alur program) dari masing-masing materi struktur data berikut:

a. Priority Queue

b. Hash Table

c. Rekursif

d. Graph & Tree

## JAWAB

a. PRIORITY QUEUE

Priority queue adalah sistem antrian yang mendahulukan elemen berdasarkan tingkat urgensinya, berbeda dengan antrian biasa yang dilayani berdasarkan urutan kedatangan. Implementasinya menggunakan struktur data "heap" untuk memastikan elemen dengan prioritas tertinggi dilayani terlebih dahulu dengan efisien [1].

```C++
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Compare {
    bool operator()(int a, int b) {
        return a < b;
    }
};

int main() {

    priority_queue<int, vector<int>, Compare> pq;

    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);
    pq.push(1);

    cout << "Priority Queue elements: ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
```


Program diawali dari struct Compare mendefinisikan operator fungsi () yang membandingkan dua integer, yang mana elemen dengan nilai lebih besar akan dianggap memiliki prioritas lebih tinggi, karena a < b akan mengembalikan true jika a lebih kecil dari b. Pada fungsi main, deklarasi pq sebagai priority queue yang menyimpan integer, menggunakan vector int sebagai kontainer internal, dan Compare sebagai komparator untuk menentukan urutan prioritas. Lima elemen ditambahkan ke priority queue: 10, 30, 20, 5, dan 1. Elemen-elemen ini akan disimpan dalam urutan sehingga elemen terbesar selalu berada di puncak. Kemudian program mencetak elemen-elemen dari priority queue satu per satu. Selama priority queue tidak kosong, elemen dengan prioritas tertinggi (elemen terbesar dalam hal ini) diambil menggunakan pq.top() dan kemudian dihapus dari queue dengan pq.pop(). Setelah program selesai berjalan dengan baik, program akan mengemballikan nilai 0. Output dari program ini adalah "Priority Queue elements: 30 20 10 5 1", yang mencerminkan urutan elemen berdasarkan prioritas menurun yang telah ditentukan.

#### Output:
![Screenshot 2024-06-20 201604](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/3d1fe0ff-1472-474b-9826-a7d357cc9d56)


b. HASH TABLE

Hash Table adalah struktur data yang digunakan untuk memetakan kunci (keys) ke nilai-nilai (values) secara efisien, memungkinkan akses cepat ke data menggunakan fungsi hash yang mengubah kunci menjadi indeks. Salah satu aspek penting dalam hash table adalah penanganan tabrakan (collision handling), di mana beberapa teknik seperti chaining dan open addressing digunakan untuk menangani tabrakan kunci. Pemilihan teknik ini mempengaruhi kinerja dan efisiensi hash table. Hash table banyak digunakan dalam berbagai aplikasi, termasuk basis data dan struktur data internal dalam bahasa pemrograman, untuk mengimplementasikan algoritma pencarian dan pengurutan secara efisien [2].

```C++
#include <iostream>
#include <list>
#include <vector>

using namespace std;

class HashTable {
private:
    int daftar;
    vector<list<int>> table;

    int hashFunction(int key) {
        return key % daftar;
    }

public:
    HashTable(int size) : daftar(size) {
        table.resize(daftar);
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    void displayHashTable() {
        for (int i = 0; i < daftar; ++i) {
            cout << "Daftar " << i << ": ";
            for (const auto& key : table[i]) {
                cout << key << " ";
            }
            cout << "\n";
        }
    }
};

int main() {
    HashTable ht(7);

    ht.insertItem(10);
    ht.insertItem(20);
    ht.insertItem(15);
    ht.insertItem(7);
    ht.insertItem(8);

    cout << "Hash Table contents:\n";
    ht.displayHashTable();

    cout << "\nDeleting key 20\n";
    ht.deleteItem(20);

    cout << "Hash Table contents after deletion:\n";
    ht.displayHashTable();

    return 0;
}
```

Program dimulai dengan kelas HashTable yang memiliki dua anggota privat yaitu, daftar (dengan tipe integer) untuk menyimpan ukuran tabel hash; table (vector yang berisi list integer) untuk menyimpan elemen-elemen dalam tabel hash. Dalam kelas tersebut terdapat beberapa fungsi yaitu; hashFunction(int key) untuk menghitung indeks dalam tabel hash menggunakan operasi modulus (key % daftar) dengan mengambil kunci (key) sebagai argumen dan mengembalikan indeks hasil dari operasi key % daftar; HashTable(int size) sebagai konstruktor yang menginisialisasi ukuran tabel hash (daftar) dan mengatur ukuran vector table sesuai ukuran yang diberikan; insertItem(int key) untuk menyisipkan elemen ke dalam tabel hash pada indeks yang dihitung oleh hashFunction; deleteItem(int key) untuk menghapus elemen dari tabel hash pada indeks yang dihitung oleh hashFunction; displayHashTable() untuk menampilkan seluruh elemen dalam tabel hash dengan melakukan iterasi melalui setiap indeks dari table menggunakan perulangan for sampai semua elemen terlewati, kemudian dicetak. Pada fungsi main, fungsi tersebut membuat objek HashTable dengan ukuran 7. Kemudian menyisipkan elemen (10, 20, 15, 7, 8) ke dalam tabel hash menggunakan insertItem. Seluruh isi tabel akan ditampilkan menggunakan displayHashTable. Satu elemen dengan kunci 20 akan dihapus dari tabel menggunakan deleteItem. Kemudian setelah dilakukan penghapusan elemen, isi tabel ditampilkan kembali. Setelah program selesai berjalan dengan baik, program akan mengemballikan nilai 0.

#### Output:
![Screenshot 2024-06-20 202234](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/bca86ef3-915b-463e-940e-5995184104b3)


c. REKURSIF

Rekursif adalah fungsi yang memanggil dirinya sendiri untuk menyelesaikan masalah dengan membaginya menjadi submasalah. Ada dua jenis rekursif, yaitu rekursif tunggal dan rekursif ganda, di mana rekursif tunggal menggunakan satu referensi dan rekursif ganda menggunakan banyak referensi. Dalam pemrograman imperatif, rekursif sering dihindari karena overhead dari pemanggilan fungsi berulang, namun rekursif memberikan solusi efisien untuk masalah kompleks dengan tahapan singkat. Kelemahannya adalah membutuhkan stack atau tumpukan besar yang sulit dipahami [3].

```C++
#include <iostream>

using namespace std;

int faktorial(int n) {
    
    if (n <= 1) {
        return 1;
    }
    else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int angka;
    
    cout << "Masukkan angka: ";
    cin >> angka;
    
    int hasil = faktorial(angka);
    cout << "Faktorial dari " << angka << " adalah " << hasil << endl;
    
    return 0;
}
```

Program dimulai dengan mendefinisikan fungsi faktorial dengan parameter n bertipe integer untuk menghitung faktorial. Rekursi berjalan jika n kurang dari atau sama dengan 1, maka fungsi mengembalikan nilai 1. Jika n lebih besar dari 1, maka fungsi mengembalikan nilai n dikalikan dengan hasil pemanggilan fungsi faktorial(n - 1). Pada fungsi main, int angka mendeklarasikan variabel angka bertipe integer untuk menyimpan input dari user. User akan diminta memasukkan angka yang ingin diketahui faktorial nya. Perintah cout akan mencetak pesan "Masukkan angka: ", dan perintah cin akan mengambil input dari user dan menyimpannya ke variabel angka. Kemudian program memanggil fungsi faktorial dengan argumen angka yang diberikan oleh pengguna dan menyimpan hasilnya di variabel hasil. Kemudian program akan menampilkan hasil akhir nya dengan perintah cout untuk mencetak hasil faktorial. Setelah program selesai berjalan dengan baik, program akan mengemballikan nilai 0. Output dari program ini adalah "Faktorial dari 6 adalah 720".

#### Output:
![Screenshot 2024-06-20 201812](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/0dc816d2-5f06-4ab6-82c2-95f13f4af395)


d. GRAPH & TREE

Graph adalah jenis struktur data yang terdiri dari berbagai node yang saling terhubung. Node dalam jenis ini disebut sebagai simpul dimana ada garis yang menghubungkan dari setiap simpul tersebut, digunakan dalam pembuatan jaringan seperti jaringan komputer atau telepon. Graph menggambarkan kumpulan objek dimana pasangan dari objek tersebut terhubung oleh link. Objek yang terhubung digambarkan sebagai vertex dan link yang menghubungkan vertex disebut edge. Graph dibedakan menjadi dua jenis, directed graph dan undirected graph. Directed graph adalah garis yang terhubung ke semua simpul, sedangkan undirected graph tidak semua simpul terhubung dengan garis. Keuntungan dari jenis ini yaitu memudahkan dalam memeriksa hubungan antar node dengan cepat dan cocok untuk grafik yang tidak banyak mengandung node, sedangkan kekurangannya adalah membutuhkan waktu yang lebih lama dalam memodifikasi data [4].


##### Program Graph
```C++
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
    int V;    
    vector<list<int>> adj; 

public:
    Graph(int V);

    void addEdge(int v, int w);

    void printGraph() const;
};

Graph::Graph(int V) : V(V), adj(V) {}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
    adj[w].push_back(v); 
}

void Graph::printGraph() const {
    for (int v = 0; v < V; ++v) {
        cout << "Simpul " << v << ": ";
        for (auto x : adj[v])
            cout << x << " ";
        cout << endl;
    }
}

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    return 0;
}
```

Program dimulai dengan mendeklarasikan kelas Graph yang memiliki dua anggota data dan tiga fungsi anggota yaitu, int V: jumlah simpul dalam graf; vector list int adj: daftar tetangga dari setiap simpul; Graph(int V): konstruktor untuk menginisialisasi graf dengan V simpul; void addEdge(int v, int w): menambahkan sebuah sisi antara simpul v dan w; void printGraph() const: mencetak daftar tetangga dari setiap simpul dalam graf. Kemudian konstruktor menginisialisasi jumlah simpul V dan membuat vektor adj yang berisi daftar (list) untuk menyimpan tetangga dari setiap simpul. Pada Fungsi addEdge, fungsi tersebut menambahkan sebuah sisi antara simpul v dan w dengan cara menambah w ke daftar tetangga v dan sebaliknya. Pada fungsi printGraph, fungsi tersebut mencetak daftar tetangga untuk setiap simpul dalam graf dengan melakukan iterasi dari pengulangan for pada setiap simpul dari 0 sampai v-1, dan mencetak daftar dari setiap simpulnya. Pada fungsi main, fungsi tersebut membuat objek graf g dengan simpul 5, kemudian graf dicetak. Setelah program selesai berjalan dengan baik, program akan mengemballikan nilai 0.

#### Output:
![Screenshot 2024-06-20 202459](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/040d3335-7347-4d2e-bc74-70803946cfd2)


Tree adalah struktur data hierarkis yang terdiri dari node-node yang saling terhubung, menyerupai pola pohon. Setiap node berisi data atau link ke node lainnya. Binary tree, sebagai salah satu bentuk tree, memiliki karakteristik di mana setiap node memiliki paling banyak dua child, yaitu left child dan right child. Binary tree diimplementasikan dengan menggunakan link dan menawarkan keunggulan seperti proses pencarian data yang cepat dan efisien, kemudahan dalam memindahkan subtree, refleksi hubungan data yang struktural, dan cocok untuk hierarki data. Namun, binary tree juga memiliki kekurangan, yaitu memerlukan waktu lebih lama dalam memasukkan data karena harus disesuaikan dengan urutan nilainya [4].

##### Program Tree
```C++
#include <iostream>

using namespace std;

// Struktur Node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Konstruktor
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi untuk menambahkan node baru ke pohon biner
Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Fungsi untuk melakukan traversal in-order
void inorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Fungsi untuk melakukan traversal pre-order
void preorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Fungsi untuk melakukan traversal post-order
void postorderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "In-order traversal: ";
    inorderTraversal(root);
    cout << endl;

    cout << "Pre-order traversal: ";
    preorderTraversal(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postorderTraversal(root);
    cout << endl;
    
    return 0;
}
```

Program dimulai dengan struct node yang direpresentasikan simpul dalam pohon biner yaitu, data untuk menyimpan nilai simpul; left sebagai pointer ke anak kiri; right sebagai pointer ke anak kanan; konstruktor yang menginisialisasi nilai data dan mengatur pointer left dan right menjadi nullptr. Pada fungsi insert, fungsi tersebut untuk menambahkan node baru ke dalam pohon biner. Jika root adalah nullptr, akan membuat node baru dan mengembalikan sebagai root baru. Jika data lebih kecil dari root->data, maka akan memanggil insert secara rekursif pada subtree kiri. Jika data lebih besar atau sama dengan root->data, maka akan memanggil insert secara rekursif pada subtree kanan. Kemudian mengembalikan root setelah melakukan operasi insert. Pada fungsi traversal terdapat 3 fungsi yaitu Pre-order, In-order, Post-order. Pada fungsi Pre Order, fungsi akan megunjungi node saat ini terlebih dahulu. Pada In Order, fungsi akan mengunjungi subtree kiri terlebih dahulu kemudian node saat ini dan terakhir mengunjungi subtree sebelah kanan. Pada fungsi Post Order, fungsi akan mengunjungi subtree sebelah kiri, kemudian subtree sebelah kanan dan terakhir mengunjungi node yang saat ini. Pada fungsi main, fungsi membuat pohon biner dengan root nullptr. Kemudian menambahkan beberapa node ke dalam pohon menggunakan fungsi insert, dan menampilkan hasil dari ketiga fungsi traversal. Setelah program selesai berjalan dengan baik, program akan mengemballikan nilai 0.

#### Output:
![Screenshot 2024-06-20 202553](https://github.com/yasminealifta/Teori-Algoritma-Struktur-Data-Assignment/assets/161322990/1a1e2ed4-975b-46a5-8d07-f372e440823f)

## Referensi
[1] Z. Musiafa, STRUKTUR DATA DAN IMPLEMENTASI ALGORITMA (SDIA): Pemrograman Python C C++ Java. ZAYID MUSIAFA, 2022.

[2] S. S. Wanda et al., PENGANTAR ILMU KOMPUTER : Panduan Komprehensif bagi Pemula. PT. Sonpedia Publishing Indonesia, 2023.

[3] I. Irmawati et al., BUKU AJAR PEMROGRAMAN. PT. Sonpedia Publishing Indonesia, 2023.

[4] O. Arifin et al., DASAR PEMROGRAMAN : Teori & aplikasi. PT. Sonpedia Publishing Indonesia, 2023.

