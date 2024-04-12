#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

struct stat filestat;

/*int triada_bin(int a, int *ptr) {         //представление в %0x из %d для перевода в маску доступа

int b, i = 0, y = 0;
*ptr = 0;
while(a > 0){
    b = a % 10;
    a = a / 10;
    if((b >= 3 && b <=7 || b == 0) & i <= 6){
        y = b << i;
        *ptr = *ptr | y;
        i = i + 3;    
    }
    else return -1;
};

return 0;
}; */

int let_bin(char arr[], int *ptr) {         //представление в числовом формате из буквенного

*ptr = 0;
for(int i = 8, j = 0; i >= 0; i--, j++){
    if((arr[j] == 'r' && (((i-2) % 3) == 0)) || (arr[j] == 'w' && (((i-1) % 3) == 0)) || (arr[j] == 'x' && ((i % 3) == 0)))
        *ptr |= 1 << i;
    else if(arr[j] == '-')
        *ptr &= ~(1 << i);
    else{
        return -1;
        };
};
return 0;    
}

void bin_arr(int *ptr,  int arr[]) {           //получение массива битов (1 и 0)

int mask;                               
for(int i = 8; i > -1 ; i--){
    mask = 1 << i;
    arr[i] = ((*ptr | mask) == *ptr) ? 1 : 0;
}; 
}

int stat_info(char* filename, int *ptr){      //получение прав доступа с помощью функции stat

    if (stat(filename, &filestat) == 0){
    *ptr = filestat.st_mode & 0777;
    } else {
        perror("Ошибка при вызове функции stat");
        return -1;
    };

return 0;
}

int toletter(char arr[], int *ptr){             //буквенное представление из числового
    int mask;
    for(int i = 8; i >= 0; i--){
    mask = 1 << i;
    if((*ptr | mask) == *ptr){
        if(((i - 2) % 3) == 0)
            arr[i] = 'r';
        if(((i -1) % 3) == 0)
            arr[i] = 'w';
        if((i % 3) == 0)
            arr[i] = 'x';
    } else {
        arr[i] = '-';
    };               
    };
    return 0;
    }

int right_edit(int *oldnum, char let[], int *newnum){   //изменение прав доступа с помощью модификатора

char c, y, oldy;
y = *newnum;
oldy = *oldnum;
int val = 0, flag, mask = 0;
for(int i = 7; i>=0; i--){
c = let[i];
if(c == 'x')
    val += 1;
if(c == 'w')
    val += 2;
if(c == 'r')
    val += 4;    
if(c == '+')
    flag = 1;
if(c == '-')
    flag = 0;
if(c == 'o')
    mask |= (val << 0);
if(c == 'g')
    mask |= (val << 3);
if(c == 'u')
    mask |= (val << 6);               
};
if(flag == 1){
    *newnum = *oldnum | mask;
} else {
    *newnum = *oldnum & (~(mask));
};
}