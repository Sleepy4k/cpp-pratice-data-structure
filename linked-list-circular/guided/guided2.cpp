#include <iostream>

using namespace std;

// program single linked list circular

// deklarasi struct node
struct Node {
  string data;
  Node *next;
} *head, *tail, *baru, *bantu, *hapus;

void init() { head = tail = NULL; }

// pengecekan
bool isEmpty() {
  if (head == NULL)
    return true;

  return false;
}

// buat node baru
void buatNode(string data) {
  baru = new Node;
  baru->data = data;
  baru->next = NULL;
}

// hitung list
int hitungList() {
  bantu = head;

  int jumlah = 0;

  while (bantu != NULL) {
    jumlah++;
    bantu = bantu->next;
  }

  return jumlah;
}

// tambah depan
void insertDepan(string data) {
  // buat node baru
  buatNode(data);

  if (isEmpty()) {
    head = baru;
    tail = head;
    baru->next = head;
    return;
  }

  while (tail->next != head) {
    tail = tail->next;
  }

  baru->next = head;
  head = baru;
  tail->next = head;
}

// tambah belakan
void insertBelakang(string data) {
  // buat node baru
  buatNode(data);

  if (isEmpty()) {
    head = baru;
    tail = head;
    tail->next = head;
  }

  while (tail->next != head) {
    tail = tail->next;
  }

  tail->next = baru;
  baru->next = head;
  tail = baru;
}

// tambah tengah
void insertTengah(string data, int posisi) {
  // buat node baru
  buatNode(data);

  if (isEmpty()) {
    head = baru;
    tail = head;
    baru->next = head;
    return;
  }

  baru->data = data;

  // transversing
  int nomor = 1;

  bantu = head;

  while (nomor < posisi - 1) {
    bantu = bantu->next;
    nomor++;
  }

  baru->next = bantu->next;
  bantu->next = baru;
}

// hapus depan
void hapusDepan() {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  hapus = tail = head;

  if (hapus->next == head) {
    head = tail = NULL;
    delete hapus;
    return;
  }

  while (tail->next != hapus) {
    tail = tail->next;
  }

  head = head->next;
  tail->next = head;
  hapus->next = NULL;

  delete hapus;
}

// hapus belakang
void hapusBelakang() {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  hapus = tail = head;

  if (hapus->next == head) {
    head = tail = NULL;
    delete hapus;
    return;
  }

  while (hapus->next != head) {
    hapus = hapus->next;
  }

  while (tail->next != hapus) {
    tail = tail->next;
  }

  tail->next = head;
  hapus->next = NULL;

  delete hapus;
}

// hapus tengah
void hapusTengah(int posisi) {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  bantu = head;

  int nomor = 1;

  while (nomor < posisi - 1) {
    bantu = bantu->next;
    nomor++;
  }

  hapus = bantu->next;
  bantu->next = hapus->next;

  delete hapus;
}

// hapus list
void clearList() {
  if (!isEmpty()) {
    hapus = head->next;

    while (hapus != head) {
      bantu = hapus->next;
      delete hapus;
      hapus = bantu;
    }

    delete head;
    head = tail = NULL;
  }

  cout << "List berhasil dihapus" << endl;
}

// tampilkan list
void tampil() {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  tail = head;

  do {
    cout << tail->data;
    tail = tail->next;
  } while (tail != head);

  cout << endl;
}

int main() {
  init();

  insertDepan("Ayam");
  tampil();

  insertDepan("Bebek");
  tampil();

  insertBelakang("Cicak");
  tampil();

  insertBelakang("Domba");
  tampil();

  hapusBelakang();
  tampil();

  hapusDepan();
  tampil();

  insertTengah("Sapi", 2);
  tampil();

  hapusTengah(2);
  tampil();

  return 0;
}