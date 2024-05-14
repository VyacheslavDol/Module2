#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binTreeFunc.h" 
#include "contact.h"
#include "input_char.h"

//      функции для высоты дерева
int height(struct item* p)  //обложка для height
{
	return p?p->height:0;
}

int balancefactor(struct item* p) //функция вычисления балансфактора для листа (элемента) дерева
{
    return height(p->right) - height(p->left);
}

void height_rcv(struct item* p) //функция восстановления корректного значения высоты дерева
{
    int left_h = height(p->left);
    int right_h = height(p->right);
    p->height = (left_h > right_h)?left_h + 1:right_h + 1;
}


//    функции поворотов для балансировки дерева
struct item* rotate_r(struct item* q)   //правый поворот относительно q
{
    struct item* p = q->left;
    p->parent = q->parent;
    q->parent = p;
    q->left = p->right;
    p->right = q;
    height_rcv(p);
    height_rcv(q);
    return p;
}

struct item* rotate_l(struct item* q)   //левый поворот относительно q
{
    struct item* p = q->right;
    p->parent = q->parent;
    q->parent = p;
    q->right = p->left;
    p->left = q;
    height_rcv(p);
    height_rcv(q);
    return p;
}

struct item* balance(struct item* p)    //функция балансировки узла p
{
	height_rcv(p);
	if( balancefactor(p)==2 )
	{
		if( balancefactor(p->right) < 0 )
			p->right = rotate_r(p->right);
		return rotate_l(p);
	}
	if( balancefactor(p)==-2 )
	{
		if( balancefactor(p->left) > 0  )
			p->left = rotate_l(p->left);
		return rotate_r(p);
	}
	return p; // балансировка не нужна
}


struct item* insert_item(struct Contact* val_contact, struct item* head)
{   
    struct item* p_new;
    struct item* tmp;
    int i = 0;

    if((p_new = malloc(sizeof(struct item))) == NULL) //выделение памяти для нового элеимента и получение указателя на элемент
    {
        printf("Malloc error");
        exit(EXIT_FAILURE) /* ошибка */;
    }

    cont_cpy(&(p_new->contact), val_contact);    //заполнение поля контакт внутри структуры Item


    if(head == NULL)    //вставка первого элемента
    {
        head = p_new;
        p_new->left = NULL;
        p_new->right = NULL;
        p_new->height = 1;
        return head;
    }   
    tmp = head;         //вставка 2го и более элемента
    while(1){
    if(p_new->contact.p.firstname[i] < tmp->contact.p.firstname[i]) //спуск по дереву влево
    {
        if(tmp->left == NULL)
        {
            tmp->left = p_new;
            p_new->parent = tmp;
            p_new->left = NULL;
            p_new->right = NULL;
            p_new->height = 1;
            break;
        }else{
            tmp = tmp->left;
            i = 0;
        }
        
    }else if(p_new->contact.p.firstname[i] > tmp->contact.p.firstname[i]) //спуск по дереву вправо
    {
        if(tmp->right == NULL)
        {
            tmp->right = p_new;
            p_new->parent = tmp;
            p_new->left = NULL;
            p_new->right = NULL;
            p_new->height = 1;
            break;           
        }else{
            tmp = tmp->right;
            i = 0;
        }
    }
    else if(p_new->contact.p.firstname[i] == tmp->contact.p.firstname[i])
    {
        i++;
    }
}
    do{                         //баланснсировка дерева с tmp до head
        tmp = balance(tmp);
        head = tmp;
        tmp = tmp->parent;
    }while(tmp != NULL);
    return head;
}

int add_contact(struct Contact* contact, struct item* head ){           //создание контакта (заполнение полей данных о контакте)
    char firstname[FIRST_NAME_SIZE], lastname[LAST_NAME_SIZE], phone[PHONE_NUMBER_SIZE], email[EMAIL_SIZE];
    char ans[2];
    int ansi, i = 0, name_check = 0;
    struct item* tmp;

    struct Person p;
    struct Phone t;
    struct Email e;

    memset(firstname, 0, sizeof(firstname));
    memset(lastname, 0, sizeof(lastname));
    memset(phone, 0, sizeof(phone));
    memset(email, 0, sizeof(email));

    do{
    printf("Имя: ");
    input_char(firstname, sizeof(firstname)); 
    } while(strcmp(firstname, "\0") == 0);

    tmp = head;
    while(tmp != NULL)
    {
        if(strcmp(firstname, tmp->contact.p.firstname) == 0)
        {
            printf("Контакт с таким именем уже существует\n");
            return -1;
        }
        if(firstname[i] > tmp->contact.p.firstname[i])
        {
          tmp = tmp->right;
          i = 0;  
        } 
        else if(firstname[i] < tmp->contact.p.firstname[i]) 
        {
            tmp = tmp->left;
            i = 0;
        }
        else i++;
    }
     
    do{
    printf("Фамилия: ");
    input_char(lastname, sizeof(lastname));
    } while(strcmp(lastname, "\0") == 0);
        
    printf("Заполнить номер телефона? 1.да 2.нет\n");
    ansi = get_ans_int();
    if(ansi == 1){
        printf("Номер телефона: ");
        input_char(phone, sizeof(phone));
    }

    printf("Заполнить адрес электронной почты 1.да 2.нет\n");
    ansi = get_ans_int();
    if(ansi == 1){
        printf("Элеткронная почта: ");
        input_char(email, sizeof(email));
    }

    PersonInit(&p, firstname, lastname);
    PhoneInit(&t, phone);
    EmailInit(&e, email);

    ContactInit(contact, p, t, e);
    return 0;
}

