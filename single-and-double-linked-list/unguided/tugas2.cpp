#include <iostream>

using namespace std;

struct Data {
  string name_081;
  int price_081;
};

struct Node {
  Data data_081;
  Node *prev;
  Node *next;
};

class DoublyLinkedList {
private:
  Node *head, *tail;

  bool isEmpty() {
    if (head == nullptr)
      return true;

    return false;
  }

  int totalList() {
    Node *current = head;

    int total = 0;

    while (current != nullptr) {
      total++;
      current = current->next;
    }

    return total;
  }

public:
  DoublyLinkedList() { head = tail = nullptr; }

  void addData(Data data) {
    Node *newNode = new Node;
    newNode->data_081 = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (isEmpty()) {
      head = tail = newNode;
      return;
    }

    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
  }

  void deleteData(string name) {
    Node *current = head, *helper = nullptr, *temp;

    if (isEmpty()) {
      cout << "List masih kosong!" << endl;
      return;
    }

    int index = 1;

    while (current != nullptr) {
      if (current->data_081.name_081 == name)
        break;

      current = current->next;
      index++;
    }

    if (current == nullptr) {
      cout << "Data tidak ditemukan" << endl;
      return;
    }

    if (index == 1) {
      head = current->next;
      helper = head->next;
      helper->prev = head;
      delete current;
      return;
    }

    if (index == totalList()) {
      tail = current->prev;
      tail->next = nullptr;
      delete current;
      return;
    }

    temp = current;
    current = temp->prev;
    helper = temp->next;

    if (helper != nullptr) {
      helper->prev = current;
      current->next = helper;
    }

    delete temp;
  }

  void updateData(string oldName, Data data) {
    Node *current = head, *helper = nullptr, *temp;

    if (isEmpty()) {
      cout << "List masih kosong!" << endl;
      return;
    }

    while (current != nullptr) {
      if (current->data_081.name_081 == oldName)
        break;

      current = current->next;
    }

    if (current == nullptr) {
      cout << "Data tidak ditemukan" << endl;
      return;
    }

    current->data_081 = data;
  }

  void addDataWithIndex(int location, Data data) {
    Node *newNode, *current = head, *helper;

    if (isEmpty()) {
      addData(data);
      return;
    }

    int index = 1;

    while (current != nullptr) {
      if (index == location)
        break;

      index++;
      current = current->next;
    }

    newNode = new Node;
    newNode->data_081 = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (index == 1) {
      helper = head;
      helper->prev = newNode;
      newNode->next = helper;
      head = newNode;
      return;
    }

    if (index == totalList()) {
      helper = tail;
      helper->next = newNode;
      tail = newNode;
      tail->prev = helper;
      return;
    }

    helper = current;
    current = current->prev;
    current->next = newNode;
    helper->prev = newNode;

    newNode->next = helper;
    newNode->prev = current;
  }

  void deleteDataWithIndex(int location) {
    Node *current = head, *helper = nullptr, *temp;

    if (isEmpty()) {
      cout << "List masih kosong!" << endl;
      return;
    }

    if (location > totalList()) {
      cout << "Lokasi diluar jangkauan jumlah list" << endl;
      return;
    }

    int index = 1;

    while (current != nullptr) {
      if (index == location)
        break;

      index++;
      current = current->next;
    }

    if (index == 1) {
      head = current->next;
      helper = head->next;
      helper->prev = head;
      delete current;
      return;
    }

    if (index == totalList()) {
      tail = current->prev;
      tail->next = nullptr;
      delete current;
      return;
    }

    temp = current;
    current = temp->prev;
    helper = temp->next;

    if (helper != nullptr) {
      helper->prev = current;
      current->next = helper;
    }

    delete temp;
  }

  void deleteAllData() {
    Node *current = head, *helper;

    while (current != nullptr) {
      helper = current;
      current = current->next;

      delete helper;
    }

    head = tail = nullptr;

    cout << "List berhasil terhapus!" << endl;
  }

  void display() {
    Node *current = head;

    if (isEmpty()) {
      cout << "List masih kosong!" << endl;
      return;
    }

    int index = 1;

    cout << "=======================" << endl;

    while (current != nullptr) {
      cout << "Data ke " << index << endl;
      cout << "Nama Produk : " << current->data_081.name_081
           << "\tHarga : " << current->data_081.price_081 << endl;
      current = current->next;
      index++;
    }

    cout << "=======================" << endl;
  }
};

int main() {
  DoublyLinkedList productList;

  productList.addData(Data{"Originote", 60000});
  productList.addData(Data{"Somethinc", 150000});
  productList.addData(Data{"Skintific", 100000});
  productList.addData(Data{"Wardah", 50000});
  productList.addData(Data{"Hanasui", 30000});

  string name, oldName;
  int choice, price, location;
  bool isRunning = true;

  do {
    cout << "Toko Skincare Purwokerto" << endl;
    cout << "1. Tambah Data" << endl;
    cout << "2. Hapus Data" << endl;
    cout << "3. Update Data" << endl;
    cout << "4. Tambah Data Urutan Tertentu" << endl;
    cout << "5. Hapus Data Urutan Tertentu" << endl;
    cout << "6. Hapus Seluruh Data" << endl;
    cout << "7. Tampilkan Data" << endl;
    cout << "8. Keluar" << endl;
    cout << "=========================" << endl;
    cout << "Pilih menu : ";
    cin >> choice;

    switch (choice) {
    case 1:
      cout << "Masukan data nama : ";
      cin >> name;

      cout << "Masukan data harga : ";
      cin >> price;

      productList.addData(Data{name, price});
      break;
    case 2:
      cout << "Masukan data nama : ";
      cin >> name;

      productList.deleteData(name);
      break;
    case 3:
      cout << "Masukan data nama : ";
      cin >> name;

      cout << "Masukan data harga : ";
      cin >> price;

      cout << "Masukan nama data lama : ";
      cin >> oldName;

      productList.updateData(oldName, Data{name, price});
      break;
    case 4:
      cout << "Masukan data nama : ";
      cin >> name;

      cout << "Masukan data harga : ";
      cin >> price;

      cout << "Masukan lokasi data : ";
      cin >> location;

      productList.addDataWithIndex(location, Data{name, price});
      break;
    case 5:
      cout << "Masukan lokasi data : ";
      cin >> location;

      productList.deleteDataWithIndex(location);
      break;
    case 6:
      productList.deleteAllData();
      break;
    case 7:
      productList.display();
      break;
    case 8:
      isRunning = false;
      break;
    default:
      cout << "Pilihan menu tidak valid" << endl;
      break;
    }
  } while (isRunning);

  return 0;
}