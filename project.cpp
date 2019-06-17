#include <iostream>
#define MAX 100
using namespace std;

/* struct pilihan {
  int id;
  char menu[MAX];
  double harga;   
}client;*/
 
/*void menu() {
    int jml, i, total, banyak;
    char nama[50];
    double price[50];

    cout << "\t\tDaftar Menu :\n";
    cout << "Menu :             Harga:\n";
    cout << "1. Ayam Goreng     Rp. 10.000\n";
    //int price_1 = 10000;
    cout << "2. Nasi Goreng     Rp. 12.000\n";
    //int price_2 = 12000; 
    cout << "3. Es Teh          Rp. 2.000\n";
    //int price_3 = 2000;
    cout << "4. Es Jeruk        Rp. 3.000\n";
    //int price_4 = 3000;
    cout << "5. Es Campur       Rp. 8.000\n\n";
    //int price_5 = 8000;

    cout << "Masukkan jumlah menu yang dipesan : "; cin >> jml;
    for (i = 0; i < jml; i++) {
        cout << "Menu ke - [" << i+1 << "] :\n";
        cout << "Nama   : "; cin >> nama[i];
        cout << "Harga  : "; cin >> price[i];
        cout << "Jumlah : "; cin >> banyak;

        total = banyak * price[i];
        cout << "Total Harga Rp." << total << endl;
    }
    
    
}*/

int main() {
    /*int pilihan;
    cout << "1. Daftar menu \n  2.Input\n";*/
    int jml, i, total, banyak, paket;
    string nama[50];
    double price[100];
    double bayar = 0;
    long harga;

    cout << "\t\tDaftar Menu :\n";
    cout << "Menu :                                   Harga:\n";
    cout << "1. Ayam goreang sayap + nasi + es teh    Rp. 9.900\n";
    cout << "2. Ayam goreng dada + naso + es teh      Rp. 11.900\n";
    cout << "3. nasi goreng + telur + es teh          Rp. 12.900\n";
    cout << "4. Mie goreng + es teh                   Rp. 12.000\n";
    cout << "5. Nasi goreng seafood + es teh          Rp. 14.000\n";
    cout << "\n\n";

    cout << "Menu yang dipilih [1-5] : "; cin >> paket;
    cout << "jumlah : "; cin >> jml;

    switch (paket) {
      case 1 : harga = 9900;
        break;
      case 2 : harga = 11900;
        break; 
      case 3 : harga = 12900;
        break;
      case 4 : harga = 12000;
        break;
      case 5 : harga = 14000;
        break;
    }

    bayar = harga * jml;
    cout << "Total bayar Rp. " << bayar << "\n";


    /* cout << "Masukkan jumlah menu yang dipesan : "; cin >> jml;
    for (i = 0; i < jml; i++) {
        cout << "Menu ke - [" << i+1 << "] :\n";
        cout << "Nama   : "; cin >> nama[i];
        cout << "Harga  : "; cin >> price[i];
        cout << "Jumlah : "; cin >> banyak;
        total = banyak * price[i];
        bayar += total;
        
    }
        cout << "Total Harga Rp." << bayar << endl;*/
}