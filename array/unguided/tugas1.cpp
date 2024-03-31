#include <iostream>

using namespace std;

int main() {
  int length_081;

  cout << "Masukan panjang array : ";
  cin >> length_081;

  int data_081[length_081];

  cout << "Masukan " << length_081 << " angka" << endl;

  for (int x_081 = 0; x_081 < length_081; x_081++) {
    cout << "Masukan angka ke-" << x_081 + 1 << ": ";
    cin >> data_081[x_081];
  }

  cout << "\n" << endl;

  for (int y_081 = 0; y_081 < 3; y_081++) {
    switch (y_081) {
    case 0:
      cout << "Data Array : ";
      break;
    case 1:
      cout << "Nomor Genap : ";
      break;
    case 2:
      cout << "Nomor Ganjil : ";
      break;
    }

    for (int z_081 = 0; z_081 < length_081; z_081++) {
      switch (y_081) {
      case 0:
        cout << data_081[z_081] << " ";
        break;
      case 1:
        if (data_081[z_081] % 2 != 0)
          continue;

        cout << data_081[z_081] << ", ";
        break;
      case 2:
        if (data_081[z_081] % 2 != 1)
          continue;

        cout << data_081[z_081] << ", ";
        break;
      }
    }

    cout << endl;
  }

  return 0;
}
