#include <stdio.h>
#include "mymaths.h"


int main(void) {
    double a = 0, b = 0;
    double (*operation)(double, double); //function pointer
    char symbol = ' ';
    int deyst, flag = 1;

    while (flag == 1) {
    printf("Выберите действие:\n 1.Суммирование\n 2.Вычитание\n 3.Умножение\n 4.Деление\n 0.Выход из программы\n");
    if(scanf("%d", &deyst) != 1){
        printf("Incorrect input\n");
        continue;
    };
    if(deyst == 0)
        return 0;
    printf("Введите значение первого числа \n");
    if(scanf("%lf", &a) != 1){
        printf("Incorrect input\n");
        //continue;
    };
    printf("Введите значение второго числа \n");
    if(scanf("%lf", &b) != 1){
        printf("Incorrect input\n");
        //continue;
    };

switch(deyst) {
    case 1:
        operation = mysum;
        symbol = '+';                     
    break;
    case 2: 
        operation = mysubstr;
        symbol = '-';
    break;
    case 3:
        operation = mymult;
        symbol = '*';
    break;
    case 4:
        if(b != 0) {
            operation = mydiv;
        symbol = '/'; 
            }
        else
            printf("%.3lf / %.3lf undefined\n", a, b);    
    break;
    case 0:
        return 0;        
    default:
        printf("incorrect input");
    break;    
};
printf("%.3lf %c %.3lf = %.3lf\n", a, symbol, b, operation(a, b));    // вывод результата
};
return 0;
}