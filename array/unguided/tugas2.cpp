#include <cstring>
#include <iostream>

using namespace std;

int main() {
  int f_081, g_081, h_081;

  cout << "Masukan panjang kolom array: ";
  cin >> f_081;

  cout << "Masukan panjang baris array: ";
  cin >> g_081;

  cout << "Masukan jumlah data array: ";
  cin >> h_081;

  int arr_081[f_081][g_081][h_081];

  for (int i_081 = 0; i_081 < 2; i_081++) {
    for (int j_081 = 0; j_081 < 3; j_081++) {
      for (int k_081 = 0; k_081 < 3; k_081++) {
        cout << "Input Array[" << i_081 << "][" << j_081 << "][" << k_081
             << "] = ";
        cin >> arr_081[i_081][j_081][k_081];
      }
    }

    cout << endl;
  }

  for (int x_081 = 0; x_081 < 2; x_081++) {
    for (int y_081 = 0; y_081 < 3; y_081++) {
      for (int z_081 = 0; z_081 < 3; z_081++) {
        cout << "Data Array[" << x_081 << "][" << y_081 << "][" << z_081
             << "] = " << arr_081[x_081][y_081][z_081] << endl;
      }
    }
  }

  cout << endl;

  for (int a_081 = 0; a_081 < 2; a_081++) {
    for (int b_081 = 0; b_081 < 3; b_081++) {
      for (int c_081 = 0; c_081 < 3; c_081++) {
        cout << arr_081[a_081][b_081][c_081] << endl;
      }

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
