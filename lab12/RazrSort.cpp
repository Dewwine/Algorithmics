#include "iostream"
using namespace std;
const unsigned int N = 50, col_razr = 3;

void RandomFill(int arr[])
{
    srand(time(0));

    for (int i = 0; i < N; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
}

int VelichRazr(int chislo, int razr)
{
    while (razr > 1)
    {
        chislo /= 10;
        razr--;
    }
    return chislo % 10;
}

void SortRazr(int dop_arr[N][N], int arr[N], int razr)
{
    int arr_col[N], i, j, temp = 0;
    for (i = 0; i < N; i++)
        arr_col[i] = 0;
    for (i = 0; i < N; i++)
    {
        int a = VelichRazr(arr[i], razr);
        dop_arr[arr_col[a]][a] = arr[i];
        arr_col[a]++;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < arr_col[i]; j++)
        {
            arr[temp] = dop_arr[j][i];
            temp++;
        }
    }
}

int main()
{

    int razr, i;
    int arr[N];
    RandomFill(arr);
    int dop_arr[N][N];
    for (razr = 1; razr < 4; razr++)
        SortRazr(dop_arr, arr, razr);
    for (i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}