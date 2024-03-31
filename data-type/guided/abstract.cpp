#include <stdio.h>
#include <string.h>

struct Mahasiswa_081 {
  char name_081[50];
  char address_081[100];
  int age_081;
};

int main() {
  struct Mahasiswa_081 mhs1_081, mhs2_081; 

  strcpy(mhs1_081.name_081, "Dian");
  strcpy(mhs1_081.address_081, "Mataram");
  mhs1_081.age_081 = 22;

  strcpy(mhs2_081.name_081, "Bambang");
  strcpy(mhs2_081.address_081, "Surabaya");
  mhs2_081.age_081 = 23;

  printf("## Mahasiswa 1 ##\n");
  printf("Nama: %s\n", mhs1_081.name_081);
  printf("Alamat: %s\n", mhs1_081.address_081);
  printf("Umur: %d\n", mhs1_081.age_081);

  printf("\n");

  printf("## Mahasiswa 2 ##\n");
  printf("Nama: %s\n", mhs2_081.name_081);
  printf("Alamat: %s\n", mhs2_081.address_081);
  printf("Umur: %d\n", mhs2_081.age_081);

  return 0;
}