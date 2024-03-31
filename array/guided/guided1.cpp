#include <iostream>

using namespace std;

int main() {
  int arr[2][3][3];

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        cout << "Input Array[" << i << "][" << j << "][" << k << "] = ";
        cin >> arr[i][j][k];
      }
    }

    cout << endl;
  }

  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 3; y++) {
      for (int z = 0; z < 3; z++) {
        cout << "Data Array[" << x << "][" << y << "][" << z
             << "] = " << arr[x][y][z] << endl;
      }
    }
  }

  cout << endl;

  for (int a = 0; a < 2; a++) {
    for (int b = 0; b < 3; b++) {
      for (int c = 0; c < 3; c++) {
        cout << arr[a][b][c] << endl;
      }

      cout << endl;
    }

    cout << endl;
  }

  return 0;
}
