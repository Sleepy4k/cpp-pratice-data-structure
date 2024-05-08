#include <iostream>
#include <string>

using namespace std;

char word[100];
int maximum = 100, top = 0;

bool isStackFull() {
  return top == maximum;
}

bool isStackEmpty() {
  return top < 1;
}

void clear() {
  for (int i = 0; i < top; i++) {
    word[i] = '\0';
  }

  top = 0;
}

void push(char data) {
  if (isStackFull()) cout << "Stack is full!" << endl;
  else {
    word[top] = data;
    top++;
  }
}

void display() {
  if (isStackEmpty()) {
    cout << "Stack is empty!" << endl;
    return;
  }

  cout << "Word: ";
  for (int i = 0; i < top; i++) {
    cout << word[i];
  }

  cout << "\nReversed Word: ";
  for (int i = top - 1; i >= 0; i--) {
    cout << word[i];
  }

  cout << endl;
}

void reverse(string data) {
  int dataLength = data.length();

  if (dataLength > maximum) {
    cout << "Kata terlalu panjang! maksimal 100 kakrakter" << endl;
    return;
  }

  if (!isStackEmpty()) clear();

  for (int i = 0; i < dataLength; i++) {
    push(data[i]);
  }
}

int main() {
  int choice;
  string input;
  char isRunning = 'y';

  do {
    cout << "Palindrom Word" << endl;
    cout << "=========================" << endl;
    cout << "Input word: ";
    getline(cin, input);

    reverse(input);
    display();

    cout << "Do you want to continue? (Y/n): ";
    cin >> isRunning;
    cin.ignore();
  } while (tolower(isRunning) == 'y');

  return 0;
}
