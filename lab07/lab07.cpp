#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

#define MAX_SIZE 10

int arr[MAX_SIZE];
int point = 0;

void insert()
{
    for (int j = 0; j < MAX_SIZE; j++)
    {
        int i = point - 1;
        int item = rand() % 100 + 1;
        while (i >= 0 && item < arr[i])
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = item;
        point++;
    }
}

void del1()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        // int item;

        if (point == 0)
        {
            printf("%s\n", "ERROR: Queue is empty");
        }
        arr[0] = 0;
        for (int j = 0; j < point; j++)
        {
            arr[j] = arr[j + 1];
        }
        arr[point - 1] = 0;
        point = point - 1;
    }
}

void del2()
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        int item;

        if (point == 0)
        {
            printf("%s\n", "ERROR: Queue is empty");
        }
        arr[i] = 0;
        point = point - 1;
    }
    for (int i = MAX_SIZE - 1; i > 0; i--)
    {
        arr[i - 1] = arr[i];
        arr[i] = 0;
    }
    arr[0] = 0;
}

void print()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    srand(time(0));

    unsigned int start_time1 = clock();

    insert();
    print();
    cout << endl;
    del1();
    cout << endl;
    print();

    unsigned int end_time1 = clock(); 
    unsigned int search_time1 = end_time1 - start_time1;
    cout << "Runtime: " << search_time1/10000.0 << " sec" << endl;

    cout << endl;
    cout << endl;
    cout << endl;

    unsigned int start_time2 = clock();

    insert();
    print();
    cout << endl;
    del2();
    cout << endl;
    print();

    unsigned int end_time2 = clock(); 
    unsigned int search_time2 = end_time2 - start_time2;
    cout << "Runtime: " << search_time2/10000.0 << " sec" << endl;

    return 0;
}