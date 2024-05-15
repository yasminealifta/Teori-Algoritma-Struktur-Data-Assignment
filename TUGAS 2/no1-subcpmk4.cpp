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