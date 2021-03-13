#include <iostream>
#include <ctime>
using namespace std;

void BYTE(unsigned char A) // виведення вмісту байта
{
    for (int bit = 128; bit >= 1; bit >>= 1)
        cout << (A & bit ? '1' : '0');
    cout << ' ';
}

struct Tstruct1
{
    bool cabin_heating;
    bool headlights_off;
    union 
    {
        struct
        {
            int load_capacity;
        } cargo; // грузова
        struct
        {
            int number_of_seats;
            int count;
        } passenger; // пассажирська
    } un;
};

int main()
{
    unsigned int start_time = clock();

    Tstruct1 car;
    car.cabin_heating = true;
    car.headlights_off = false;
    car.un.passenger.number_of_seats = 4;
    car.un.passenger.count = 2;

    unsigned char *p = (unsigned char *)&car;
    int byte = 0;

    for (; byte < sizeof(Tstruct1); byte++, p++)
    {
        if (byte && !(byte % 8))
        {
            cout << endl;
        }
        BYTE(*p);
    }
    cout << endl;
    cout << endl;

    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;

    cout << "Runtime: " << search_time / 1000.0 << " sec" << endl;
}
