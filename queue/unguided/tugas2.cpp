#include <iostream>

using namespace std;

// Init struct for Queue method
struct Queue {
  string name, nim;
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
void enqueueAntrian(string name, string nim) {
  Queue *newQueue = new Queue();
  newQueue->name = name;
  newQueue->nim = nim;
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

  cout << "antrian " << name << " telah ditambahkan dengan nim " << nim << endl;
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

  cout << "antrian " << temp->name << " telah selesai dilayani dengan nim " << temp->nim << endl;

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
    cout << "antrian " << current->name << " - " << current->nim << endl;
    current = current->next;
  }
}

int main() {
  init();

  enqueueAntrian("Apri", "2311102081");
  enqueueAntrian("Pandu", "2311102082");
  viewQueue();

  dequeueAntrian();
  viewQueue();

  clearQueue();
  viewQueue();

  return 0;
}