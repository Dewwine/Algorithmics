#include "iostream"
using namespace std;
const unsigned int N = 60;

void RandomFill(int arr[])
{
  srand(time(0));

  for (int i = 0; i < N; i++)
  {
    arr[i] = rand() % 100 + 1;
  }
}

void PairMergeSort(int arr[])
{
  int i0, j0, i, j, si, sj, k, ke, t, m;
  si = 1;        // начальный размер одного множества
  while (si < N) //цикл пока одно множество не составит весь массив}
  {
    i0 = 0;        // нач. индекс 1-го множества пары
    while (i0 < N) // цикл пока не пересмотрим весь массив
    {
      j0 = i0 + si;
      i = i0;
      j = j0;
      //размер 2-го множества пары может ограничиваться концом массива
      if (si >= N - j0)
        sj = N - j0;
      else
        sj = si;
      if (sj > 0)
      {
        k = i0;                                     // нач. индекс слитого множества
        while ((i < i0 + si + sj) && (j < j0 + sj)) // цикл пока не исчерпаются оба входные множества
        {
          if (arr[i] > arr[j])
          {
            t = arr[j];
            for (m = j - 1; m >= k; m--)
              arr[m + 1] = arr[m];
            arr[k] = t;
            j++; //к след. эл-ту во 2-м множестве
          }
          k++;
          i++; // если был перенос - за счет сдвига, если не было - за счет перехода эл-та в вых.
        }
      }
      i0 += si * 2; // начало следующей пары
    }
    si *= 2; // размер эл-тов пары увеличивается вдвое
  }
}

int main()
{
  int arr[N];
  RandomFill(arr);
  PairMergeSort(arr);
  for (int i = 0; i < N; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}