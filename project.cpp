#include <iostream> // cout dkk
// #include <iomanip>
#include "./queue.h" 
// #include <conio.h>
#include <stdlib.h>
// #include <array>
#include <time.h> // checkHarga()
#include <ctype.h> // mbuh
#include <vector>
// #include <string>

// #define MAX 10

using namespace std;

queue qw;
// queue<person> pdata;

bool seat[10][10] = {};

// void init() {
//     antre.head = 0;
//     antre.tail = 0;
// }

void Show_Chart()
{
    cout << "\tSeats" << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10";
    
    for (int i = 0; i < 10; i++)
    {
        cout << endl << char(i + 'A');
        for (int j = 0; j < 10; j++)
        {
            cout << " " << (seat[i][j] ? '*' : '#');
        }
    }

    cout << endl;
}

void tampilData() {
    if (qw.empty())
    {
        cout << "Kosong!!!" << endl;
    }
    else 
    {
        queue copy_of_qw = qw;

        while (!copy_of_qw.empty())
        {
            person data = copy_of_qw.pop();

            cout << " " << data.nama;
            cout << " " << data.judul;
            
            // int vector_size = data.seat.size();
            double totalPrice = 0;

            for (seat_struct item : data.seat)
            {
                cout << " " << item.name;    
                totalPrice += item.harga;
            }

            cout << " " << totalPrice;
                
        }

        cout << endl;
    }

    cin.ignore();
    cin.get();
}

double checkHarga(int row, int column) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    double base_price = 40000.0;

    if (column == 9)
      base_price += 10000.00;

    if (ltm->tm_wday == 0 || ltm->tm_wday == 6 )
      base_price += 5000.00;

    return base_price;
}

person insertData() {
    person temp_pdata;

    cout << "Masukkan data..\n";
    cin.ignore();
    cout << "Atas nama           : "; getline(cin, temp_pdata.nama);
    cout << "Masukkan judul film : "; getline(cin, temp_pdata.judul);

    string the_choosen_one;
    char quit = 'y';
    
    cout << "Beli Tiket\n\n";
    
    do 
    {
        Show_Chart();
        cout << "Pilih kursi Anda: ";
        cin >> the_choosen_one;
        // cout << "Please select the seat you would like to sit in: ";
        // cin >> column;

        // int i = toupper(row) - 65;

        int i = toupper(the_choosen_one[0]) - 'A';
        int j = stoi(the_choosen_one.substr(1)) - 1;
        
        if (seat[i][j])
        {
            cout << "Maaf Kursi sudah di pesan, silahkan pilih kursi lain\n";
            cin.get();
        }
        else 
        {
            seat_struct person_seat;
            double totalCost = 0;
            char answer;
            
            // cost = .data[antre.tail].harga[row] + 0;
            // temp_pdata = checkHarga(i, j);
            cout << "Harga tiket: " << checkHarga(i, j) << endl;
            cout << "Confirm tiket (Y/n)";
            cin >> answer;
            
            if (tolower(answer) == 'y')
            { 
                person_seat = {the_choosen_one, checkHarga(i, j)};
                totalCost += person_seat.harga;
                seat[i][j] = true;
                temp_pdata.seat.push_back(person_seat);
                cout << "Tiket anda sudah dikonfirmasi." << endl;
            }

            cout << "Mau pilih kursi lagi? (Y/n) ";
            cin >> quit;
        }
    }
    while (tolower(quit) == 'y');

    return temp_pdata; 
}

void inQueue(person data) 
{
    if (!qw.full()) 
    {
        qw.push(data);
    }
    else
    {
      cout << "Sudah Penuh";
    }
}

void deQueue()
{
  if (qw.empty())
  {
    cout << "Kosong!!!" << endl;
  }
  else
  {
    person data = qw.pop();

    cout << "Data penonton " << endl;
    cout << " Nama\t: " << data.nama;
    cout << " Judul\t: " << data.judul;
    
    double totalPrice = 0;

    for (seat_struct item : data.seat)
    {
        cout << " " << item.name;    
        totalPrice += item.harga;
    }

    cout << " Total\t: " << totalPrice;
  }
}

void Clear()
{
  if (qw.empty())
  {
    cout << "Kosong!!!" << endl;
  }
  else
  {
    while(!qw.empty())
    {
      qw.pop();
    }

    qw.head = -1;
    qw.tail = -1;
  }
}

void menu() 
{
    int pilihan;
    
    do
    {
        system("tput reset");
        cout << "+----------------------------------------+\n";
        cout << "|                  MENU                  +\n";
        cout << "+----------------------------------------+\n";
        cout << "| 1. Lihat antran dan kursi              |\n";
        cout << "| 2. Beli tiket                          |\n";
        cout << "| 3. Memberangkatkan penonton            |\n";
        cout << "| 4. Memberangkatkan semua penonton      |\n";
        cout << "| 5. Daftar film                         |\n";
        cout << "| 6. Exit                                |\n";
        cout << "+----------------------------------------+\n";
        cout << "Masukkan pilihan anda : "; cin >> pilihan;
        switch(pilihan) {
            case 1:
                system("tput reset");
                tampilData();
                break;
            case 2:
                system("tput reset");
                inQueue(insertData());
                break;
            case 3:
                system("tput reset");
                deQueue();
                break;
            case 4:
                Clear();
                break;
            case 5:

                break;
        }
    } while(pilihan != 6);
    
}

int main() {
    int pilihan = -1;
    cout << "+------------------------------------------+\n";
    cout << "|         FINAL PROJECT STRUKTUR DATA      |\n";
    cout << "+------------------------------------------+\n";
    cout << "|           PROGRAM RESERVASI BIOSKOP      |\n";
    cout << "+------------------------------------------+\n";
    cout << "|                                          |\n";
    cout << "+------------------------------------------+\n";
    cout << "| Anggota kelompok :                       |\n";
    cout << "+------------------------------------------+\n";
    cout << "| Hanif Rahman (18.11.1883)                |\n";
    cout << "| Hammam Afiq Murtadho (18.11.1931)        |\n";
    cout << "+------------------------------------------+\n\n";

    cout << "+------------------------------+\n";
    cout << "|          MAIN MENU           |\n";
    cout << "+------------------------------+\n";
    cout << "| 1. Program reservasi bioskop |\n";
    cout << "| 2. EXIT                      |\n";
    cout << "+------------------------------+\n\n";
    cout << "Masukkan pilihan anda : "; cin >> pilihan;
    switch(pilihan) {
        case 1: menu();
            break;
    } while (pilihan != 2);
    
    return 0;
}
