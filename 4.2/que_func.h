#ifndef QUE_FUNC_H_
#define QUE_FUNC_H_

#define SPECIFIC 2
#define NOTLESS 3
#define FIRST 1

struct Msg{
    unsigned short value;
    unsigned short prior;
    struct Msg* prev;
};

struct Msg* create_msg(int get_prior, int get_value);   //создание сообщения, возвращаемое значение - указатель на сообщение (new_msg)
struct Msg* insert_msg(struct Msg* head, struct Msg* new_msg);   //фнкция вставки сообщения в очередь (new_msg получаем из функции create_msg)
struct Msg* msg_get(struct Msg* head, int* value, int* prior , int MODE);  //функция извлечения сообщения (три вида)
int head_check(struct Msg* head);   //проверка пустой очереди

#endif