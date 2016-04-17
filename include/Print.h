#include<stdio.h>
#include<stdlib.h>
void print_binary(int n){
    int* v;
    v = (int*)calloc(8*sizeof(int),sizeof(int));
    int mask = 1;
#if 0
    i=0;
    printf("0b");
    while(i<8*sizeof(int)){
        printf("%d",v[i]);
        i++;
    }
    printf("\n");
#endif
    int i=1;
    while(i<=8*sizeof(int)){
        v[8*sizeof(int)-i]=(n&mask)?1:0;
        mask <<= 1;
        i++;
    }
    i=0;
    printf("0b");
    while(i<8*sizeof(int)){
        printf("%d",v[i]);
        i++;
    }
    printf("\n");
}
