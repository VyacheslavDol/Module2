#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]){
    if (argc != 4) {
        printf("Необходимо ввести 3 аргумента командной строки (IP шлюза (0x..) маска (0x..) кол-во пакетов)\n");
        return 1;
    };
    char *input1 = argv[1];
    int IP_unit = (int)strtol(input1, NULL, 16);    //IP узла   например (0xC0A8010A)
    char *input2 = argv[2];
    int Mask = (int)strtol(input2, NULL, 16);   //маска подсети    например (0xFFFFFF00)
    int N = atoi(argv[3]);                      //кол-во пакетов          
    int Net_unit, IP_dst, Net_dst, Result;
    int count = 0, packet_not_unit_net;
    srand(time(NULL));              
    Net_unit = IP_unit & Mask;      //адрес "своей" подсети
    for(int i = 1; i <= N; i++){
    IP_dst = rand() + rand() + 1;   // от 1 до 4294967294 - адрес назначения
    Net_dst = IP_dst & Mask;        //адрес сети назначения
    Result = Net_unit ^ Net_dst;
    if(Result == 0){
        count++;
    };
    };         

    printf("Пакетов узлам своей подсети: %d, %lf %%\n", count, 100.0 * (double)count / (double)N);
    printf("Пакетов узлам других подсетей: %d, %lf %%\n", N - count, 100.0 - (100.0 * (double)count / (double)N));
    return 0;
}


