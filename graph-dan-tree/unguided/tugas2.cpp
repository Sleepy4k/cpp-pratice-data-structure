#include <iostream>

using namespace std;

// Deklarasi Pohon
struct Pohon {
  char data_081;
  Pohon *left_081, *right_081, *parent_081;
} *root_081, *baru_081;

// Inisialisasi
void init() {
  root_081 = nullptr;
}

// Cek Node
bool isEmpty() {
  return root_081 == nullptr;
}

// Buat Node Baru
void buatNode(char data_081) {
  if (!isEmpty()) {
    cout << "\nPohon sudah dibuat" << endl;
    return;
  }

  baru_081 = new Pohon();
  baru_081->data_081 = data_081;
  baru_081->left_081 = nullptr;
  baru_081->right_081 = nullptr;
  baru_081->parent_081 = nullptr;

  root_081 = baru_081;

  cout << "\nNode " << data_081 << " berhasil dibuat menjadi root" << endl;
}

// Tambah Kiri
Pohon *insertLeft(char data_081, Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return nullptr;
  }

  // Cek apakah child kiri ada atau tidak
  // Jika ada maka tampilkan pesan bahwa node sudah ada
  if (node_081->left_081 != nullptr) {
    cout << "\nNode " << node_081->left_081->data_081 << " sudah ada di kiri " << node_081->data_081 << endl;
    return nullptr;
  }

  // Jika tidak ada maka buat node baru
  baru_081 = new Pohon();
  baru_081->data_081 = data_081;
  baru_081->left_081 = nullptr;
  baru_081->right_081 = nullptr;
  baru_081->parent_081 = node_081;

  // Tambahkan node baru ke kiri node parent
  node_081->left_081 = baru_081;

  cout << "\nNode " << data_081 << " berhasil ditambahkan di kiri " << node_081->data_081 << endl;

  return baru_081;
}

// Tambah Kanan
Pohon *insertRight(char data_081, Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return nullptr;
  }

  // Cek apakah child kanan ada atau tidak
  // Jika ada maka tampilkan pesan bahwa node sudah ada
  if (node_081->right_081 != nullptr) {
    cout << "\nNode " << node_081->right_081->data_081 << " sudah ada di kanan " << node_081->data_081 << endl;
    return nullptr;
  }

  // Jika tidak ada maka buat node baru
  baru_081 = new Pohon();
  baru_081->data_081 = data_081;
  baru_081->left_081 = nullptr;
  baru_081->right_081 = nullptr;
  baru_081->parent_081 = node_081;

  // Tambahkan node baru ke kanan node parent
  node_081->right_081 = baru_081;

  cout << "\nNode " << data_081 << " berhasil ditambahkan di kanan " << node_081->data_081 << endl;

  return baru_081;
}

// Ubah Data Tree
void update(char data_081, Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) {
    cout << "\nNode tidak ditemukan" << endl;
    return;
  }

  char temp_081 = node_081->data_081;
  node_081->data_081 = data_081;

  cout << "\nNode " << temp_081 << " berhasil diubah menjadi " << data_081 << endl;
}

// Lihat Isi Data Tree
void retrieve(Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) {
    cout << "\nNode tidak ditemukan" << endl;
    return;
  }

  cout << "\nNode " << node_081->data_081 << " ditemukan" << endl;
}

// Cari Data Tree
void find(Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) {
    cout << "\nNode tidak ditemukan" << endl;
    return;
  }

  cout << "\nData Node : " << node_081->data_081 << endl;
  cout << "Root : " << root_081->data_081 << endl;

  if (!node_081->parent_081) {
    cout << "Parent Node : Tidak ada" << endl;
  } else {
    cout << "Parent Node : " << node_081->parent_081->data_081 << endl;
  }

  if (node_081->parent_081 != nullptr && node_081->parent_081->left_081 != node_081 && node_081->parent_081->right_081 == node_081) {
    cout << "Sibling : " << node_081->parent_081->left_081->data_081 << endl;
  } else if (node_081->parent_081 != nullptr && node_081->parent_081->right_081 != node_081 && node_081->parent_081->left_081 == node_081) {
    cout << "Sibling : " << node_081->parent_081->right_081->data_081 << endl;
  } else {
    cout << "Sibling : Tidak ada" << endl;
  }

  if (!node_081->left_081) {
    cout << "Child Kiri : Tidak ada" << endl;
  } else {
    cout << "Child Kiri : " << node_081->left_081->data_081 << endl;
  }

  if (!node_081->right_081) {
    cout << "Child Kanan : Tidak ada" << endl;
  } else {
    cout << "Child Kanan : " << node_081->right_081->data_081 << endl;
  }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node_081 = root_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (node_081 == nullptr) return;

  cout << " " << node_081->data_081 << ", ";
  preOrder(node_081->left_081);
  preOrder(node_081->right_081);
}

// inOrder
void inOrder(Pohon *node_081 = root_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) return;

  inOrder(node_081->left_081);
  cout << " " << node_081->data_081 << ", ";
  inOrder(node_081->right_081);
}

// postOrder
void postOrder(Pohon *node_081 = root_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) return;

  postOrder(node_081->left_081);
  postOrder(node_081->right_081);
  cout << " " << node_081->data_081 << ", ";
}

