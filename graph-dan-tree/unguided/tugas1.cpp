#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  int k_081, v_081, n_081 = 0, w_081 = 8;

  cout << "Menghitung Jarak Tempuh" << endl;
  cout << "=======================" << endl;
  cout << "Masukkan jumlah data: ";
  cin >> n_081;

  cout << "=======================" << endl;
  cout << "Silahkan masukkan nama simpul" << endl;

  string simpul_081[n_081];

  for (k_081 = 0; k_081 < n_081; k_081++) {
    cout << "Simpul ke-" << k_081 + 1 << " : ";
    cin >> simpul_081[k_081];
  }

  cout << "=======================" << endl;
  cout << "Silahkan masukkan bobot antar simpul" << endl;

  int bobot_081[n_081][n_081];

  for (k_081 = 0; k_081 < n_081; k_081++) {
    for (v_081 = 0; v_081 < n_081; v_081++) {
      cout << "Bobot dari " << simpul_081[k_081] << " ke " << simpul_081[v_081] << " : ";
      cin >> bobot_081[k_081][v_081];
    }
  }

  cout << "=======================" << endl;
  cout << "Matriks bobot antar simpul" << endl;

  for (k_081 = 0; k_081 <= n_081; k_081++) {
    if (k_081 == 0) {
      cout << setw(w_081) << " ";
      continue;
    }

    cout << setw(w_081) << simpul_081[k_081 - 1];
  }

  cout << endl;

  for (k_081 = 0; k_081 < n_081; k_081++) {
    cout << setw(w_081) << simpul_081[k_081];

    for (v_081 = 0; v_081 < n_081; v_081++) {
      cout << setw(w_081) << bobot_081[k_081][v_081];
    }
    cout << endl;
  }

  return 0;
}
