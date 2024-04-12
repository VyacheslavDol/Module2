#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "bin_func.h"

#define BIN_REPRES 1
#define STAT_INFO 2
#define EDIT_RIGHTS 3

void printMenu() {
printf("Выберите действие:\n1.Битовоe представление прав доступа\n2.Права доступа файла\n3.Изменение прав доступа\n0.Выход из программы\n");
}

void printInc() {
    printf("Incorrect input\n");
};

void bufclean(){        //очистка буфера
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

int main(void){

int choice, bit[9], n, number, *ptr, newnumber, *newn;
unsigned int  c;
short flag = 1;
ptr = &number;
newn = &newnumber;
char let_arr[10], filename[100], word[8];
memset(bit, 0, sizeof(bit));

while(flag  > 0){

printMenu();
if(scanf("%d",&choice) != 1){
    printInc();
    bufclean();
    continue;
}                             
bufclean();

switch(choice){

    case (BIN_REPRES):
        printf("1.Из числового (777)\n2.Из буквенного (rwxrwxrwx)\n");
        if(scanf("%d",&choice) != 1){
            printInc();
            break;
        };
        bufclean();
        if(choice == 1){                       //из числового формата
            printf("Введите маску права доступа (777):\n");
            n = 0;
            if(scanf("%o", &n) != 1)
                break;
            bufclean();    
            *ptr = n;
        }
        else if(choice == 2){                  //из буквенного формата
            printf("Введите маску права доступа (rwxrwxrwx):\n");
            if(scanf("%s", let_arr) != 1){
                printInc();
                break;
                };
            if(let_bin(let_arr, ptr) == -1){
                printInc();
                break;};
        } else {
            printInc();
            break;
        };
        bin_arr(ptr, bit);                        
        printf("Битовое представление: ");              //вывод битового представления
        for(int i = 8; i >= 0; i--){
        printf("%d", bit[i]);
        };
        printf("\n");
    break;

    case(STAT_INFO):                                                        //права достпуа к файлу                  
        printf("Введите путь к файлу: ");
        fgets(filename, sizeof(filename)/sizeof(filename[0]), stdin);
        filename[strcspn(filename, "\n")] = 0;          // Удаляем символ новой строки
        if(stat_info(filename, ptr) == -1)
            break;
                    printf("Error\n");
        toletter(let_arr, ptr);
        
        printf("Файл: %s\nПрава доступа: %o\t", filename, *ptr);            //вывод прав доступа файла
        for(int i = 8; i >= 0; i--)                                         
            printf("%c", let_arr[i]);                                       
        printf("\t");
        bin_arr(ptr, bit);                                                    
        for(int i = 8; i >= 0; i--)                                         
            printf("%d", bit[i]);                                           
        printf("\n");     
    break;

    case(EDIT_RIGHTS):
        if(*ptr == 0){
        printf("Сначала выберите пункт 1 или 2");
        break;
        };
        
        printf("Актуальные права доступа: ");   //вывод актуальных прав доступа
        printf("%o\t", *ptr);
        toletter(let_arr, ptr);
        for(int i = 8; i >= 0; i--)                                         
            printf("%c", let_arr[i]);                                       
        printf("\t");                                                     
        for(int i = 8; i >= 0; i--)                                         
            printf("%d", bit[i]);                                           
        printf("\n");

        printf("Ввести новые права доступа\n1.В числовом обозначении\n2.В буквенном обозначении\n");
        if(scanf("%d",&choice) != 1){
            printInc();
            break;
        };
        bufclean();
        if(choice == 1){                       //из числового
            printf("Введите маску права доступа в числовом формате (777):\n");
            n = 0;
            if(scanf("%o", newn) != 1){
            printInc();
            break;
        };
            bufclean();    
        }
        else if(choice == 2){                  //из буквенного
            printf("Введите команду измнения прав в буквенном формате (ugo+rwx)\n");
                if(scanf("%7s", word) != 1){
            printInc();
            break;
        };
            right_edit(ptr, word, newn);
        }else{
            printInc();
            break;};

        printf("Прошлое значение: %o\t", *ptr);     //числовое представление старых прав
        for(int i = 8; i >= 0; i--)                 //буквенное представление старых прав                       
            printf("%c", let_arr[i]);                                       
        printf("\t");                                                       
        for(int i = 8; i >= 0; i--)                 //битовое представление старых прав                        
            printf("%d", bit[i]);                                           
        printf("\n");
        
        printf("Новое значение: %o\t", *newn);      //числовое представление новых прав
        toletter(let_arr, newn);                    //буквенное представление новых прав
        for(int i = 8; i >= 0; i--)                                         
            printf("%c", let_arr[i]);                                       
        printf("\t");

        bin_arr(newn, bit);                         //битовое представление новых прав
        for(int i = 8; i >= 0; i--){
        printf("%d", bit[i]);
        };
        printf("\n");

        *ptr = *newn;
    break;
    case(0):
    flag = 0;
    break;
    default:
        printInc();
        break;
    };
}
return 0;
}
