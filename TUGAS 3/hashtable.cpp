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
