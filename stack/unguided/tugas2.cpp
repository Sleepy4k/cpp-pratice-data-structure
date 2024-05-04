#include <iostream>
#include <string>
#include <string.h>

using namespace std;

char word[100];
int maximum = 100, top = 0;

bool isStackEmpty() {
  return top < 1;
}

void clear() {
  for (int i = 0; i < top; i++) {
    word[i] = '\0';
  }

  top = 0;
  cout << "Stack is cleared!" << endl;
}

bool push(string data) {
  int dataLength = data.length();

  if (dataLength > maximum) {
    cout << "Kata terlalu panjang! maksimal 100 kakrakter" << endl;
    return false;
  }

  if (!isStackEmpty()) clear();

  top += dataLength;
  strcpy(word, data.c_str());

  return true;
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

int main() {
  int choice;
  string input;
  char isRunning = 'y';

  do {
    cout << "Reverse Word" << endl;
    cout << "=========================" << endl;
    cout << "Input word: ";
    getline(cin, input);

    if (push(input)) {
      display();
    }

    cout << "Do you want to continue? (Y/n): ";
    cin >> isRunning;
    cin.ignore();
  } while (tolower(isRunning) == 'y');

  return 0;
}
