#include <iostream>

using namespace std;

#define N 6

int NewIndex(int x, int y) //перерахування індексів
{
    int j = 0;

    for (int i = 0; i < x; i++)
        j += N - i;

    return j + y - x;
}
void Put(int vec[], int x, int y, int v) // Запис у вектор (стиснення)
{
    if (y >= x)
        vec[NewIndex(x, y)] = v;
}

int Get(int vec[], int x, int y) // читання з вектора
{
    if (y <= x)
        return vec[NewIndex(x, y)];
    else
        return 0;
}

void RandArray(int a[N][N]) //формування початкового масиву
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (j >= i)
                a[i][j] = rand() % 50;
            else
                a[i][j] = 0;
}

void PrintArray(int a[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%4i", a[i][j]);
        printf("\n");
    }
}
int main()
{
    int vec[N * N / 2 + N / 2];
    int array[N][N];

    RandArray(array);
    PrintArray(array);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Put(vec, i, j, array[i][j]);

    for (int i = 0; i < N * N / 2 + N / 2; i++)
        printf("%3i", vec[i]);
    printf("\n\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%10i", Get(vec, i, j));
        printf("\n");
    }

    return 0;
}