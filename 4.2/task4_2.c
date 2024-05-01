#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "input_char.h"
#include "que_func.h"


#define MENU "\nВыберите действие:\n1.Добавить N сообщений со случайным приоритетом и значением\n\
2.Добавление сообщения с определенными параметрами\n\
3.Извлечение первого сообщения из очереди\n\
4.Извлечение сообщения с определнным приоритетом\n\
5.Извлечение сообщения с приоритетом не ниже чем заданный\n\
0.Выход из программы\n"

int main(){
    struct Msg* head;
    struct Msg* tmp;
    struct Msg* new_msg;
    int prior, value;
    head = NULL;
    tmp = NULL;
    new_msg = NULL;
    srand(time(NULL));
    int ansi, flag = 1, n;
    
    while(flag)
    {
    printf(MENU);
    ansi = get_ans_int();
    switch (ansi)
    {
    case 1:
        printf("Введите кол-во сообщений N(1-99): ");
        n = get_ans_int();
        if(n == 0) break;
        for(int i = 1; i <= n; i++)
        {
            prior = rand() % 256;   //приоритет от 0 до 255
            value = rand();  //значение
            new_msg = create_msg(prior, value);
            head = insert_msg(head, new_msg);
        }
        break;
    
    case 2:
        
        printf("Введите значение сообщения(0-2147483647): ");
        value = get_ans_int();
    
        do 
        {
            printf("Введите приоритет сообщения(0-255): ");
            prior = get_ans_int();
        }while(prior > 255 || prior < 0);
        new_msg = create_msg(prior, value);
        head = insert_msg(head, new_msg);
        break;

    case 3:
        if(head_check(head) == 0) break;
        head = msg_get(head, &value, &prior, FIRST);
        printf("Значение: %d, Приоритет: %d\n", value, prior);
    break;    


    case 4:
        if(head_check(head) == 0) break;
        printf("Введите приоритет (0-255) сообщения: ");
        prior = get_ans_int();
        if(prior < 0 || prior > 255)
        {
            printf("Incorrect input\n"); break;
        }
        head = msg_get(head, &value, &prior, SPECIFIC);
        if(prior != -1)
        printf("Значение: %d, Приоритет: %d\n", value, prior); 
    break;    
    
    case 5:
        if(head_check(head) == 0) break;
        printf("Введите приоритет (0-255) не ниже которого выведется сообщение: ");
        prior = get_ans_int();
        if(prior < 0 || prior > 255)
        {
            printf("Incorrect input\n"); break;
        }
        head = msg_get(head, &value, &prior, NOTLESS);
        if(prior != -1)
        printf("Значение: %d, Приоритет: %d\n", value, prior);
    break;
    default:
        flag = 0;
        break;    
    }

    }
    
    while(head != NULL){    //освобождение динамической памяти
        tmp = head;
        head = head->prev;
        free(tmp);
    }
    return 0;
}