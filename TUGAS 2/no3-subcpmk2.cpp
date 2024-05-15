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