// calc
#include <stdio.h>


int main(void) {
    double a = 0, b = 0;
    int oprt;
    char flag = 1;
    while (flag == 1) {
    printf("выберите действие:\n 1.Суммирование\n 2.Вычитание\n 3.Умножение\n 4.Деление\n 0.Выход\n");
    if(scanf("%d", &oprt) != 1) {
        printf("Error input\n");
        return 0;
    }
    if(oprt != 0) {
    printf("Введите значение первого числа\n");
    scanf("%lf", &a);
    printf("Введите значение второго числа\n");
    scanf("%lf", &b);
    }
    switch(oprt) {
        case 1:
            printf("%.3lf + %.3lf = %.3lf\n", a, b, a + b);                    
        break;
        case 2: 
            printf("%.3lf - %.3lf = %.3lf\n", a, b, a - b);
        break;
        case 3:
            printf("%.3lf * %.3lf = %.3lf \n", a, b, a * b);
        break;
        case 4:
            if(b != 0)
                printf("%.3lf / %.3lf = %.3lf\n", a, b, a / b);
            else
                printf("%.3lf / %.3lf undefined\n", a, b);    
        break;
        case 0:
            return 0;        
        default:
            printf("incorrect input");
    }

    }
return 0;
}