void print_tree(struct item* head)      //функция вывода дерева
{   
    struct item* tmp = head;
    if(tmp->left != NULL) print_tree(tmp->left);
    printf("Name %s %s\n", tmp->contact.p.firstname, tmp->contact.p.lastname);
    if(tmp->right != NULL) print_tree(tmp->right);

}

void free_mem(struct item* tmp)
{  
    if(tmp->left != NULL) free_mem(tmp->left);
    if(tmp->right != NULL) free_mem(tmp->right);
    free(tmp);
}

struct item* name_search(struct item* head)     //функция поиска контакта по имени, возвращает указатель на контакт
{
    struct item* tmp = head;
    char firstname[FIRST_NAME_SIZE];
    int i = 0;
    printf("Введите имя контакта: ");
    input_char(firstname, sizeof(firstname));
    
    while(tmp != NULL)
    {
        if(strcmp(firstname, tmp->contact.p.firstname) == 0)
        {
            return tmp;
        }
        if(firstname[i] > tmp->contact.p.firstname[i])
        {
          tmp = tmp->right;
          i = 0;  
        } 
        else if(firstname[i] < tmp->contact.p.firstname[i]) 
        {
            tmp = tmp->left;
            i = 0;
        }
        else i++;
    }

    printf("Incorrect input\n");
    return tmp; //(NULL)
}

struct item* delete_item(struct item* tmp, struct item* head)   //удаление элемента tmp
{
    struct item* min;
    if(tmp->left == NULL && tmp->right == NULL)     //удаление листа
    {   
        if(tmp == head)
        {
            head = NULL;
            free(tmp);
            memset(tmp, 0, sizeof(struct item));
            return head;
        }
        if(tmp == tmp->parent->left) tmp->parent->left = NULL;
        else tmp->parent->right = NULL;
        free(tmp);
        memset(tmp, 0, sizeof(struct item));
        return head;
    }
    else                                            //удаление из середины, начала
    {
        if(tmp->right != NULL) min = findmin(tmp->right);
        else min = tmp->left;

        if(min == min->parent->left) min->parent->left = NULL;
        else min->parent->right = NULL;

        if(tmp == tmp->parent->left) tmp->parent->left = min;
        else tmp->parent->right = min;

        min->parent = tmp->parent;
        min->left = tmp->left;
        min->right = tmp->right;
        
        free(tmp);
        memset(tmp, 0, sizeof(struct item));
    }
    do{                         //баланснсировка дерева с tmp до head
        min = balance(min);
        head = min;
        min = min->parent;
    }while(min != NULL);
    return head;
}

int head_check(struct item* head)
{
    if(head == NULL)
    {
        printf("Контактная книга пуста\n");
        return -1;
    }
    return 0;
}

struct item* findmin(struct item* tmp) // поиск узла с минимальным ключом в дереве tmp
{
	return tmp->left?findmin(tmp->left):tmp;
}

struct item* edit_item(struct item* head, struct item* tmp)
{
    char firstname[FIRST_NAME_SIZE], lastname[LAST_NAME_SIZE], phone[PHONE_NUMBER_SIZE], email[EMAIL_SIZE];
    int choice;
    ContactPrint(&(tmp->contact));
    printf("Выберите, что изменить\n1.Имя\n2.Номер телефона\n3.Адрес\n");
    choice = get_ans_int();

    if(choice == 2){
        printf("Введите новый номер: ");
        memset(phone, 0, sizeof(phone));
        input_char(phone, sizeof(phone));
        strcpy(tmp->contact.t.number, phone);
    }else if(choice == 3){
        printf("Введите новый адрес: ");
        memset(email, 0, sizeof(email));
        input_char(email, sizeof(email));
        strcpy(tmp->contact.e.email, email);
    }
    else if(choice == 1)/*name chnge*/
    { 
        struct Contact edit_contact;                
        memset(firstname, 0, sizeof(firstname));
        memset(lastname, 0, sizeof(lastname));
        printf("Введите новое имя: ");
        input_char(firstname, sizeof(firstname));   //ввод новых значений
        printf("Введите новую фамилию: ");
        input_char(lastname, sizeof(lastname));

        strcpy(edit_contact.t.number, tmp->contact.t.number);   //копирование значений почты и телефона из "старого контакта в новый"
        strcpy(edit_contact.e.email, tmp->contact.e.email);
        strcpy(edit_contact.p.firstname, firstname);            //вставляем имя и фамилию
        strcpy(edit_contact.p.lastname, lastname);

        head = delete_item(tmp, head);
        head = insert_item(&edit_contact, head);
        
    }
    return head;
}