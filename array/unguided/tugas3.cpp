#include <iostream>

using namespace std;

void find_max_or_min(int type_081) {
  int length_081;

  cout << "Masukan panjang array: ";
  cin >> length_081;

  int data_081[length_081];

  cout << "Masukan " << length_081 << " angka" << endl;

  for (int i = 0; i < length_081; i++) {
    cout << "Array ke-" << i << ": ";
    cin >> data_081[i];
  }

  int index_081, threshold_081 = data_081[0];

  for (int i = 0; i < length_081; i++) {
    if (type_081 == 0 && data_081[i] < threshold_081)
      continue;
    else if (type_081 == 1 && data_081[i] > threshold_081)
      continue;

    threshold_081 = data_081[i];
    index_081 = i;
  }

  cout << "Nilai " << (type_081 == 0 ? "maksimum" : "minimum") << " adalah "
       << threshold_081 << " berada pada array ke-" << index_081 << endl;
}

void find_average() {
  int length_081;

  cout << "Masukan panjang array: ";
  cin >> length_081;

  int data_081[length_081];

  cout << "Masukan " << length_081 << " angka" << endl;

  for (int i = 0; i < length_081; i++) {
    cout << "Array ke-" << i << ": ";
    cin >> data_081[i];
  }

  int total_081 = 0;

  for (int i = 0; i < length_081; i++) {
    total_081 += data_081[i];
  }

  cout << "Nilai rata rata adalah " << total_081 / length_081 << endl;
}

int main() {
  // Inisiasi variable untuk menampung pilihan menu
  int choice_081;

  // Inisiasi variable untuk kondisi perulangan
  bool isRunning_081 = true;

  do {
    // Tampilkan menu dan ambil pilihan menu user
    cout << "Perhitungan Sederhana" << endl;
    cout << "=====================" << endl;
    cout << "1. Mencari Nilai Maksimum" << endl;
    cout << "2. Mencari Nilai Minimum" << endl;
    cout << "3. Mencari Nilai Rata Rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "=====================" << endl;
    cout << "Masukan pilihan kamu : ";
    cin >> choice_081;

    // Check apakah pilihan valid, jika iya jalankan fungsi sesuai menu
    switch (choice_081) {
    case 1:
      find_max_or_min(0);
      break;
    case 2:
      find_max_or_min(1);
      break;
    case 3:
      find_average();
      break;
    case 4:
      // Jika user memilih menu 3, maka ubah status isRunning menjadi false
      isRunning_081 = false;
      break;
    default:
      // Jika pilihan tidak valid, maka system mencetak pilihan tidak valid
      cout << "Pilihan tidak valid" << endl;
      break;
    }
  } while (
      isRunning_081); // Apabila kondisi bernilai true, maka ulangin perulangan

  cout << "Terima kasih sudah menggunakan system kami :)" << endl;

  return 0;
}