// Hapus Node Tree
void deleteTree(Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) return;

  if (node_081 != root_081) {
    node_081->parent_081->left_081 = nullptr;
    node_081->parent_081->right_081 = nullptr;
  }

  deleteTree(node_081->left_081);
  deleteTree(node_081->right_081);

  if (node_081 == root_081) {
    delete root_081;
    root_081 = nullptr;
    return;
  }

  delete node_081;
}

// Hapus SubTree
void deleteSub(Pohon *node_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node_081) return;

  deleteTree(node_081->left_081);
  deleteTree(node_081->right_081);

  cout << "\nNode SubTree " << node_081->data_081 << " berhasil dihapus" << endl;
}

// Hapus Tree
void clear() {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  deleteTree(root_081);
  cout << "\nPohon berhasil dihapus" << endl;
}

// Cek Size Tree
int size(Pohon *node_081 = root_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return 0;
  }

  if (!node_081) return 0;

  return 1 + size(node_081->left_081) + size(node_081->right_081);
}

// Cek Height Tree
int height(Pohon *node_081 = root_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return 0;
  }

  if (!node_081) return 0;

  int heightKiri_081 = height(node_081->left_081);
  int heightKanan_081 = height(node_081->right_081);

  return 1 + (heightKiri_081 > heightKanan_081 ? heightKiri_081 : heightKanan_081);
}

// Karakteristik Tree
void charateristic() {
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << size() / height() << endl;
}

int getIndexOfNode(char data_081) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return -1;
  }

  Pohon *node_081 = root_081;

  for (int i = 0; i < size(); i++) {
    if (node_081->data_081 == data_081) {
      return i;
    }

    if (node_081->left_081) {
      node_081 = node_081->left_081;
    } else if (node_081->right_081) {
      node_081 = node_081->right_081;
    }
  }

  return -1;
}

int main() {
  init();

  char data_081, tmp_081;
  Pohon *node_081[50], *helper_081; // Array of Node
  int choice_081, temp_081, index_081 = 0, isRunning_081 = 1;

  do {
    cout << "Binary Tree Program" << endl;
    cout << "====================" << endl;
    cout << "1. Buat Node Baru" << endl;
    cout << "2. Tambah Node Kiri" << endl;
    cout << "3. Tambah Node Kanan" << endl;
    cout << "4. Ubah Data Node" << endl;
    cout << "5. Lihat Data Node" << endl;
    cout << "6. Cari Data Node" << endl;
    cout << "7. Penelusuran Tree" << endl;
    cout << "8. Hapus Node Tree" << endl;
    cout << "9. Hapus SubTree" << endl;
    cout << "10. Hapus Tree" << endl;
    cout << "11. Karakteristik Tree" << endl;
    cout << "12. Keluar" << endl;
    cout << "====================" << endl;
    cout << "Masukkan pilihan: ";
    cin >> choice_081;

    switch (choice_081) {
      case 1:
        if (index_081 > 0) {
          cout << "\nNode sudah dibuat" << endl;
          break;
        }

        cout << "\nMasukkan data node : ";
        cin >> data_081;

        buatNode(data_081);

        node_081[index_081] = root_081;
        index_081++;

        break;
      case 2:
        cout << "\nMasukan node yang ingin ditambahkan ke kiri : ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        cout << "\nMasukkan data node : ";
        cin >> data_081;

        helper_081 = insertLeft(data_081, node_081[temp_081]);
        node_081[index_081] = helper_081;
        index_081++;

        break;
      case 3:
        cout << "\nMasukan node yang ingin ditambahkan ke kanan : ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        cout << "\nMasukkan data node : ";
        cin >> data_081;

        helper_081 = insertRight(data_081, node_081[temp_081]);
        node_081[index_081] = helper_081;
        index_081++;

        break;
      case 4:
        cout << "\nMasukkan node yang ingin diubah datanya : ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        cout << "\nMasukkan data node : ";
        cin >> data_081;

        update(data_081, node_081[temp_081]);

        break;
      case 5:
        cout << "\nMasukkan node yang ingin dilihat : ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        retrieve(node_081[index_081]);

        break;
      case 6:
        cout << "\nMasukkan node yang ingin dicari : ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        find(node_081[index_081]);

        break;
      case 7:
        cout << "\npreOrder : ";
        preOrder();
        cout << endl;

        cout << "inOrder : ";
        inOrder();
        cout << endl;

        cout << "postOrder : ";
        postOrder();
        cout << endl;
        break;
      case 8:
        cout << "\nMasukkan node yang ingin dihapus : ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        deleteTree(node_081[temp_081]);
        
        break;
      case 9:
        cout << "\nMasukkan data node yang ingin dihapus: ";
        cin >> tmp_081;

        temp_081 = getIndexOfNode(tmp_081);

        if (temp_081 == -1 || temp_081 >= index_081 || !node_081[temp_081]) {
          cout << "\nNode tidak ditemukan" << endl;
          break;
        }

        deleteSub(node_081[temp_081]);

        break;
      case 10:
        clear();
        break;
      case 11:
        charateristic();
        break;
      case 12:
        isRunning_081 = 0;
        break;
      default:
        cout << "\nPilihan tidak valid" << endl;
        break;
    }

    if (choice_081 != 12) system("pause");
  } while (isRunning_081);

  return 0;
}
