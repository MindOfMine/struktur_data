#include <string>
#include <vector>

#define MAX 10

using namespace std;

struct seat_struct
{
    public:
    string name;
    double harga;
};

struct person
{
    string id;
    string nama;
    string judul;
    vector<seat_struct> seat;
    // double harga = 0;
};

class queue
{
    private:
        struct person data[MAX];
    private:
        int tail = 0;
    private:
        int head = 0;

    public:
    bool full() 
    {
        if (tail == MAX)
            return true;
        else
            return false;
    }

    bool empty() 
    {
        if (tail == head)
            return true;
        else
            return false;
        
    }

    void push(person psdata)
    {
        data[tail] = psdata;
        tail++;
    }
    
    person pop()
    {
        person pop_data = data[head];
        
        for (int i = head; i < tail; i++)
        data[i] = data[i+1];
        
        tail--;

        return pop_data;
    }
};
