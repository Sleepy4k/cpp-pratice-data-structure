#include <iostream>

using namespace std;

int find_number(int target_081) {
  int n_081 = 10, found_081 = 0, i;
  int data_081[n_081] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};

  for (i = 0; i < n_081; i++) {
    if (data_081[i] != target_081) continue;

    found_081++;
  }

  return found_081;
}

int main() {
  cout << "Program Sequential Search\n" << endl;
  cout << "Data : {9, 4, 1, 4, 7, 10, 5, 4, 12, 4}\n" << endl;

  int target_081 = 4, found_081 = find_number(target_081);

  if (found_081 < 1) {
    cout << "Angka " << target_081 << " tidak ditemukan dalam data" << endl;
    return 0;
  }

  cout << "Ditemukan " << found_081 << " angka " << target_081 << " dalam data\n" << endl;

  return 0;
}