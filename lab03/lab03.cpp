#include "stdlib.h"
#include "iostream"
#define PB(value) (byte *)(value)
using namespace std;
typedef unsigned char byte;
typedef unsigned int dword;
template <class T>
void to_bin(const T &value)
{
    for (dword i = 0; i < sizeof(T); i++)
    {
        byte Byte = *(PB(&value) + i);
        for (dword j = 0; j < 8; j++) {
            cout << dword((Byte >> (7 - j)) & 1);
        }
        cout << ' ';
    }
    cout << endl;
}
int main()
{
    srand(time(0));
    int val1 = 0;
    float val2 = 0;
    char val3 = '0';
    cout << "Enter int value : ";
    cin >> val1;
    to_bin(val1);
    cout << "Enter float value : ";
    cin >> val2;
    to_bin(val2);
    cout << "Enter char value : ";
    cin >> val3;
    to_bin(val3);
    cout << "Array : ";
    const int N = 3;
    int val4[N];
    for (int i = 0; i < N; i++)
    {
        val4[i] = rand() % 10 + 1;
        cout << val4[i] << " ";
    }
    cout << endl;
    to_bin(val4);
    return 0;
}