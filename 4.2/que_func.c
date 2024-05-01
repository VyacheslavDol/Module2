#include "que_func.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Msg* create_msg(int get_prior, int get_value){   //создание сообщения, возвращаемое значение - указатель на сообщение (new_msg)
    struct Msg* new_msg;
    new_msg = malloc(sizeof(struct Msg)); //выделение памяти
    new_msg->prior = get_prior;
    new_msg->value = get_value;   
    return new_msg;
}

struct Msg* insert_msg(struct Msg* head, struct Msg* new_msg){   //функция вставки сообщения в очередь (new_msg получаем из функции create_msg)
    struct Msg* tmp;
    tmp = head;
    if(tmp == NULL)    //вставка в пустую очередь
    {  
        head = new_msg;
        new_msg->prev = NULL;
        return head;
    }
    if(new_msg->prior < tmp->prior) //вставка в начало
    {
        head = new_msg;
        new_msg->prev = tmp;
        return head;
    }
    if(tmp->prev == NULL)   //вставка вторым сообщением
    {
        tmp->prev = new_msg;
        new_msg->prev = NULL;
        return head;
    }
    while(new_msg->prior > tmp->prev->prior && tmp->prev != NULL){  //поиск позиции (вставка после tmp) (ВТОРОЕ УСЛОВИЕ ДОЛЖНО СРАБАТЫВАТЬ РАНЬШЕ!!!)
        tmp = tmp->prev;
        if(tmp->prev == NULL) break;
    }

    if(tmp->prev == NULL)   //вставка в конец очереди
    {
        tmp->prev = new_msg;
        new_msg->prev = NULL;
    }else
    {                           //вставка в середину
        new_msg->prev = tmp->prev;
        tmp->prev = new_msg;
    };
    return head;
}

struct Msg* msg_get(struct Msg* head, int* value, int* prior , /* int flag, */ int MODE){ //flag -1 - первый элемент, иначе flag - приоритет    
    struct Msg* tmp;
    struct Msg* tmp2;

    switch (MODE){
        case FIRST:         //извлечение первого элемента
        *value = head->value;
        *prior = head->prior;
        head = head->prev;
        return head;
        break;

        case SPECIFIC:      //извлечение по конкретному приоритету

    tmp = head;
    if(tmp->prev == NULL && *prior != tmp->prior)  //если одно сообщение в очереди
    {
        printf("Сообщения с приоритетом %d в очереди\n", *prior);
        *prior = -1;
        return head;
    }
    else if(*prior == tmp->prior) //извлечение head по условию 
    {
        *value = tmp->value;
        *prior = tmp->prior;
        head = tmp->prev;
        free(tmp);
        return head;
    };
    
    while(*prior != tmp->prev->prior)   //перебор указателей до нужного
    {
        tmp = tmp->prev;
        if(tmp->prev == NULL)
        {
        printf("Сообщения с приоритетом %d нет в очереди\n", *prior);
        *prior = -1;
        return head;   
        }
    };
    *value = tmp->prev->value;
    *prior = tmp->prev->prior;
    tmp2 = tmp->prev;
    tmp->prev = tmp->prev->prev;
    free(tmp2);
    return head;

        break;

        case NOTLESS:   //извлечение по приоритету не ниже

    tmp = head;
    if(tmp->prev == NULL && *prior > tmp->prior)  //если одно сообщение в очереди
    {
        printf("Сообщения с приоритетом %d и больше нет в очереди\n", *prior);
        *prior = -1;
        return head; 
    }else if(*prior <= tmp->prior) //извлечение head по условию 
    {
        *value = tmp->value;
        *prior = tmp->prior;
        head = tmp->prev;
        free(tmp);
        return head;
    };
    
    while(*prior > tmp->prev->prior)    //перебор указателей до нужного
    {
        tmp = tmp->prev;
        if(tmp->prev == NULL)
        {
        printf("Сообщения с приоритетом %d и больше нет в очереди\n", *prior);
        *prior = -1;
        return head;   
        }
    };
    *value = tmp->prev->value;
    *prior = tmp->prev->prior;
    tmp2 = tmp->prev;
    tmp->prev = tmp->prev->prev;
    free(tmp2);
    return head;
        break;
    };
};
    
int head_check(struct Msg* head){
    if(head == NULL) 
    {
      printf("Очередь пуста\n");
      return 0;  
    } 
    else return 1;
};