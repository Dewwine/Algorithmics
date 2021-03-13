#include <iostream>
#include <stack>
#include <ctime>

using namespace std;

int AkermanRecursion(int m, int n);
int AkermanIteration(int m, int n);

int main()
{
    int m, n, res;
    cout << "Введите m" << endl;
    cin >> m;
    cout << "Введите n" << endl;
    cin >> n;

    unsigned int start_time =  clock();

    // cout << "A(" << m << "," << n << ") = " << AkermanRecursion(m, n) << endl;
    cout << "Iteration - A(" << m << "," << n << ") = " << AkermanIteration(m, n) << endl;

    unsigned int end_time = clock(); 
    unsigned int search_time = end_time - start_time;
    cout << "Runtime: " << search_time/1000000.0 << " sec" << endl;
    return 0;
}

int AkermanRecursion(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (m > 0 && n == 0)
    {
        return AkermanRecursion(m - 1, 1);
    }
    else
    {
        return AkermanRecursion(m - 1, AkermanRecursion(m, n - 1));
    }
}

int AkermanIteration(int m, int n) {
    stack <int> value;
    
    value.push(m);
    while (value.size() > 0) {
        m = value.top(); 
        value.pop();
 
        if (m == 0) {
            n+=m+1;
        } else if (n == 0) {
            value.push(m - 1);
            n = 1;
        } else {
            value.push(m - 1); 
            value.push(m);
            n--;
        }
    }
 
    return n;
}