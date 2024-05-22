#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void selection_sort(char word_081[], int length_081) {
  int temp, min, i, j;

  for (i = 0; i < length_081; i++) {
    min = i;

    for (j = i + 1; j < length_081; j++) {
      if (word_081[j] > word_081[min]) continue;

      min = j;
    }

    temp = word_081[i];
    word_081[i] = word_081[min];
    word_081[min] = temp;
  }
}

void binary_search(char word_081[], int length_081, char target_081) {
  int start = 0, end = length_081 - 1, mid, is_found = false;

  while (!is_found && start <= end) {
    mid = (start + end) / 2;

    if (word_081[mid] == target_081) is_found = true;
    else if (word_081[mid] < target_081) start = mid + 1;
    else end = mid - 1;
  }

  if (is_found) cout << "Data ditemukan pada indeks ke-" << mid << endl;
  else cout << "Data tidak ditemukan" << endl;
}

int main() {
  string tempWord_081;

  cout << "Mencari huruf dalam kata" << endl;
  cout << "========================" << endl;
  cout << "Masukkan kata : ";
  getline(cin, tempWord_081);

  int length_081 = tempWord_081.length();
  char word_081[length_081 + 1], target_081;

  for (int i = 0; i < length_081; i++) {
    if (tempWord_081[i] == ' ' || tempWord_081[i] == '\0') continue;

    word_081[i] = tolower(tempWord_081[i]);
  }

  cout << "Masukkan huruf yang dicari : ";
  cin >> target_081;
  cout << endl;

  cout << "Data diurutkan : ";
  selection_sort(word_081, length_081);

  for (int i = 0; i < length_081; i++) {
    cout << setw(3) << word_081[i];
  }

  cout << "\n" << endl;

  binary_search(word_081, length_081, tolower(target_081));

  return 0;
}
