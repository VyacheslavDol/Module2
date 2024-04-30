#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "contact.h"
#include "input_char.h"
#include "list_func.h"

#define ADD 1
#define LOOK_C 2
#define LOOK_L 5
#define EDIT 3
#define DELETE 4
#define EXIT 0


int main(){
    
    struct Item* head = NULL;
    struct Item* tmp;
    /* ... */
    int choice, exit_flag = 1, flag;
    struct Contact new_contact;

    while(exit_flag){
    printf("\nВыберите действие:\n1.Создать контакт\n2.Просмотреть контакт\n3.Редактировать контакт\n4.Удалить контакт\n5.Список контактов\n0.Выход\n");
    choice = get_ans_int();
        
    switch(choice){
            
        case ADD:                       /* созданиe контакта */
            if(add_contact(&new_contact, head) == -1) break;         //функция заполнения полей данных
            head = InsertItem(&new_contact, head);                   //функция добавления контакта в список
        break;

        case LOOK_C:
            if(head == NULL)
            {
                printf("Список пуст\n");
                break;
            }
            flag = 1;
            print_list(head);
            printf("Выберите номер контакта по порядку\n");
            choice = get_ans_int();
            tmp = get_tmp_choice(head, choice, &flag);
            if(flag == 0) break;
            print_item(head, tmp);
        break;
        
        case DELETE:
        if(head == NULL)
        {
            printf("Список пуст\n");
            break;
        }        
            flag = 1;
            print_list(head);
            printf("Выберите номер контакта по порядку\n");
            choice = get_ans_int();
            tmp = get_tmp_choice(head, choice, &flag);
            if(flag == 0) break;
            head = delete_item(head, tmp);
        break;

        case LOOK_L:
        if(head == NULL)
        {
            printf("Список пуст\n");
            break;
        }        
            print_list(head);
        break;

        case EDIT:
        if(head == NULL)
        {
            printf("Список пуст\n");
            break;
        }        
            flag = 1;
            print_list(head);
            printf("Выберите номер контакта по порядку\n");
            choice = get_ans_int();
            tmp = get_tmp_choice(head, choice, &flag);
            if(flag == 0) break;

            head = edit_item(head, tmp);
        break;

        case EXIT:
            exit_flag = 0;
        break;

        default:
            printf("Incorrect input\n");
        break;
    }

}
    while(head != NULL)     //очистка занимаемой динамической памяти (кучи)
    {
    tmp = head->next;
    free(head);
    head = tmp;
    };
    printf("Память освобождена\n");

    return 0;
}