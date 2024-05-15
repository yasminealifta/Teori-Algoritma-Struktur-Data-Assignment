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