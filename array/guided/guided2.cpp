#include <iostream>

using namespace std;

int main() {
  int a, i, maks, lokasi;

  cout << "Masukan panjang array: ";
  cin >> a;

  int array[a];

  cout << "Masukan " << a << " angka" << endl;

  for (i = 0; i < a; i++) {
    cout << "Array ke-" << i << ": ";
    cin >> array[i];
  }

  maks = array[0];

  for (i = 0; i < a; i++) {
    if (array[i] < maks)
      continue;

    maks = array[i];
    lokasi = i;
  }

  cout << "Nilai maksimum adalah " << maks << " berada pada indeks ke "
       << lokasi << endl;

  return 0;
}
