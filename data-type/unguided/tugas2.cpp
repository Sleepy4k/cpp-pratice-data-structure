#include <cstring>
#include <iostream>

using namespace std;

/**
 * Membuat class Car untuk mengatur data kendaraan
 *
 * @class Car
 */
class Car {
  // Inisiasi variable topspeed dengan default value 0
  double topspeed_081 = 0;

  public:
    // Inisiasi variable untuk menyimpan nama dan tipe mesin kendaraan
    char name_081[100], engine_081[100];

    // Inisiasi variable untuk menyimpan data kecepatan kendaraan
    double speed_081 = 0;

    // Inisiasi variable untuk menyimpan data total gigi kendaraan
    int gear_081 = 3;
    
    /**
     * Prosedural untuk mencetak tiap nilai dari public maupun private variable
     *
     * @return void
     */
    void print() {
      topspeed_081 = speed_081 * gear_081;
      
      cout << "=================" << endl;
      cout << "Nama kendaraan " << name_081 << endl;
      cout << "Jenis mesin " << engine_081 << endl;
      cout << "Kecepatan kendaraan " << speed_081 << endl;
      cout << "Total roda gigi " << gear_081 << endl;
      cout << "Kecepatan maksimal " << topspeed_081 << endl;
      cout << "=================" << endl;
    }
};

/**
 * Membuat struktur Driver untuk menyimpan data pembalap
 *
 * @struct Driver
 */
struct Driver {
  string nama_081, team_081;
  int number_081;
};

int main() {
  // Inisiasi variable car dengan tipe data class Car
  Car car_081;

  // Isi data nama dan mesin dengan fungsi strcpy
  // Digunakan untuk mengubah string ke tipe data char
  strcpy(car_081.name_081, "RB20");
  strcpy(car_081.engine_081, "V6");

  // Isi nilai dengan integer
  car_081.gear_081 = 8;
  car_081.speed_081 = 45;

  // Cetak data kendaraan
  car_081.print();

  //Inisiasi variable driver dengan tipe data struct Driver
  Driver driver_081[2];

  // Isi nilai struct
  driver_081[0] = { "Max Verstappen", "Red Bull Power Train Honda", 1 };
  driver_081[1] = { "Apri Pandu Wicaksono", "Red Bull Power Train Honda", 81 };

  // Cetak nilai dari struct pada variable driver
  for (int i = 0; i < sizeof(driver_081) / sizeof(*driver_081); i++) {
    cout << "Nama pembalap " << driver_081[i].nama_081 << endl;
    cout << "Team pembalap " << driver_081[i].team_081 << endl;
    cout << "Nomor pembalap " << driver_081[i].number_081 << endl;
  }

  return 0;
}
