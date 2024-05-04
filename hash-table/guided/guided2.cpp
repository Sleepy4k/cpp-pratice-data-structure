#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int table_size = 11;

string name;
string phone_number;

class hashnode {
public:
  string name;
  string phone_number;

  hashnode(string name, string phone_number) {
    this->name = name;
    this->phone_number = phone_number;
  }
};

class hashmap {
private:
  vector<hashnode *> table[table_size];

public:
  // hash function
  int hashfunc(string key) {
    int hash_val = 0;

    for (char c : key) {
      hash_val += c;
    }

    return hash_val % table_size;
  }

  // insertion
  void insert(string name, string phone_number) {
    int hash_val = hashfunc(name);

    for (auto node : table[hash_val]) {
      if (node->name == name) {
        node->phone_number = phone_number;
        return;
      }
    }

    table[hash_val].push_back(new hashnode(name, phone_number));
  }

  // deletion
  void remove(string name) {
    int hash_val = hashfunc(name);

    for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
      if ((*it)->name == name) {
        table[hash_val].erase(it);
        return;
      }
    }
  }

  // searching
  string searchbyname(string name) {
    int hash_val = hashfunc(name);

    for (auto node : table[hash_val]) {
      if (node->name == name) {
        return node->phone_number;
      }
    }

    return "";
  }

  // transversing
  void print() {
    for (int i = 0; i < table_size; i++) {
      cout << i << ": ";

      for (auto pair : table[i]) {
        if (pair != nullptr) {
          cout << "[" << pair->name << ", " << pair->phone_number << "]";
        }
      }

      cout << endl;
    }
  }
};

int main() {
  hashmap employee_map;

  employee_map.insert("mistah", "1234");
  employee_map.insert("pastah", "5678");
  employee_map.insert("ghana", "91011");

  cout << "nomer hp mistah : " << employee_map.searchbyname("mistah") << endl;
  cout << "phone hp pastah : " << employee_map.searchbyname("pastah") << endl;

  employee_map.remove("mistah");
  cout << "nomer hp mistah setelah dihapus : "
       << employee_map.searchbyname("mistah") << endl
       << endl;

  cout << "hash table : " << endl;
  employee_map.print();

  return 0;
}
