#include <iostream>

using namespace std;

int main() {
  int n = 10, cari = 10, i;
  int data[n] = {9,4,1,7,5,12,4,13,4,10};
  bool ketemu = false;

  for (i = 0; i < n; i++) {
    if (data[i] != cari) continue; 

    ketemu = true;
    break;
  }

  cout << "Program Sequential Search\n" << endl;
  cout << "Data : {9,4,1,7,5,12,4,13,4,10}\n" << endl;

  if (ketemu) cout << "Data ditemukan pada indeks ke-" << i << endl;
  else cout << "Data tidak ditemukan" << endl;

  return 0;
}