#ifndef BINTREEFUNC_H_
#define BINTREEFUNC_H_

#include <stdlib.h>
#include "contact.h"

struct item {               //структура листа бинарного дерева (int value -> struct Contact)
    int height;
    struct item* right;
    struct item* left;
    struct item* parent;
    struct Contact contact;
};

//      функции для высоты дерева
int height(struct item*);  //обложка для height

int balancefactor(struct item*); //функция вычисления балансфактора для листа (элемента) дерева

void height_rcv(struct item*); //функция восстановления корректного значения высоты дерева

//    функции поворотов для балансировки дерева
struct item* rotate_r(struct item*);   //правый поворот относительно q

struct item* rotate_l(struct item*);   //левый поворот относительно q

//балансировка
struct item* balance(struct item*);    //функция балансировки узла p

//работа с данными контакта
int add_contact(struct Contact* contact, struct item* head);   //функция получнеия данных о контакте

void print_tree(struct item* head);          //вывод дерева

struct item* insert_item(struct Contact* val_contact, struct item* head);    // вставка в дерево

struct item* name_search(struct item* head); // поиск по имени

struct item* delete_item(struct item* tmp, struct item* head); //удаление

void free_mem(struct item* tmp); //освобождение памяти

int head_check(struct item* head); //проверка пустого списка

struct item* findmin(struct item* tmp);

struct item* edit_item(struct item* head, struct item* tmp);  //функция редактирования элеменета

#endif