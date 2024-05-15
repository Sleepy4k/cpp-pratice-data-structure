#include <iostream>
#include <string>

using namespace std;

int search_vocal(char word_081[], int length_081) {
  int i, j, found = 0;
  char vocal_081[5] = {'a', 'i', 'u', 'e', 'o'};

  for (i = 0; i < length_081; i++) {
    for (j = 0; j < 5; j++) {
      if (word_081[i] != vocal_081[j]) continue;

      found++;
      break;
    }
  }

  return found;
}

int main() {
  string tempWord_081;

  cout << "Mencari huruf vokal dalam kata" << endl;
  cout << "==============================" << endl;
  cout << "Masukkan kata : ";
  getline(cin, tempWord_081);

  int length_081 = tempWord_081.length();
  char word_081[length_081 + 1];

  for (int i = 0; i < length_081; i++) {
    if (tempWord_081[i] == ' ' || tempWord_081[i] == '\0') continue;

    word_081[i] = tempWord_081[i];
  }

  cout << endl;
  cout << "Jumlah huruf vokal dalam kata '" << tempWord_081 << "' adalah " << search_vocal(word_081, length_081) << endl;

  return 0;
}
