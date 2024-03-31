#include <map>
#include <iostream>

using namespace std;

/**
 * Membuat struct CityRecord untuk menyimpan data kota
 *
 * @struct CityRecord
 */
struct CityRecord {
  string name_081;
  int population_081;
  double tax_081;
};

int main() {
  // Inisiasi array dengan nama city bertipe data struct CityRecord
  CityRecord city_081[4];

  // Isi tiap slot array dengan kota sekitar purwokerto
  city_081[0] = {"Purwokerto", 250, 2.4};
  city_081[1] = {"Kebumen", 100, 2.4};
  city_081[2] = {"Jogja", 350, 2.4};
  city_081[3] = {"Tegal", 81, 2.4};

  // Ambil panjang array pada variable city
  int cityLength_081 = sizeof(city_081) / sizeof(*city_081);

  // Lakukan perulangan dengan iterator mulai dari 0 hingga panjang array city
  for (int i = 0; i < cityLength_081; i++) {
    // Jika nama kota bukan tegal maka lewati perulangan sekarang
    if (city_081[i].name_081 != "Tegal") continue;

    // Cetak data kota tegal
    cout << "Current city is " << city_081[i].name_081 << endl;
    cout << "With total population " << city_081[i].population_081 << endl;
    cout << "And average tax ratio " << city_081[i].tax_081 << endl;
    cout << "==========================" << endl;
  }

  // Inisiasi map dengan variable cityMap
  map<string, CityRecord> cityMap_081;

  // Isi tiap slot map sejumlah 4 dengan kota sekitar purwokerto
  cityMap_081["Purwokerto"] = CityRecord { "Purwokerto", 250, 2.4 };
  cityMap_081["Kebumen"] = CityRecord { "Kebumen", 100, 2.4 };
  cityMap_081["Jogja"] = CityRecord { "Jogja", 350, 2.4 };
  cityMap_081["Tegal"] = CityRecord { "Tegal", 81, 2.4 };

  // Cek apakah kota tegal terdapat pada cityMap
  if (cityMap_081.find("Tegal") != cityMap_081.end()) {
    // Jika ada cetak data kota tegal
    cout << "Current city is " << cityMap_081["Tegal"].name_081 << endl;
    cout << "With total population " << cityMap_081["Tegal"].population_081 << endl;
    cout << "And average tax ratio " << cityMap_081["Tegal"].tax_081 << endl;
    cout << "==========================" << endl;
  }

  return 0;
}
