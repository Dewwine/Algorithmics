#include <iostream>
// #include <stdlib.h>
#include <ctime>
// #include <string.h>
#include <string>

using namespace std;

int StringSearchInText(string text, string p)
{
    int j;
    int i = -1;
    int N = text.length();
    int M = p.length();

    while ((j != M) && (i <= N - M))
    {
        j = 0;
        i++;
        while ((j < M) && (p[j] == text[i + j]))
        {
            j++;
        }
    }

    if ((j == M) && (i <= N - M)) {
        return i; }
    else
        return -1;
}

int KMPSearch(string text, string p)
{
    int search;
    int N = text.length();
    int M = p.length();

    int d[M];
    int i = 0;
    int j = -1;
    d[0] = -1;

    while (i < M) // формування дескриптору d
    {
        while ((j >= 0) && (p[i] != p[j]))
            j = d[j];
        i++;
        j++;
        if (p[i] == p[j])
            d[i] = d[j];
        else
            d[i] = j;
    }

    i = 0;
    j = 0; // пошук

    while ((i < N) && (j < M))
    {
        while ((j >= 0) && (p[j] != text[i]))
            j = d[j];
        i++;
        j++;
    }
    if (j == M)
        search = i - j;
    else
        search = -1;
    return search;
}

int main()
{
    unsigned int start_time1 = clock();

    int i = StringSearchInText("qwertqwertqwerty", "qwerty");
    cout << i << endl;

    unsigned int end_time1 = clock();
    unsigned int search_time1 = end_time1 - start_time1;
    cout << "Runtime: " << search_time1 / 10000.0 << " sec" << endl;

    unsigned int start_time2 = clock();

    int j = KMPSearch("qwertqwertqwerty", "qwerty");
    cout << j << endl;

    unsigned int end_time2 = clock();
    unsigned int search_time2 = end_time2 - start_time2;
    cout << "Runtime: " << search_time2 / 10000.0 << " sec" << endl;

    return 0;
}