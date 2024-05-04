#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Struktur data untuk merepresentasikan mahasiswa
struct Mahasiswa {
  string nama, nim;
  int nilai;
};

// Class untuk hash table
class HashTable {
private:
  static const int SIZE = 100;   // Ukuran hash table
  vector<Mahasiswa> table[SIZE]; // Array dari vector untuk menampung data

  // Fungsi hash untuk menghasilkan indeks dari nim
  int generate_hash(string nim) { return atoi(nim.c_str()) & SIZE; }

public:
  // Fungsi untuk menambahkan data mahasiswa
  void insert_data(Mahasiswa data) {
    int index = generate_hash(data.nim);

    table[index].push_back(data);
  }

  // Fungsi untuk menghapus data mahasiswa berdasarkan nim
  void remove_data(string nim) {
    int index = generate_hash(nim);

    for (auto it = table[index].begin(); it != table[index].end(); it++) {
      if ((*it).nim != nim)
        continue;

      table[index].erase(it);
      break;
    }
  }

  // Fungsi untuk mencari data mahasiswa berdasarkan nim
  void find_data_by_nim(string nim) {
    bool isFound = false;
    int index = generate_hash(nim);

    cout << "==========================" << endl;

    for (Mahasiswa mhs : table[index]) {
      if (mhs.nim != nim)
        continue;

      isFound = true;
      cout << "NIM : " << mhs.nim << ", Nama : " << mhs.nama
           << ", Nilai : " << mhs.nilai << endl;
      break;
    }

    if (!isFound)
      cout << "data mahasiswa tidak ditemukan" << endl;

    cout << "==========================" << endl;
  }

  // Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai
  void find_data_by_nilai(int minnilai, int maxnilai) {
    cout << "==========================" << endl;

    for (int i = 0; i < SIZE; i++) {
      for (Mahasiswa mhs : table[i]) {
        if (mhs.nilai < minnilai || mhs.nilai > maxnilai)
          continue;

        cout << "NIM : " << mhs.nim << ", Nama : " << mhs.nama
             << ", Nilai : " << mhs.nilai << endl;
      }
    }

    cout << "==========================" << endl;
  }

  // Fungsi untuk menampilkan semua data mahasiswa
  void show_all_data() {
    cout << "==========================" << endl;

    for (int i = 0; i < SIZE; i++) {
      for (Mahasiswa mhs : table[i]) {
        cout << "NIM : " << mhs.nim << ", Nama : " << mhs.nama
             << ", Nilai : " << mhs.nilai << endl;
      }
    }

    cout << "==========================" << endl;
  }
};

int main() {
  HashTable ht;

  bool isRunning = true;
  int choice, nilai;
  string nama, nim;

  system("cls");

  do {
    cout << endl;
    cout << "System Management Mahasiswa" << endl;
    cout << "===================================" << endl;
    cout << "1. Tambah Data Mahasiswa" << endl;
    cout << "2. Hapus Data Mahasiswa" << endl;
    cout << "3. Cari Data Mahasiswa Berdasarkan Nim" << endl;
    cout << "4. Cari Data Mahasiswa Dengan rentang Nilai (80 - 90)" << endl;
    cout << "5. Tampilkan Semua Data Mahasiswa" << endl;
    cout << "6. keluar" << endl;
    cout << "===================================" << endl;
    cout << "Masukan pilihan: ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Masukkan nim mahasiswa: ";
      cin >> nim;
      cout << "Masukkan nama mahasiswa: ";
      cin >> nama;
      cout << "Masukkan nilai mahasiswa: ";
      cin >> nilai;

      ht.insert_data(Mahasiswa{nama, nim, nilai});
      break;
    case 2:
      cout << "Masukkan nim mahasiswa yang akan dihapus: ";
      cin >> nim;

      ht.remove_data(nim);
      break;
    case 3:
      cout << "Masukkan nim mahasiswa yang dicari: ";
      cin >> nim;

      ht.find_data_by_nim(nim);
      break;
    case 4:
      cout << "Mahasiswa dengan nilai antara 80 - 90: " << endl;

      ht.find_data_by_nilai(80, 90);
      break;
    case 5:
      cout << "Seluruh data mahasiswa: " << endl;

      ht.show_all_data();
      break;
    case 6:
      isRunning = false;
      break;
    default:
      cout << "Pilihan tidak valid, silakan coba lagi." << endl;
      break;
    }
  } while (isRunning);

  cout << "Terima kasih sudah menggunakan aplikasi kami!" << endl;

  return 0;
}
