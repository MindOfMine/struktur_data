#include <iostream>
#include <iomanip>
#include <queue>
#include <conio.h>
#include <stdlib.h>
#include <array>
#include <time.h>
#include <ctype.h>
#include <vector>

#define MAX 10

using namespace std;

struct person 
{
    char nama[30];
    char judul[50];
    vector<string> seat;
    int banyak = 0;
    double harga = 0;
};

queue<person> pdata;

bool seat[10][10] = {};

// void init() {
//     antre.head = 0;
//     antre.tail = 0;
// }

void Show_Chart()
{
    cout << "\tSeats" << endl;
    cout << "   1 2 3 4 5 6 7 8 9 10\n";
    
    for (int i = 0; i < 10; i++)
    {
        cout << endl << char(i + 'A');
        for (int j = 0; j < 10; j++)
        {
            cout << " " <<  (seat[i][j] ? '*' : '#');
        }
    }

    cout << endl;
}

bool full() {
    if (pdata.size() == MAX) {
        return true;
    } else {
        return false;
    }
}

// bool empty(void) {
//     if (pdata. == -1) {
//         return true;
//     } else {
//         return false;
//     }
    
// }

void tampilData(queue<person> q) {
    while (!q.empty())
    {
        person qw_data = q.front();
		cout << " " << qw_data.nama;
        cout << " " << qw_data.judul;
        
        int vector_size = qw_data.seat.size();
        
        for (int i = 0; i < vector_size; i++)
        {
            cout << " " << qw_data.seat[i];    
        }
        
        cout << " " << qw_data.harga * qw_data.banyak;
		q.pop();
	}
	cout<<endl;
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
    cout << "Atas nama           : "; cin.getline(temp_pdata.nama, 30);
    cout << "Masukkan judul film : "; cin.getline(temp_pdata.judul, 50);

    string the_choosen_one;
    char quit = 'y';
    char answer;
    double totalCost = 0;
    cout << "Purchase a Ticket\n\n";
    do 
    {
        Show_Chart();
        cout << "Please select the row you would like to sit in: ";
        cin >> the_choosen_one;
        // cout << "Please select the seat you would like to sit in: ";
        // cin >> column;

        // int i = toupper(row) - 65;
        int i = toupper(the_choosen_one[0]) - 'A';
        int j = the_choosen_one[1] - '0';
        
        if (seat[i][j])
        {
            cout << "Sorry that seat is sold-out, Please select a new seat.";
            cout << endl;
        }
        else 
        {
            // cost = .data[antre.tail].harga[row] + 0;
            temp_pdata.harga = checkHarga(i, j);
            totalCost += temp_pdata.harga;
            cout << "That ticket costs: " << temp_pdata.harga << endl;
            cout << "Confirm Purchase? Enter (Y/n)";
            cin >> answer;
            
            if (tolower(answer) == 'y')
            { 
                cout << "Your ticket purchase has been confirmed." << endl;
                seat[i][j] = true;
                temp_pdata.seat.push_back(the_choosen_one);
                temp_pdata.banyak++;
            }

            cout << "Would you like to look at another seat? (Y/n) ";
            cin >> quit;
        }
    }
    while (tolower(quit) == 'y');

    return temp_pdata; 
}

void enQueue(person adata) 
{
    if (!full()) 
    {
        pdata.push(adata);
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
        cout << "| 5. Lihat data penjualan                |\n";
        cout << "| 6. Exit                                |\n";
        cout << "+----------------------------------------+\n";
        cout << "Masukkan pilihan anda : "; cin >> pilihan;
        switch(pilihan) {
            case 1:
                tampilData(pdata);
                break;
            case 2:
                enQueue(insertData());
                break;
            case 3:
                break;
            case 4:
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
    cout << "| Hanif Rahman (18.11.1883                 |\n";
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