#include <iostream> // cout dkk
// #include <iomanip>
#include "./queue.h" 
#include <conio.h>
#include <stdlib.h> // system()
// #include <array>
#include <algorithm> // transform
#include <time.h> // checkHarga()
#include <ctype.h> // tolower()
#include <vector> // vector
// #include <string>

// #define MAX 10

using namespace std;

queue qw;
// queue<person> pdata;

// bool seat[10][10] = {};

// struct film films[2] = {
//     {1, },
//     {2, }
// };

struct film films[2] = {
    {1, "spider-man: far from home", 40000.00, {}},
    // {2, 1, "Studio #1", 40000.00, seat},
    {2, "annabelle", 50000.00, {}},
    // {5, 2, "Studio #1", 40000.00, seat}
};

// void init() {
//     antre.head = 0;
//     antre.tail = 0;
// }

int searchFilmByTitle(string title) 
{
    int flag = 0;
    int foundId = 0;
    
    for (auto item: films)
    {
        if (item.judul == title)
        {
            foundId = item.id;
            flag = 1;
            break;
        }

        // foundId++;
    }

    if (flag == 0)
    {
        return -1;
    }
    else
    {
        return foundId;
    }
}
int getIndexFilmsById(int id)
{
    int flag = 0;
    int foundId = 0;
    
    for (auto item: films)
    {
        if (item.id == id)
        {
            // foundId = item.id;
            flag = 1;
            break;
        }

        foundId++;
    }

    if (flag == 0)
    {
        return -1;
    }
    else
    {
        return foundId;
    }
}

film searchFilmById(int id) 
{
    int flag = 0;
    int foundId = 0;
    
    for (auto item: films)
    {
        if (item.id == id)
        {
            // foundId = item.id;
            flag = 1;
            break;
        }

        foundId++;
    }

    if (flag == 0)
    {
        throw "no_such_film_error";
    }
    else
    {
        return films[foundId];
    }
}

// vector<show> searchShowsByIdFilm(int idFilm)
// {
//     int flag = 0;
//     vector<show> foundShows;
    
//     for (auto item: shows)
//     {
//         if (item.idFilm == idFilm)
//         {
//             // foundId = item.id;
//             foundShows.push_back(item);
//             flag = 1;
//         }
//     }

//     if (flag == 0)
//     {
//         return;
//     }
//     else
//     {
//         return foundShows;
//     }
// }

void Show_Chart(film film)
{
    cout << "\tSeats" << endl;
    cout << "  1 2 3 4 5 6 7 8 9 10";
    
    // int idFilm = searchFilmByTitle(film_title);
    // vector<show> idShow = searchShowsByIdFilm(idFilm);

    for (int i = 0; i < 10; i++)
    {
        cout << endl << char(i + 'A');
        for (int j = 0; j < 10; j++)
        {
            cout << " " << (film.seat[i][j] ? '*' : '#');
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
        int i = 0;

        cout << "Data Queue" << endl;
        while (!copy_of_qw.empty())
        {
            person data = copy_of_qw.pop();

            cout << "[" << i++ << "] Nama\t: " << data.nama << endl;
            cout << "    Judul\t: " << searchFilmById(data.idFilm).judul << endl;
            
            // int vector_size = data.seat.size();
            double totalPrice = 0;
            
            cout << "    Seat\t:";
            for (seat_struct item : data.seat)
            {
                cout << " " << item.name;    
                totalPrice += item.harga;
            }

            cout << "\n    Total\t: " << totalPrice << endl;
        }

        cout << endl;
    }

    cin.ignore();
    cin.get();
}

double checkHarga(film film_item, int row, int column) {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    double base_price = film_item.price;

    if (row == 9)
      base_price += 10000.00;

    if (ltm->tm_wday == 0 || ltm->tm_wday == 6 )
      base_price += 5000.00;

    return base_price;
}

string stringToLower(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;
}

person insertData() {
    person temp_pdata;
    string temp_judul;

    cout << "Masukkan data..\n";
    cin.ignore();
    cout << "Atas nama           : "; getline(cin, temp_pdata.nama);
isijudul:
    cout << "Masukkan judul film : "; getline(cin, temp_judul);

    string the_choosen_one;
    char quit = 'n';
    
    temp_judul = stringToLower(temp_judul);

    int idFilm = searchFilmByTitle(temp_judul);
    
    if (idFilm == -1)
    {
        cout << "Film tidak ditemukan" << endl;
        cin.get();
        goto isijudul;
        // system("tput reset");
    }
    int IndexFilm = getIndexFilmsById(idFilm);
    cout << "Beli Tiket\n\n";    
    // film choosenFilm = searchFilmById(idFilm);
    do 
    {        
        // cout << "Jam Tayang : " << endl;
        // for(auto item: choosenShows)
        // {
        //     cout << " " << item.jamTayang << " " << item.studio << "\n";
        // }
        // string jamTayang;
        // cout << "Pilih jam tayang : "; getline(cin, jamTayang);
        
        temp_pdata.idFilm = idFilm;
        // int randomStudio =;
        Show_Chart(films[IndexFilm]);
        cout << "Pilih kursi Anda: ";
        cin >> the_choosen_one;
        // cout << "Please select the seat you would like to sit in: ";
        // cin >> column;

        // int i = toupper(row) - 65;

        int i = toupper(the_choosen_one[0]) - 'A';
        int j = stoi(the_choosen_one.substr(1)) - 1;
        
        if (films[IndexFilm].seat[i][j])
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
            cout << "Harga tiket: " << checkHarga(films[IndexFilm], i, j) << endl;
            cout << "Confirm tiket (Y/n) ";
            cin >> answer;
            
            if (tolower(answer) == 'y')
            { 
                person_seat = {the_choosen_one, checkHarga(films[IndexFilm], i, j)};
                totalCost += person_seat.harga;
                films[IndexFilm].seat[i][j] = true;
                temp_pdata.seat.push_back(person_seat);
                cout << "Tiket anda sudah dikonfirmasi." << endl;
            }

            cout << "Mau pilih kursi lagi? (Y/n) ";
            cin >> quit;
        }
    }
    while (!(tolower(quit) == 'n'));
    
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
      cout << "Sudah Penuh" << endl;
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
        cout << " Nama\t: " << data.nama << endl;
        
        try
        {
            cout << " Judul\t: " << searchFilmById(data.idFilm).judul << endl;
        }
        catch(exception e)
        {
            cerr << e.what() << "\n";
        }
        
        double totalPrice = 0;
        cout << " Seat\t:";
        for (seat_struct item : data.seat)
        {
            cout << " " << item.name;    
            totalPrice += item.harga;
        }

        cout << "\n Total\t: " << totalPrice << endl;
    }
    cin.ignore();
    cin.get();
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
    //   qw.pop();
        deQueue();
    }

    qw.setHead(-1);
    qw.setTail(-1);
  }
}

