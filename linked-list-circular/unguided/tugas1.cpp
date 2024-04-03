#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR

// Deklarasi Struct Data
// Agar mempermudah penulisan kode
struct Data {
  string nama_081;
  int usia_081;
};

// Deklarasi Struct Node
struct Node {
  // komponen/member
  Data data_081;
  Node *next;
} *head, *tail;

// Inisialisasi Node
void init() {
  head = NULL;
  tail = NULL;
}

// Pengecekan
bool isEmpty() {
  if (head == NULL)
    return true;

  return false;
}

// Tambah Depan
void insertDepan(Data data) {
  // Buat Node baru
  Node *baru = new Node;
  baru->data_081 = data;
  baru->next = NULL;

  if (isEmpty()) {
    head = tail = baru;
    tail->next = NULL;
    return;
  }

  baru->next = head;
  head = baru;
}

// Tambah Belakang
void insertBelakang(Data data) {
  // Buat Node baru
  Node *baru = new Node;
  baru->data_081 = data;
  baru->next = NULL;

  if (isEmpty()) {
    head = tail = baru;
    tail->next = NULL;
    return;
  }

  tail->next = baru;
  tail = baru;
}

// Hitung Jumlah List
int hitungList() {
  Node *hitung;
  hitung = head;

  int jumlah = 0;

  while (hitung != NULL) {
    jumlah++;
    hitung = hitung->next;
  }

  return jumlah;
}

// Tambah Tengah
void insertTengah(Data data, int posisi) {
  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan posisi tengah" << endl;
  else {
    Node *baru, *bantu;
    baru = new Node();
    baru->data_081 = data;

    bantu = head;

    int nomor = 1;

    while (nomor < posisi - 1) {
      bantu = bantu->next;
      nomor++;
    }

    baru->next = bantu->next;
    bantu->next = baru;
  }
}

// Hapus Depan
void hapusDepan() {
  Node *hapus;

  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  if (head->next == NULL) {
    head = tail = NULL;
    return;
  }

  hapus = head;
  head = head->next;
  delete hapus;
}

// Hapus Belakang
void hapusBelakang() {
  Node *bantu, *hapus;

  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  if (head == tail) {
    head = tail = NULL;
    return;
  }

  hapus = tail;
  bantu = head;

  while (bantu->next != tail) {
    bantu = bantu->next;
  }

  tail = bantu;
  tail->next = NULL;
  delete hapus;
}

// Hapus Tengah
void hapusTengah(int posisi) {
  Node *hapus, *bantu, *bantu2;

  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi di luar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan posisi tengah" << endl;
  else {
    int nomor = 1;

    bantu = head;

    while (nomor <= posisi) {
      if (nomor == posisi - 1)
        bantu2 = bantu;
      if (nomor == posisi)
        hapus = bantu;

      bantu = bantu->next;
      nomor++;
    }

    bantu2->next = bantu;
    delete hapus;
  }
}

// Ubah Depan
void ubahDepan(Data data) {
  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  head->data_081 = data;
}

// Ubah Tengah
void ubahTengah(Data data, int posisi) {
  Node *bantu;

  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi di luar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan posisi tengah" << endl;
  else {
    int nomor = 1;

    bantu = head;

    while (nomor < posisi) {
      bantu = bantu->next;
      nomor++;
    }

    bantu->data_081 = data;
  }
}

// Ubah Belakang
void ubahBelakang(Data data) {
  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  tail->data_081 = data;
}

// Hapus List
void clearList() {
  Node *bantu, *hapus;

  bantu = head;

  while (bantu != NULL) {
    hapus = bantu;
    bantu = bantu->next;
    delete hapus;
  }

  head = tail = NULL;
  cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
  Node *bantu;

  bantu = head;

  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  int index = 1;

  cout << "===================" << endl;

  while (bantu != NULL) {
    cout << "Data ke " << index << endl;
    cout << "Nama : " << bantu->data_081.nama_081
         << "\tUmur : " << bantu->data_081.usia_081 << endl;
    bantu = bantu->next;
    index++;
  }

  cout << "===================" << endl;
}

