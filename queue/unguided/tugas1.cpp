#include <iostream>

using namespace std;

// Init struct for Queue method
struct Queue {
  int id_081;
  string name_081;
  Queue *next_081, *prev_081;
} *head, *tail;

// fungsi untuk inisisalisasi antrian
void init() {
  // Set head and tail to null pointer
  head = tail = nullptr;
}

// fungsi pengecekan
bool isEmpty() {
  // antrian kosong atau tidak
  return head == nullptr;
}

// fungsi menghitung banyak antrian
int queueSize() {
  // menghitung banyak antrian
  int size = 0;

  if (head == nullptr) return size;

  Queue *current = head;

  while (current) {
    size++;
    current = current->next_081;
  }

  return size;
}

// fungsi menambahkan antrian
void enqueueAntrian(string data) {
  Queue *newQueue = new Queue();
  newQueue->id_081 = queueSize() + 1;
  newQueue->name_081 = data;
  newQueue->next_081 = nullptr;
  newQueue->prev_081 = nullptr;

  if (isEmpty()) {
    head = tail = newQueue;
    tail->next_081 = nullptr;
    return;
  }

  tail->next_081 = newQueue;
  newQueue->prev_081 = tail;
  tail = newQueue;

  cout << "antrian " << data << " telah ditambahkan dengan nomor antrian " << newQueue->id_081 << endl;
}

// fungsi mengurangi antrian
void dequeueAntrian() {
  if (isEmpty()) {
    cout << "antrian kosong" << endl;
    return;
  }

  Queue *temp = head;

  if (head == tail) {
    head = tail = nullptr;
    return;
  }

  head = head->next_081;

  cout << "antrian " << temp->name_081 << " telah selesai dilayani pada antrian " << temp->id_081 << endl;

  delete temp;
}

// fungsi menghapus semua antrian
void clearQueue() {
  if (isEmpty()) {
    cout << "antrian kosong" << endl;
    return;
  }

  Queue *current = head;

  while (current) {
    Queue *temp = current;
    current = current->next_081;
    delete temp;
  }

  head = tail = nullptr;
  cout << "semua antrian telah selesai dilayani" << endl;
}

// fungsi melihat antrian
void viewQueue() {
  if (isEmpty()) {
    cout << "antrian kosong" << endl;
    return;
  }

  Queue *current = head;

  cout << "antrian yang sedang dilayani:" << endl;
  while (current) {
    cout << "antrian " << current->id_081 << " - " << current->name_081 << endl;
    current = current->next_081;
  }
}

int main() {
  init();

  enqueueAntrian("Apri");
  enqueueAntrian("Pandu");
  viewQueue();

  dequeueAntrian();
  viewQueue();

  clearQueue();
  viewQueue();

  return 0;
}