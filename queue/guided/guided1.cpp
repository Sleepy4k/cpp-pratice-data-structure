#include <iostream>

using namespace std;

// queue array
int maksimalQueue = 5; // maksimal antrian
int front = 0;         // penanda antrian
int back = 0;          // penanda
string queueTeller[5]; // fungsi pengecekan

bool isFull() {
  // pengecekan antrian penuh atau tidak
  return back == maksimalQueue;
}

// fungsi pengecekan
bool isEmpty() {
  // antrian kosong atau tidak
  return back == 0;
}

// fungsi menambahkan antrian
void enqueueAntrian(string data) {
  if (isFull()) {
    cout << "antrian penuh" << endl;
    return;
  }

  if (isEmpty()) {
    queueTeller[0] = data;
    front++;
    back++;
    return;
  }

  queueTeller[back] = data;
  back++;
}

// fungsi mengurangi antrian
void dequeueAntrian() {
  if (isEmpty()) {
    cout << "antrian kosong" << endl;
    return;
  }

  for (int i = 0; i < back; i++) {
    queueTeller[i] = queueTeller[i + 1];
  }

  back--;
}

// fugsi menghitung banyak antrian
int countQueue() {
  return back;
}

// fungsi menghapus semua antrian
void clearQueue() {
  if (isEmpty()) {
    cout << "antrian kosong" << endl;
    return;
  }

  for (int i = 0; i < back; i++) {
    queueTeller[i] = "";
  }

  back = 0;
  front = 0;
}

// fungsi melihat antrian
void viewQueue() {
  cout << "data antrian teller : " << endl;

  for (int i = 0; i < maksimalQueue; i++) {
    if (queueTeller[i] != "") {
      cout << i + 1 << "." << queueTeller[i] << endl;
    } else {
      cout << i + 1 << ".(kosong)" << endl;
    }
  }
}

int main() {
  enqueueAntrian("Apri");
  enqueueAntrian("Pandu");
  viewQueue();
  cout << "jumlah antrian = " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "jumlah antrian = " << countQueue() << endl;

  clearQueue();
  viewQueue();
  cout << "jumlah antrian = " << countQueue() << endl;

  return 0;
}