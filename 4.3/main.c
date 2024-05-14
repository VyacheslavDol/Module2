#include <stdlib.h>
#include <stdio.h>
#include "input_char.h"
#include "binTreeFunc.h"
#include "contact.h"

#define ADD 1
#define DELETE 2
#define INFO 3
#define LIST 4
#define EDIT 5
#define EXIT 0

int main()
{
    int ansi, flag = 1;
    struct Contact new_contact;
    struct item* head = NULL;
    struct item* tmp = NULL;


    while(flag)
    {
    printf("Выберите действие\n1.Создать контакт\n2.Удалить контакт\n\
3.Информация о контакте\n4.Список контактов\n5.Редактировать контакт\n0.Выход\n");
    ansi = get_ans_int();
    
    switch(ansi) 
    {
        case ADD:
            if(add_contact(&new_contact, head) == -1) break;
            head = insert_item(&new_contact, head);                   
        break;

        case DELETE:
            if(head_check(head) == -1) break;
            print_tree(head);
            tmp = name_search(head);
            if(tmp == NULL) break;
            head = delete_item(tmp, head);
        break;

        case INFO:
            if(head_check(head) == -1) break;
            print_tree(head);
            tmp = name_search(head);
            if(tmp == NULL) break;
            ContactPrint(&(tmp->contact));
        break;

        case LIST:
            if(head_check(head) == -1) break;
            print_tree(head);
        break;

        case EDIT:
            if(head_check(head) == -1) break;
            print_tree(head);
            tmp = name_search(head);
            if(tmp == NULL) break;
            head = edit_item(head, tmp);
        break;

        case EXIT:
            flag = 0;
        break;

        default:
            printf("Incorrect input\n");
        break;
    }

    }

    //освобождение памяти
    free_mem(head);
    printf("Память освобождена\n");

    return 0;
}
