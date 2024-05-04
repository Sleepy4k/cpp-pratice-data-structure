#include <iostream>

using namespace std;

string book[5];
int maximum = 5, top = 0;

bool isStackFull() {
  return (top == maximum);
}

bool isStackEmpty() {
  return (top < 1);
}

int stackSize() {
  return top;
}

void push(string title) {
  if (isStackFull()) cout << "Stack is full!" << endl;
  else {
    book[top] = title;
    top++;
  }
}

void pop() {
  if (isStackEmpty()) cout << "Stack is empty!" << endl;
  else {
    top--;
    cout << "Popped book: " << book[top] << endl;
  }
}

void find(int position) {
  if (isStackEmpty()) cout << "Stack is empty!" << endl;
  else if (position < 1 || position > top) cout << "Invalid position!" << endl;
  else cout << "Book at position " << position << ": " << book[top - position] << endl;
}

void change(int position, string title) {
  if (isStackEmpty()) cout << "Stack is empty!" << endl;
  else if (position < 1 || position > top) cout << "Invalid position!" << endl;
  else {
    string oldTitle = book[top - position];
    book[top - position] = title;
    cout << "Changed book at position " << position << " from " << oldTitle << " to " << title << endl;
  }
}

void clear() {
  if (isStackEmpty()) cout << "Stack is empty!" << endl;
  else {
    for (int i = 0; i < top; i++) {
      book[i] = "";
    }

    top = 0;
    cout << "Stack is cleared!" << endl;
  }
}

void display() {
  if (isStackEmpty()) cout << "Stack is empty!" << endl;
  else {
    cout << "Books in the stack:" << endl;
    for (int i = top - 1; i >= 0; i--) {
      cout << book[i] << endl;
    }
  }
}

int main() {
  push("Kalkulus");
  push("Struktur Data");
  push("Matematika Diskrit");
  push("Dasar Multimedia");
  push("Inggris");
  display();

  cout << endl;
  cout << "Apakah stack penuh? " << (isStackFull() ? "Ya" : "Tidak") << endl;
  cout << "Apakah stack kosong? " << (isStackEmpty() ? "Ya" : "Tidak") << endl;
  cout << endl;

  find(2);
  pop();

  cout << "Banyak buku di stack: " << stackSize() << endl;
  cout << endl;

  change(2, "Bahasa Jerman");
  display();

  cout << endl;

  clear();
  cout << "Banyak buku di stack: " << stackSize() << endl;

  display();

  return 0;
}