#include <iomanip>
#include <iostream>

using namespace std;

// Array
string simpul[7] = {
  "Ciamis",
  "Bandung",
  "Bekasi",
  "Tasikmalaya",
  "Cianjur",
  "Purwokerto",
  "Yogyakarta"
};

// Arry matriks 2 dimensi
int busur[7][7] = {
  {0, 7, 8, 0, 0, 0, 0},
  {0, 0, 5, 0, 0, 15, 0},
  {0, 6, 0, 0, 5, 0, 0},
  {0, 5, 0, 0, 2, 4, 0},
  {23, 0, 0, 10, 0, 0, 8},
  {0, 0, 0, 0, 7, 0, 3},
  {0, 0, 0, 0, 9, 4, 0},
};

void tampilGraph() {
  for (int i = 0; i < sizeof(simpul) / sizeof(*simpul); i++) {
    // Mencetak busur dan simpul tujuan
    cout << " " << setw(15) << left << simpul[i] << " : ";

    for (int j = 0; j < sizeof(simpul) / sizeof(*simpul); j++) {
      if (busur[i][j] == 0) continue;

      cout << " " << simpul[j] << "(" << busur[i][j] << ")";
    }

    cout << endl;
  }
}

int main() {
  tampilGraph();

  return 0;
}