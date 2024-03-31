#include <iostream>

using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
  // komponen/member
  int data;
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
void insertDepan(int nilai) {
  // Buat Node baru
  Node *baru = new Node;
  baru->data = nilai;
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
void insertBelakang(int nilai) {
  // Buat Node baru
  Node *baru = new Node;
  baru->data = nilai;
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
void insertTengah(int data, int posisi) {
  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan posisi tengah" << endl;
  else {
    Node *baru, *bantu;
    baru = new Node();
    baru->data = data;

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
void ubahDepan(int data) {
  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  head->data = data;
}

// Ubah Tengah
void ubahTengah(int data, int posisi) {
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

    bantu->data = data;
  }
}

// Ubah Belakang
void ubahBelakang(int data) {
  if (isEmpty()) {
    cout << "List kosong!" << endl;
    return;
  }

  tail->data = data;
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

  while (bantu != NULL) {
    cout << bantu->data;
    bantu = bantu->next;
  }

  cout << endl;
}

int main() {
  init();

  insertDepan(3);
  tampil();

  insertBelakang(5);
  tampil();

  insertDepan(2);
  tampil();

  insertDepan(1);
  tampil();

  hapusDepan();
  tampil();

  hapusBelakang();
  tampil();

  insertTengah(7, 2);
  tampil();

  hapusTengah(2);
  tampil();

  ubahDepan(1);
  tampil();

  ubahBelakang(8);
  tampil();

  ubahTengah(11, 2);
  tampil();

  return 0;
}