int main() {
  // Inisialisasi Linked List
  init();

  // Tambahkan data sesuai request tugas
  insertDepan(Data{"Apri", 19});
  insertBelakang(Data{"Karin", 18});
  insertTengah(Data{"John", 19}, 2);
  insertTengah(Data{"Jane", 20}, 3);
  insertTengah(Data{"Michael", 18}, 4);
  insertTengah(Data{"Yusuke", 19}, 5);
  insertTengah(Data{"Akechi", 20}, 6);
  insertTengah(Data{"Hoshio", 18}, 7);

  bool isRunning = true;
  int pilihan, umur, posisi;
  string nama;

  do {
    cout << "Menu Single Linked List" << endl;
    cout << "1. Tampilkan semua data" << endl;
    cout << "2. Tambah data" << endl;
    cout << "3. Ubah data" << endl;
    cout << "4. Hapus data" << endl;
    cout << "5. Keluar" << endl;
    cout << "========================" << endl;
    cout << "Pilih menu : ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
      tampil();
      break;
    case 2:
      cout << "Menu tambah data" << endl;
      cout << "1. Tambah data awal" << endl;
      cout << "2. Tambah data tengah" << endl;
      cout << "3. Tambah data akhir" << endl;
      cout << "=====================" << endl;
      cout << "Pilih menu : ";
      cin >> pilihan;

      if (pilihan < 1 || pilihan > 3) {
        cout << "Pilihan tidak valid" << endl;
        break;
      }

      // Mengambil input nama dan umur
      cout << "Masukan data nama : ";
      cin >> nama;

      cout << "Masukan data umur : ";
      cin >> umur;

      switch (pilihan) {
      case 1:
        insertDepan(Data{nama, umur});
        break;
      case 2:
        cout << "Masukan urutan data : ";
        cin >> posisi;

        insertTengah(Data{nama, umur}, posisi);
        break;
      case 3:
        insertBelakang(Data{nama, umur});
        break;
      default:
        break;
      }

      break;
    case 3:
      cout << "Menu ubah data" << endl;
      cout << "1. Ubah data awal" << endl;
      cout << "2. Ubah data tengah" << endl;
      cout << "3. Ubah data akhir" << endl;
      cout << "=====================" << endl;
      cout << "Pilih menu : ";
      cin >> pilihan;

      if (pilihan < 1 || pilihan > 3) {
        cout << "Pilihan tidak valid" << endl;
        break;
      }

      // Mengambil input nama dan umur
      cout << "Masukan data nama : ";
      cin >> nama;

      cout << "Masukan data umur : ";
      cin >> umur;

      switch (pilihan) {
      case 1:
        ubahDepan(Data{nama, umur});
        break;
      case 2:
        cout << "Masukan urutan data : ";
        cin >> posisi;

        ubahTengah(Data{nama, umur}, posisi);
        break;
      case 3:
        ubahBelakang(Data{nama, umur});
        break;
      default:
        break;
      }

      break;
    case 4:
      cout << "Menu hapus data" << endl;
      cout << "1. Hapus data awal" << endl;
      cout << "2. Hapus data tengah" << endl;
      cout << "3. Hapus data akhir" << endl;
      cout << "=====================" << endl;
      cout << "Pilih menu : ";
      cin >> pilihan;

      if (pilihan < 1 || pilihan > 3) {
        cout << "Pilihan tidak valid" << endl;
        break;
      }

      switch (pilihan) {
      case 1:
        hapusDepan();
        break;
      case 2:
        cout << "Masukan urutan data : ";
        cin >> posisi;

        hapusTengah(posisi);
        break;
      case 3:
        hapusBelakang();
        break;
      default:
        break;
      }

      break;
    case 5:
      isRunning = false;
      break;
    default:
      cout << "Pilihan tidak valid, silahkan coba lagi" << endl;
      break;
    }
  } while (isRunning);

  cout << "Terima kasih sudah menggunakan aplikasi kami" << endl;

  return 0;
}