bool filmTitleCompareAsc(film lfl, film rfl)
{
    return lfl.judul < rfl.judul;
}

bool filmTitleCompareDesc(film lfl, film rfl)
{
    return lfl.judul > rfl.judul;
}

bool filmIdCompareAsc(film lfl, film rfl)
{
    return lfl.id < rfl.id;
}

bool filmIdCompareDesc(film lfl, film rfl)
{
    return lfl.id > rfl.id;
}

bool filmPriceCompareAsc(film lfl, film rfl)
{
    return lfl.price < rfl.price;
}

bool filmPriceCompareDesc(film lfl, film rfl)
{
    return lfl.price > rfl.price;
}

void SortFilmsByName(bool asc = true)
{
    if (asc)
        sort(films, films + 2, filmTitleCompareAsc);
    else
        sort(films, films + 2, filmTitleCompareDesc);
}

void SortFilmsById(bool asc = true)
{
    if (asc)
        sort(films, films + 2, filmIdCompareAsc);
    else
        sort(films, films + 2, filmIdCompareDesc);
}

void SortFilmsByPrice(bool asc = true)
{
    if (asc)
        sort(films, films + 2, filmPriceCompareAsc);
    else
        sort(films, films + 2, filmPriceCompareDesc);
}

void DisplayFilms()
{
    redo:
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
    system("tput reset");

    for (auto item : films)
    {
        cout << " #" << item.id << " " << item.judul << " " << item.price << endl;
    }
    
    int key;
    cout << "\nCommands \n Back(Esc)\n Sorting berdasarkan nama(A)\n Sorting Berdasarkan Id(B)\n Sorting Berdasarkan Harga(C)\n Lihat Kursi(D) ";
    key = toupper(getch());

    //clear the input buffer
    // while ((getchar()) != '\n'); 

    switch (key)
    {
        case 65:
            SortFilmsByName();
            // cin.get();
            break;
        case 66:
            SortFilmsById();
            // cin.get();
            break;
        case 67:
            SortFilmsByPrice();
            // cin.get();
            break;
        case 68:
        {
            int id;
            try
            {
                cout << "\n Pilih Id film: "; cin >> id;
                Show_Chart(searchFilmById(id));
                cin.ignore();
                cin.get();
            }
            catch(char const *)
            {
                cout << "Film dengan id #" << id << " tidak ditemukan\n";
                cin.get();
            }
            break;
        }
        default:
            return;
    }

    goto redo;
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
                // cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
                DisplayFilms();
                break;
            default:
                break;
        }
    } while(pilihan != 6);
    
}

int main() {
    int pilihan = -1;
    do
    {
        system("tput reset");
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
        cout << "| Muhammad Dzaki Baihaqi (18.11.1946)      |\n";
        cout << "| Ardy Muhammad Johan Shah (18.11.1936)    |\n";
        cout << "| Fikri Ivaldi Ihsan (18.11.1947)          |\n";
        cout << "| Fahmi Yahya Mubarok (18.11.1945)         |\n";
        cout << "| Benny Wira Wicaksana (18.11.1881)        |\n";
        cout << "| Yudha Prasetya (18.11.1941)              |\n";
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
            default:
                break;
        } 
    }while (pilihan != 2);
    
    return 0;
}
