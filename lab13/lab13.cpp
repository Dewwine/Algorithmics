#include <iostream>
using namespace std;

const int N = 10;

struct Node
{
  Node *left, *right; //левое и правое поддерево
  int data;           //Данные
};

void add(int data, Node *&Tree) //Функция добавления звена в дерево
{
  if (NULL == Tree) //Если дерева нет, то создаем корень
  {
    Tree = new Node;                 //Выделяем память под звено дерева
    Tree->data = data;               //Записываем данные в звено
    Tree->left = Tree->right = NULL; //Подзвенья инициализируем пустотой
  }

  if (data < Tree->data) //Если нововведенный элемент data меньше чем элемент data из корня, уходим влево
  {
    if (Tree->left != NULL)
    {
      add(data, Tree->left); //При помощи рекурсии заталкиваем элемент на свободный участок
    }
    else //Если элемент получил свой участок, то
    {
      Tree->left = new Node; //Выделяем память левому подзвену.
      Tree->left->left = Tree->left->right = NULL;
      Tree->left->data = data;
    }
  }

  if (data > Tree->data) //Если нововведенный элемент data больше чем элемент data из корня, уходим вправо
  {
    if (Tree->right != NULL)
    {
      add(data, Tree->right); //При помощи рекурсии заталкиваем элемент на свободный участок
    }
    else //Если элемент получил свой участок, то
    {
      Tree->right = new Node; //Выделяем память правому подзвену.
      Tree->right->left = Tree->right->right = NULL;
      Tree->right->data = data;
    }
  }
}

void Show(Node *&tree, int n)
{
  if (tree == NULL)
  {
    return; //Если дерева нет, выходим
  }
  for (int i = 1; i < n; i++)
  {
    cout << " ";
  }
  cout << tree->data << endl; //Вывели узел

  Show(tree->left, n - 3);  //Обошли левое поддерево
  Show(tree->right, n + 3); //Обошли правое поддерево
}

int FindMax(Node *&tree)
{
  while (tree->right != NULL)
  {
    tree = tree->right;
  }
  return tree->data;
}

int main()
{
  srand(time(0));
  Node *Tree = NULL; //Указатель на структуру

  for (int i = 0; i < N; i++)
  {
    add(rand() % 100, Tree); //Добавили рандомные данные в дерево
  }

  Show(Tree, 10); //Обход дерева и показ звеньев в линейном порядке
  int max = FindMax(Tree);
  cout << "\nМаксимальное число: " << max << endl;
}
