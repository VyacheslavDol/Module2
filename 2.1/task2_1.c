#include <stdio.h>
#include "contact.h"
#include <string.h>
#include "input_char.h"

#define ADD 1
#define LOOK 2
#define EDIT 3
#define DELETE 4
#define EXIT 0
#define NUMBER_OF_CONTACTS 5

int main(){
    char ans[2];
    int ansi, id, flag = 1, name_check, edit_id;
    char firstname[FIRST_NAME_SIZE], lastname[LAST_NAME_SIZE], phone[PHONE_NUMBER_SIZE], email[EMAIL_SIZE];
    

        struct Contact contact[5];// создать массив из структуры
        struct Person p;
        struct Email e;
        struct Phone t;

        memset(contact, 0, sizeof(contact));

while(flag){
    
    memset(firstname, 0, sizeof(firstname));
    memset(lastname, 0, sizeof(lastname));
    memset(phone, 0, sizeof(phone));
    memset(email, 0, sizeof(email));

    printf("Выберите действие:\n1.Создать контакт\n2.Просмотреть контакт\n3.Редактировать контакт\n4.Удалить контакт\n0.Выход\n");

        input_char(ans, sizeof(ans));
        ansi = atoi(ans);
        
        switch(ansi){
            case ADD:

        name_check = 0;

        printf("Под каким ID (1-5) хотите записать контакт?\n");
        input_char(ans, sizeof(ans));
        id = atoi(ans) -1;
        if(id > 4 || id < 0){
            printf("Такой ID не поддерживается\n");
            break;
            };

            if(contact[id].p.firstname[0] != '\0'){
                printf("Этот ID уже занят, удалите контакт, или выберите другой ID\n");
                break;
            };

        do{
        printf("Имя: ");
        input_char(firstname, sizeof(firstname)); 
        } while(strcmp(firstname, "\0") == 0);

        do{
        printf("Фамилия: ");
        input_char(lastname, sizeof(lastname));
        } while(strcmp(lastname, "\0") == 0);
        
        //name check
        for(int i = 0; i <= NUMBER_OF_CONTACTS - 1; ++i){
            if((strcmp(firstname, contact[i].p.firstname) == 0) && (strcmp(lastname, contact[i].p.lastname) == 0)){
                printf("Контакт с таким именем уже существует под ID = %d\n", i + 1);
                name_check = 1;
                break;
            }
        }
        if(name_check == 1) break;

        printf("Заполнить номер телефона? 1.да 2.нет\n");
        input_char(ans, sizeof(ans));
        ansi = atoi(ans);
        if(ansi == 1){
        printf("Номер телефона: ");
        input_char(phone, sizeof(phone));
        };

        printf("Заполнить адрес электронной почты 1.да 2.нет\n");
        input_char(ans, sizeof(ans));
        ansi = atoi(ans);
        if(ansi == 1){
        printf("Элеткронная почта: ");
        input_char(email, sizeof(email));
        };

        PersonInit(&p, firstname, lastname);
        PhoneInit(&t, phone);
        EmailInit(&e, email);

        ContactInit(&contact[id], p, t, e);
        
        printf("Контакт %s %s успешно создан под %d ID\n\n", firstname, lastname, id + 1);

            break;

            case LOOK:

            //вывод всех контактов по именам с выбором id
        printf("Выберите ID контакта\n");       
        for(int i = 0; i <= 4; i++){
            printf("ID: %d, Name: %s %s\n", i+1, contact[i].p.firstname, contact[i].p.lastname);
        };

        input_char(ans, sizeof(ans));
        ansi = atoi(ans) - 1;
        if(ansi > 4 || ansi < 0){
            printf("Incorrect input");
            break;
        };    
        ContactPrint(&contact[ansi]);
        printf("\n");
            break;

            case DELETE:

            printf("Выберите ID контакта\n");   
        for(int i = 0; i <= 4; i++){
            printf("ID: %d, Name: %s %s\n", i+1, contact[i].p.firstname, contact[i].p.lastname);
        }

        input_char(ans, sizeof(ans));
        ansi = atoi(ans) - 1; 
        if(ansi > 4 || ansi < 0){
            printf("Incorrect input");
            break;
        };
        ContactUnInit(&contact[ansi]);
        printf("Контакт успешно удален\n");
        printf("\n");
            break;

            case EDIT:

            printf("Выберите ID контакта\n");   
        for(int i = 0; i <= 4; i++){
            printf("ID: %d, Name: %s %s\n", i+1, contact[i].p.firstname, contact[i].p.lastname);
        }
        
        input_char(ans, sizeof(ans));
        edit_id = atoi(ans) - 1; 
        if(ansi > 4 || ansi < 0){
            printf("Incorrect input");
            break;
        };

        printf("Выберите, что изменить\n1.Имя и фамилию\n2.Номер телефона\n3.Адрес почты\n0.Отмена\n");
        input_char(ans, sizeof(ans));
        ansi = atoi(ans); 
        if(ansi > 3 || ansi < 0){
            printf("Incorrect input");
            break;
        };

        if(ansi == 1){
            PersonUnInit(&(contact[edit_id].p));
            do{
            printf("Новое имя: ");
            input_char(firstname, sizeof(firstname)); 
            } while(strcmp(firstname, "\0") == 0);
            do{
            printf("Новая фамилия: ");
            input_char(lastname, sizeof(lastname)); 
            } while(strcmp(lastname, "\0") == 0);
            PersonInit(&(contact[edit_id].p), lastname, lastname);
            printf("Имя успешно измнено\n");
        } else if(ansi == 2){
            PhoneUnInit(&(contact[edit_id].t));
            printf("Введите новый номер: ");
            input_char(phone, sizeof(phone));
            PhoneInit(&(contact[edit_id].t), phone);
            printf("Номер успешно изменён\n");
        } else if(ansi == 3){
            EmailUnInit(&(contact[edit_id].e));
            printf("Введите новый адрес: ");
            input_char(email, sizeof(email));
            EmailInit(&(contact[edit_id].e), email);
            printf("Адрес почты успешно измененён\n");           
        };
            printf("\n");
            break;

            case EXIT:
        flag = 0;
            break;

            default:
        printf("Incorrect input\n");
            break;
        }
        

}
   
return 0;
}