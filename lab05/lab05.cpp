#include <iostream>
#include <ctime>

using namespace std;

#define N 6

void RandArray(int a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j >= N / 2)
            {
                a[i][j] = rand() % 50 + 1;
            }
            else
            {
                a[i][j] = 0;
            }
        }
    }
}

void PrintArray(int a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void Put(int a[N][N], int vec[], int c)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j >= N / 2)
            {
                vec[c++] = a[i][j];
            }
        }
    }
}

void printLine(int vec[], int c)
{
    for (int i = 0; i < N * N / 2; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void printNew(int vec[], int c)
{
    c = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j >= N / 2)
            {
                cout << vec[c++] << " ";
            }
            else
            {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int array[N][N];
    int vec[N * N / 2];
    int c = 0;

    RandArray(array);
    
    unsigned int start_time = clock();

    PrintArray(array);
    
    unsigned int end_time = clock(); 
    unsigned int search_time = end_time - start_time;
    cout << "Runtime: " << search_time/10000.0 << " sec" << endl;

    Put(array, vec, c);
    cout << endl;

    printLine(vec, c);
    cout << endl;

    unsigned int start_time2 = clock();

    printNew(vec, c);

    unsigned int end_time2 = clock(); 
    unsigned int search_time2 = end_time2 - start_time2;
    cout << "Runtime: " << search_time2/10000.0 << " sec" << endl;

    return 0;
}