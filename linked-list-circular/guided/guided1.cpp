#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
} *head, *tail;

void init() { head = tail = NULL; }

// pengecekan
bool isEmpty() {
  if (head == NULL)
    return true;

  return false;
}

// tambah depan
void insertDepan(int nilai) {
  // buat node baru
  Node *baru = new Node();
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

// tambah belakang
void insertBelakang(int nilai) {
  // buat node baru
  Node *baru = new Node();
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

// hitung jumlah list
int hitungList() {
  Node *hitung = head;

  int jumlah = 0;

  while (hitung != NULL) {
    jumlah++;
    hitung = hitung->next;
  }

  return jumlah;
}

// tambah tengah
void insertTengah(int data, int posisi) {
  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan di tengah" << endl;
  else {
    Node *baru, *bantu = head;
    baru = new Node();
    baru->data = data;

    // tranversing
    int nomor = 1;

    while (nomor < posisi - 1) {
      bantu = bantu->next;
      nomor++;
    }

    baru->next = bantu->next;
    bantu->next = baru;
  }
}

// hapus depan
void hapusDepan() {
  Node *hapus = head;

  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  if (head->next == NULL) {
    head = tail = NULL;
    return;
  }

  head = head->next;
  delete hapus;
}

// hapus belakang
void hapusBelakang() {
  Node *hapus = tail, *bantu = head;

  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  if (bantu == hapus) {
    head = tail = NULL;
    return;
  }

  while (bantu->next != tail) {
    bantu = bantu->next;
  }

  tail = bantu;
  tail->next = NULL;
  delete hapus;
}

// hapsu tengah
void hapusTengah(int posisi) {
  Node *hapus, *bantu = head, *bantu2;

  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi di luar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan di tengah" << endl;
  else {
    int nomor = 1;

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

// ubah depan
void ubahDepan(int data) {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  head->data = data;
}

// ubah tengah
void ubahTengah(int data, int posisi) {
  Node *bantu = head;

  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  if (posisi < 1 || posisi > hitungList())
    cout << "Posisi diluar jangkauan" << endl;
  else if (posisi == 1)
    cout << "Posisi bukan di tengah" << endl;
  else {
    int nomor = 1;

    while (nomor < posisi) {
      bantu = bantu->next;
      nomor++;
    }

    bantu->data = data;
  }
}

// ubah belakang
void ubahBelakang(int data) {
  if (isEmpty()) {
    cout << "List masih kosong" << endl;
    return;
  }

  tail->data = data;
}

// hapus list
void clearList() {
  Node *bantu = head, *hapus;

  while (bantu != NULL) {
    hapus = bantu;
    bantu = bantu->next;
    delete hapus;
  }

  head = tail = NULL;
  cout << "List berhasil terhapus!" << endl;
}

// tampilkan list
void tampil() {
  Node *bantu = head;

  if (isEmpty()) {
    cout << "List Kosong!" << endl;
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