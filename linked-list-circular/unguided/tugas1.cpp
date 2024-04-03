#include <iostream>

using namespace std;

struct Data {
  string nama;
  long long int nim;
};

struct Node {
  Data data;
  Node *next;
} *head, *tail;

// Inisiasi head dan tail
void init() { head = tail = NULL; }

// pengecekan
bool isEmpty() {
  if (head == NULL)
    return true;

  return false;
}

// tambah depan
void insertDepan(Data data) {
  // buat node baru
  Node *baru = new Node();
  baru->data = data;
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
void insertBelakang(Data data) {
  // buat node baru
  Node *baru = new Node();
  baru->data = data;
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
void insertTengah(Data data, int posisi) {
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
void ubahDepan(Data data) {
  if (isEmpty()) {
    cout << "List Kosong!" << endl;
    return;
  }

  string nama_lama = head->data.nama;
  head->data = data;

  cout << "Data " << nama_lama << " telah diganti menjadi " << head->data.nama
       << endl;
}

// ubah tengah
void ubahTengah(Data data, int posisi) {
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

    string nama_lama = bantu->data.nama;
    bantu->data = data;

    cout << "Data " << nama_lama << " telah diganti menjadi "
         << bantu->data.nama << endl;
  }
}

// ubah belakang
void ubahBelakang(Data data) {
  if (isEmpty()) {
    cout << "List masih kosong" << endl;
    return;
  }

  string nama_lama = tail->data.nama;
  tail->data = data;

  cout << "Data " << nama_lama << " telah diganti menjadi " << tail->data.nama
       << endl;
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

  cout << "NAMA\tNIM" << endl;

  while (bantu != NULL) {
    cout << bantu->data.nama << "\t" << bantu->data.nim << endl;
    bantu = bantu->next;
  }

  cout << endl;
}

int main() {
  init();

  insertDepan(Data{"Jawad", 23300001});
  insertBelakang(Data{"Budi", 23300099});
  insertTengah(Data{"Apri", 2311102081}, 2);
  insertTengah(Data{"Farrel", 23300003}, 3);
  insertTengah(Data{"Denis", 23300005}, 4);
  insertTengah(Data{"Anis", 23300008}, 5);
  insertTengah(Data{"Bowo", 23300015}, 6);
  insertTengah(Data{"Gahar", 23300040}, 7);
  insertTengah(Data{"Udin", 23300048}, 8);
  insertTengah(Data{"Ucok", 23300050}, 9);

  string nama;
  int pilihan, posisi, nim;
  bool isRunning = true;

  do {
    cout << "PROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
    cout << "1. Tambah Depan" << endl;
    cout << "2. Tambah Belakang" << endl;
    cout << "3. Tambah Tengah" << endl;
    cout << "4. Ubah Depan" << endl;
    cout << "5. Ubah Belakang" << endl;
    cout << "6. Ubah Tengah" << endl;
    cout << "7. Hapus Depan" << endl;
    cout << "8. Hapus Belakang" << endl;
    cout << "9. Hapus Tengah" << endl;
    cout << "10. Hapus List" << endl;
    cout << "11. TAMPILKAN" << endl;
    cout << "0. KELUAR" << endl;
    cout << endl;
    cout << "Pilih Operasi : ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
      cout << "Masukan Nama : ";
      cin >> nama;

      cout << "Masukan NIM : ";
      cin >> nim;

      insertDepan(Data{nama, nim});

      cout << "Data telah ditambahkan" << endl;
      break;
    case 2:
      cout << "Masukan Nama : ";
      cin >> nama;

      cout << "Masukan NIM : ";
      cin >> nim;

      insertBelakang(Data{nama, nim});

      cout << "Data telah ditambahkan" << endl;
      break;
    case 3:
      cout << "Masukan Nama : ";
      cin >> nama;

      cout << "Masukan NIM : ";
      cin >> nim;

      cout << "Masukan Posisi : ";
      cin >> posisi;

      insertTengah(Data{nama, nim}, posisi);

      cout << "Data telah ditambahkan" << endl;
      break;
    case 4:
      cout << "Masukan Nama : ";
      cin >> nama;

      cout << "Masukan NIM : ";
      cin >> nim;

      ubahDepan(Data{nama, nim});
      break;
    case 5:
      cout << "Masukan Nama : ";
      cin >> nama;

      cout << "Masukan NIM : ";
      cin >> nim;

      ubahBelakang(Data{nama, nim});
      break;
    case 6:
      cout << "Masukan Nama : ";
      cin >> nama;

      cout << "Masukan NIM : ";
      cin >> nim;

      cout << "Masukan Posisi : ";
      cin >> posisi;

      ubahTengah(Data{nama, nim}, posisi);
      break;
    case 7:
      hapusDepan();
      break;
    case 8:
      hapusBelakang();
      break;
    case 9:
      cout << "Masukan Posisi : ";
      cin >> posisi;

      hapusTengah(posisi);
      break;
    case 10:
      clearList();
      break;
    case 11:
      tampil();
      break;
    case 0:
      isRunning = false;
      break;
    default:
      cout << "Pilihan tidak valid" << endl;
      break;
    }
  } while (isRunning);

  cout << "Terima kasih sudah menggunakan aplikasi kami" << endl;

  return 0;
}