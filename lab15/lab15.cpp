#include <iostream>
#include <fstream>

using namespace std;

struct workshop
{
  int key;

  string lastname;
  string name;
  string patronymic;

  string post;
};

int linesCount()
{
  ifstream fin("data.txt");
  fin.seekg(0, ios::cur);

  char *temp = new char[1024];

  int i = 0;

  while (!fin.eof())
    fin.getline(temp, 1024, '\n'), i++;

  fin.close();
  delete temp;

  return i;
}

void output(workshop worker)
{
  cout << worker.key << "  " << worker.lastname << "  " << worker.name << "  " << worker.patronymic << "  " << worker.post << endl;
}

void scan_file(int lines)
{
  ifstream fin("data.txt");
  fin.seekg(0, ios::cur);

  if (!fin.is_open())
  {
    cout << "File cannot be opened!" << endl;
  }
  else
  {
    for (int i = 0; i < lines; i++)
    {
      workshop worker;
      fin >> worker.key >> worker.lastname >> worker.name >> worker.patronymic >> worker.post;
      output(worker);
    }
  }

  cout << endl;

  fin.close();
}

void find_data(int key)
{
  ifstream fin("data.txt");
  fin.seekg(0, ios::cur);

  if (!fin.is_open())
  {
    cout << "File cannot be opened!" << endl;
  }
  else
  {
    for (int i = 0; i < linesCount(); i++)
    {
      workshop worker;
      fin >> worker.key >> worker.lastname >> worker.name >> worker.patronymic >> worker.post;

      if (worker.key == key)
      {
        output(worker);
        return;
      }
    }

    cout << "Данных с таким ключем нет!" << endl
         << endl;
  }

  fin.close();
}

void delete_data(int key)
{
  ifstream fin;
  ofstream fout("newData.txt");

  fin.open("data.txt", ios::app);

  int lines = linesCount();

  if (fin.is_open())
  {
    for (int i = 0; i < lines;)
    {
      workshop worker;

      fin >> worker.key >> worker.lastname >> worker.name >> worker.patronymic >> worker.post;

      if (worker.key == key)
        i++;

      else
      {
        fout << worker.key << "  " << worker.lastname << "  " << worker.name << "  " << worker.patronymic
             << "  " << worker.post << (i < lines - 1 ? "\n" : "");
        i++;
      }
    }
    fout.close();
  }

  fin.close();

  remove("data.txt");
  rename("newData.txt", "data.txt");
}

int main()
{
  srand(time(0));

  scan_file(linesCount());

  int key = 0;
  cout << "Введите ключ поиска для отображения информации: ";
  cin >> key;
  cout << endl;

  find_data(key);
  cout << endl
       << endl;

  cout << "Введите ключ поиска для удаления информации: ";
  cin >> key;
  cout << endl;

  delete_data(key);
  cout << endl
       << endl;

  scan_file(linesCount());

  return 0;
}