#include <iostream>

using namespace std;

// Deklarasi Pohon
struct Pohon {
  char data;
  Pohon *left, *right, *parent;
} *root, *baru;

// Inisialisasi
void init() {
  root = nullptr;
}

// Cek Node
bool isEmpty() {
  return root == nullptr;
}

// Buat Node Baru
void buatNode(char data) {
  if (!isEmpty()) {
    cout << "\nPohon sudah dibuat" << endl;
    return;
  }

  baru = new Pohon();
  baru->data = data;
  baru->left = nullptr;
  baru->right = nullptr;
  baru->parent = nullptr;

  root = baru;

  cout << "\nNode " << data << " berhasil dibuat menjadi root" << endl;
}

// Tambah Kiri
Pohon *insertLeft(char data, Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return nullptr;
  }

  // Cek apakah child kiri ada atau tidak
  // Jika ada maka tampilkan pesan bahwa node sudah ada
  if (node->left != nullptr) {
    cout << "\nNode " << node->left->data << " sudah ada di kiri " << node->data << endl;
    return nullptr;
  }

  // Jika tidak ada maka buat node baru
  baru = new Pohon();
  baru->data = data;
  baru->left = nullptr;
  baru->right = nullptr;
  baru->parent = node;

  // Tambahkan node baru ke kiri node parent
  node->left = baru;

  cout << "\nNode " << data << " berhasil ditambahkan di kiri " << node->data << endl;

  return baru;
}

// Tambah Kanan
Pohon *insertRight(char data, Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return nullptr;
  }

  // Cek apakah child kanan ada atau tidak
  // Jika ada maka tampilkan pesan bahwa node sudah ada
  if (node->right != nullptr) {
    cout << "\nNode " << node->right->data << " sudah ada di kanan " << node->data << endl;
    return nullptr;
  }

  // Jika tidak ada maka buat node baru
  baru = new Pohon();
  baru->data = data;
  baru->left = nullptr;
  baru->right = nullptr;
  baru->parent = node;

  // Tambahkan node baru ke kanan node parent
  node->right = baru;

  cout << "\nNode " << data << " berhasil ditambahkan di kanan " << node->data << endl;

  return baru;
}

// Ubah Data Tree
void update(char data, Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) {
    cout << "\nNode tidak ditemukan" << endl;
    return;
  }

  char temp = node->data;
  node->data = data;

  cout << "\nNode " << temp << " berhasil diubah menjadi " << data << endl;
}

// Lihat Isi Data Tree
void retrieve(Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) {
    cout << "\nNode tidak ditemukan" << endl;
    return;
  }

  cout << "\nNode " << node->data << " ditemukan" << endl;
}

// Cari Data Tree
void find(Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) {
    cout << "\nNode tidak ditemukan" << endl;
    return;
  }

  cout << "\nData Node : " << node->data << endl;
  cout << "Root : " << root->data << endl;

  if (!node->parent) {
    cout << "Parent Node : Tidak ada" << endl;
  } else {
    cout << "Parent Node : " << node->parent->data << endl;
  }

  if (node->parent != nullptr && node->parent->left != node && node->parent->right == node) {
    cout << "Sibling : " << node->parent->left->data << endl;
  } else if (node->parent != nullptr && node->parent->right != node && node->parent->left == node) {
    cout << "Sibling : " << node->parent->right->data << endl;
  } else {
    cout << "Sibling : Tidak ada" << endl;
  }

  if (!node->left) {
    cout << "Child Kiri : Tidak ada" << endl;
  } else {
    cout << "Child Kiri : " << node->left->data << endl;
  }

  if (!node->right) {
    cout << "Child Kanan : Tidak ada" << endl;
  } else {
    cout << "Child Kanan : " << node->right->data << endl;
  }
}

// Penelusuran (Traversal)
// preOrder
void preOrder(Pohon *node = root) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (node == nullptr) return;

  cout << " " << node->data << ", ";
  preOrder(node->left);
  preOrder(node->right);
}

// inOrder
void inOrder(Pohon *node = root) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) return;

  inOrder(node->left);
  cout << " " << node->data << ", ";
  inOrder(node->right);
}

// postOrder
void postOrder(Pohon *node = root) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) return;

  postOrder(node->left);
  postOrder(node->right);
  cout << " " << node->data << ", ";
}

// Hapus Node Tree
void deleteTree(Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) return;

  if (node != root) {
    node->parent->left = nullptr;
    node->parent->right = nullptr;
  }

  deleteTree(node->left);
  deleteTree(node->right);

  if (node == root) {
    delete root;
    root = nullptr;
    return;
  }

  delete node;
}

// Hapus SubTree
void deleteSub(Pohon *node) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  if (!node) return;

  deleteTree(node->left);
  deleteTree(node->right);

  cout << "\nNode SubTree " << node->data << " berhasil dihapus" << endl;
}

// Hapus Tree
void clear() {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return;
  }

  deleteTree(root);
  cout << "\nPohon berhasil dihapus" << endl;
}

// Cek Size Tree
int size(Pohon *node = root) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return 0;
  }

  if (!node) return 0;

  return 1 + size(node->left) + size(node->right);
}

// Cek Height Tree
int height(Pohon *node = root) {
  if (isEmpty()) {
    cout << "\nSilahkan buat node terlebih dahulu" << endl;
    return 0;
  }

  if (!node) return 0;

  int heightKiri = height(node->left);
  int heightKanan = height(node->right);

  return 1 + (heightKiri > heightKanan ? heightKiri : heightKanan);
}

// Karakteristik Tree
void charateristic() {
  cout << "\nSize Tree : " << size() << endl;
  cout << "Height Tree : " << height() << endl;
  cout << "Average Node of Tree : " << size() / height() << endl;
}

int main() {
  init();
  buatNode('A');

  Pohon *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ;

  nodeB = insertLeft('B', root);
  nodeC = insertRight('C', root);
  nodeD = insertLeft('D', nodeB);
  nodeE = insertRight('E', nodeB);
  nodeF = insertLeft('F', nodeC);
  nodeG = insertLeft('G', nodeE);
  nodeH = insertRight('H', nodeE);
  nodeI = insertLeft('I', nodeG);
  nodeJ = insertRight('J', nodeG);

  update('Z', nodeC);
  update('C', nodeC);

  retrieve(nodeC);

  find(nodeC);

  cout << "\nPreOrder :" << endl;
  preOrder(root);

  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder(root);

  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder(root);

  cout << "\n" << endl;
  charateristic();

  deleteSub(nodeE);

  cout << "\nPreOrder :" << endl;
  preOrder();

  cout << "\n" << endl;
  charateristic();

  return 0;
}
