// Визначити кількість символів у рядку s.
// 4) Вектор з керованою довжиною рядка (з дескриптором).
// 8) Блочно-зв’язне подання із змінною довжиною.

#include <iostream>
#include <string.h>
#include <ctime>

using namespace std;

typedef struct size_s
{
    int x;
} size;

typedef struct list_s
{
    char symbol;
    struct list_s *next;
} list;

list *init();

void addelem(list *tmp);

int str_first(size_s size, char *s);

int str_second(int N);

int count_sym(char *s, int count);

int count_sym_list(list *s, int count);

int main()
{
    size_s size;

    int N = 5555;

    size.x = N;
    char s[size.x];
    for (int i = 0; i < size.x; i++)
    {
        s[i] = '*';
    }

    int count = 0;
    count = str_first(size, s);
    cout << count << endl;

    count = 0;
    count = str_second(N);
    cout << count << endl;

    return 0;
}

int str_first(size_s size, char *s)
{
    int count = 0;
    char *str = (char *)calloc(size.x, sizeof(char));

    memmove(str, s, size.x * sizeof(char));

    count = count_sym(str, count);
    return count;
}

int str_second(int N)
{
    int count = 0;
    list *str = init();

    for (int i = 0; i < N; i++)
    {
        addelem(str);        
    }

    count = count_sym_list(str, count);
    return count;
}

int count_sym(char *s, int count)
{
    unsigned int start_time = clock();

    for (int i = 0; s[i] != '\0'; i++)
    {
        count++;
    }

    unsigned int end_time = clock(); 

    unsigned int search_time = end_time - start_time;
    cout << "Runtime: " << search_time/10000.0 << " sec" << endl;

    return count;
}

int count_sym_list(list *s, int count)
{
    unsigned int start_time = clock();

    while (s->next != NULL)
    {
        count++;
        s = s->next;
    }

    unsigned int end_time = clock(); 

    unsigned int search_time = end_time - start_time;
    cout << "Runtime: " << search_time/10000.0 << " sec" << endl;

    return count;
}

list *init()
{
    list *tmp;
    tmp = (list *)malloc(sizeof(list));
    tmp->symbol = ' ';
    tmp->next = NULL;
    return (tmp);
}

void addelem(list *tmp)
{
    list *temp, *p;
    temp = (list *)malloc(sizeof(list));
    p = tmp->next;
    tmp->next = temp;
    temp->symbol = '*';
    temp->next = p;
}