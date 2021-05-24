#include <stdio.h>
#include <iostream>
using namespace std;

const int N = 100;
int arr[N];

void RandomFill()
{
  srand(time(0));

  for (int i = 0; i < N; i++)
  {
    arr[i] = rand() % 100 + 1;
  }
}
int n = sizeof(arr) / sizeof(arr[0]);

int binarySearch(int key, int start, int end)
{
  while (start <= end)
  {
    int m = start + (end - start) / 2;

    if (arr[m] == key)
      return m;

    if (arr[m] < key)
      start = m + 1;

    else
      end = m - 1;
  }
}

void insertionSort()
{
  for (int i = 1; i < n; ++i)
  {
    int j = i - 1;
    int current = arr[i];

    int loc = binarySearch(current, 0, j);

    while (j >= loc)
    {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = current;
  }
}

int main()
{
  RandomFill();
  insertionSort();

  cout << "Sorted array: " << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

  return 0;
}
