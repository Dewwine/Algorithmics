#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

#define N 5

typedef struct sublist
{
    int title;            // поле данных
    struct sublist *next; // указатель на следующий элемент
} sub_list;

typedef struct mainlist
{
    int author;            // поле данных
    struct mainlist *next; // указатель на следующий элемент
    sub_list *title_list;  // указатель на голову вложенного списка
} main_list;

main_list *create_list(int author); // создание элемента главного списка

sub_list *create_sub_list(int n); // создание элемента подсписка

main_list *push(main_list *list, int author); // добавление элемента главного списка

sub_list *push_sub(sub_list *list, int title); // добавление элемента в подсписок

void print_list(main_list *list); // вывод всего списка

void delete_elem_list(main_list *list, int index); // удаление элемента списка

void deleteList(main_list *list); // удаление всего списка


int main()
{
    main_list *list = create_list(1);
    for (int i = N; i > 1; i--)
    {
        push_sub(list->title_list, i);
    }

    main_list *el = list;
    for (int i = 0; i < N - 1; i++)
    {
        el = push(el, i + 2);
    }

    print_list(list);

    deleteList(list);
    return 0;
}

main_list *create_list(int author)
{
    main_list *tmp;
    tmp = new main_list;
    tmp->next = NULL;
    tmp->author = author;
    tmp->title_list = create_sub_list(1);

    return tmp;
}

sub_list *create_sub_list(int title)
{
    sub_list *tmp;
    tmp = new sub_list;
    tmp->next = NULL;
    tmp->title = title;
    return tmp;
}

main_list *push(main_list *list, int author)
{
    main_list *temp, *p;
    temp = create_list(author);

    p = list->next;
    list->next = temp;
    temp->next = p;

    sub_list *titles = temp->title_list;
    for (int i = 0; i < N - 1; i++)
    {
        titles = push_sub(titles, i + 2);
    }
    return temp;
}

sub_list *push_sub(sub_list *list, int title)
{
    sub_list *temp, *p;
    temp = create_sub_list(title);
    p = list->next;
    list->next = temp;
    temp->next = p;
    return temp;
}

void print_list(main_list *list)
{
    main_list *temp = list;

    while (temp)
    {
        cout << "Автор №" << temp->author << endl;
        sub_list *tmp = temp->title_list;

        while (tmp)
        {
            cout << "\tТвір №" << tmp->title;
            tmp = tmp->next;
        }
        cout << endl;
        temp = temp->next;
    }
}

void deleteList(main_list *list)
{
    main_list *temp = list;
    struct mainlist *next = NULL;

    while (temp)
    {
        next = temp->next;

        sub_list *tmp = temp->title_list;
        struct sublist *nxt = NULL;
        while (tmp)
        {
            nxt = tmp->next;
            delete[] tmp;
            tmp = nxt;
        }

        delete[] temp;
        temp = next;
    }
}

void delete_elem_list(main_list *list, int index)
{
    main_list *temp = list;
    main_list *del_pos = NULL;

    if (index == 0)
    {
        del_pos = list;
        list = temp->next;
        delete[] del_pos;
        return;
    }

    for (int i = 0; i < index - 1; i++)
        temp = temp->next;

    del_pos = temp->next;
    temp->next = temp->next->next;
    delete[] del_pos;
}