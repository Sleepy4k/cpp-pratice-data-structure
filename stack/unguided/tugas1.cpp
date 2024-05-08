#include <iostream>
#include <string>

using namespace std;

char word[100];
int maximum = 100, minimum = 3, top = 0;

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

void pop() {
  if (isStackEmpty()) {
    cout << "Stack is empty!" << endl;
    return;
  }

  word[top - 1] = '\0';
  top--;
}

void display(string data) {
  if (isStackEmpty()) {
    cout << "Stack is empty!" << endl;
    return;
  }

  int dataLength = data.length();

  for (int i = 0; i < dataLength; i++) {
    if (data[i] != word[top - 1]) {
      cout << "Kata bukan palindrom" << endl;
      return;
    }

    pop();
  }

  cout << "Kata palindrom" << endl;
}

void palindrom(string data) {
  int dataLength = data.length();

  if (dataLength < minimum) {
    cout << "Kata terlalu pendek! minimal 3 karakter" << endl;
    return;
  } else if (dataLength > maximum) {
    cout << "Kata terlalu panjang! maksimal 100 kakrakter" << endl;
    return;
  }

  if (!isStackEmpty()) clear();

  for (int i = 0; i < dataLength; i++) {
    push(data[i]);
  }
}

string removeAdditionalCharacter(string data) {
  string result = "";

  for (int i = 0; i < data.length(); i++) {
    if (isalpha(data[i])) {
      result += tolower(data[i]);
    }
  }

  return result;
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

    input = removeAdditionalCharacter(input);

    palindrom(input);
    display(input);

    cout << "Do you want to continue? (Y/n): ";
    cin >> isRunning;
    cin.ignore();
  } while (tolower(isRunning) == 'y');

  return 0;
}
