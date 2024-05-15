#include <iostream>
#include <iomanip>

using namespace std;

int cari, dataArray[7] = {1, 8, 2, 5, 3, 9, 7}, dataLength = sizeof(dataArray) / sizeof(*dataArray);

void selection_sort() {
  int temp, min, i, j;

  for (i = 0; i < dataLength; i++) {
    min = i;

    for (j = i + 1; j < dataLength; j++) {
      if (dataArray[j] > dataArray[min]) continue;

      min = j;
    }

    temp = dataArray[i];
    dataArray[i] = dataArray[min];
    dataArray[min] = temp;
  }
}

void binary_search() {
  int awal = 0, akhir = dataLength - 1, tengah, is_found = false;

  while (!is_found && awal <= akhir) {
    tengah = (awal + akhir) / 2;

    if (dataArray[tengah] == cari) is_found = true;
    else if (dataArray[tengah] < cari) awal = tengah + 1;
    else akhir = tengah - 1;
  }

  if (is_found) cout << "Data ditemukan pada indeks ke-" << tengah << endl;
  else cout << "Data tidak ditemukan" << endl;
}

int main() {
  int i;

  cout << "BINARY SEARCH\n" << endl;
  cout << "Data : ";

  for (i = 0; i < dataLength; i++) {
    cout << setw(3) << dataArray[i];
  }

  cout << "\n" << endl;

  cout << "Masukkan data yang dicari : ";
  cin >> cari;
  cout << endl;

  cout << "Data Diurutkan : ";
  selection_sort();

  for (i = 0; i < dataLength; i++) {
    cout << setw(3) << dataArray[i];
  }

  cout << "\n" << endl;

  binary_search();

  return 0;
}