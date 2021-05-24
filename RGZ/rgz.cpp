#include <ctime>
#include <iostream>
using namespace std;

const int N = 100;
const int M = 100;
const int K = 100;

int GetEl(int *arr, int i, int j, int k)
{
  return *(arr + ((K * M * i) + (K * j) + k));
}

void addIliffeEl(int i, int j, int k, int ***base, int data)
{
  *(*(*(base + i) + j) + k) = data;
}

void removeIliffeEl(int i, int j, int k, int ***base)
{
  *(*(*(base + i) + j) + k) = 0;
}

int GetIliffeEl(int i, int j, int k, int ***base)
{
  return *(*(*(base + i) + j) + k);
}

void freeMemory()
{
}

int main()
{
  // [0][0][0] = 1
  // [0][0][1] = 2
  // [0][0][2] = 3
  // [0][1][0] = 4
  // [0][1][1] = 5
  // [0][1][2] = 6
  // [0][2][0] = 7
  // [0][2][1] = 8
  // [0][2][2] = 9
  // [1][0][0] = 10
  // [1][0][1] = 11
  // [1][0][2] = 12
  // [1][1][0] = 13
  // [1][1][1] = 14
  // [1][1][2] = 15
  // [1][2][0] = 16
  // [1][2][1] = 17
  // [1][2][2] = 18
  // [2][0][0] = 19
  // [2][0][1] = 20
  // [2][0][2] = 21
  // [2][1][0] = 22
  // [2][1][1] = 23
  // [2][1][2] = 24
  // [2][2][0] = 25
  // [2][2][1] = 26
  // [2][2][2] = 27

  int arr[N * N * N];
  for (int i = 0; i < N * N * N; i++)
  {
    arr[i] = i + 1;
  }

  int i = 99;
  int j = 99;
  int k = 99;

  unsigned int start_time = clock();

  cout << GetEl(arr, i, j, k) << endl;

  unsigned int end_time = clock();
  unsigned int search_time = end_time - start_time;
  cout << "Runtime: " << search_time / 10000.0 << " sec" << endl;

  // ИНИЦИАЛИЗАЦИЯ ВЕКТОРОВ АЙЛИФФА
  int ***base;
  int **vec1[3];

  base = vec1;
  int count = 0;
  for (int i = 0; i < N; i++)
  {
    vec1[i] = new int *[M];
    for (int j = 0; j < M; j++)
    {
      vec1[i][j] = new int[K];
      for (int k = 0; k < K; k++)
      {
        vec1[i][j][k] = *(arr + count);
        count++;
      }
    }
  }
  //////////////////////////////////

  start_time = clock();

  cout << GetIliffeEl(i, j, k, base) << endl;

  end_time = clock();
  search_time = end_time - start_time;
  cout << "Runtime: " << search_time / 10000.0 << " sec" << endl;

  // addIliffeEl(i, j, k, base, 666);
  // removeIliffeEl(i, j, k, base);
  // cout << GetIliffeEl(i, j, k, base) << endl;
  return 0;
}
