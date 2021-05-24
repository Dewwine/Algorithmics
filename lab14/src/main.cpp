// Driver Program for Red Black Tree
#include <iostream>
#include "RBTree.h"
using namespace std;

int main()
{
    srand(time(0));

    RBTree rbTree;

    int data = rand() % 100;

    while (data != 0)
    {
        rbTree.insertValue(data);
        data = rand() % 100;
    }

    rbTree.merge(rbTree);

    rbTree.preorder();

    rbTree.SHOW();

    int k = 0;
    cout << "Какое значение нужно удалить?" << endl;
    cin >> k;
    cout << endl;
    rbTree.deleteValue(k);

    rbTree.preorder();

    rbTree.SHOW();

    return 0;
}