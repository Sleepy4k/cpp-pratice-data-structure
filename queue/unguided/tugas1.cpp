#include <iostream>

using namespace std;

// Init struct for Queue method
struct Queue {
  int id;
  string name;
  Queue *next, *prev;
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
    current = current->next;
  }

  return size;
}

// fungsi menambahkan antrian
void enqueueAntrian(string data) {
  Queue *newQueue = new Queue();
  newQueue->id = queueSize() + 1;
  newQueue->name = data;
  newQueue->next = nullptr;
  newQueue->prev = nullptr;

  if (isEmpty()) {
    head = tail = newQueue;
    tail->next = nullptr;
    return;
  }

  tail->next = newQueue;
  newQueue->prev = tail;
  tail = newQueue;

  cout << "antrian " << data << " telah ditambahkan dengan nomor antrian " << newQueue->id << endl;
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

  head = head->next;

  cout << "antrian " << temp->name << " telah selesai dilayani pada antrian " << temp->id << endl;

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
    current = current->next;
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
    cout << "antrian " << current->id << " - " << current->name << endl;
    current = current->next;
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