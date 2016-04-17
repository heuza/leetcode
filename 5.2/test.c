#include<stdio.h>
#include<Print.h>
int insertBit(int N, int M, int i ,int j){
    unsigned _N = (unsigned)N;
    _N=_N<<(8*sizeof(int) -j-1)>>(8*sizeof(int)-j-1);
    _N=_N>>(i)<<(i);
    print_binary(_N);
    N^=_N;
    N|=M<<i;
    return N;
}
int main()
{
    int N = 1<<10;
    int M = 0x13;
    int ret;
    printf("N ="); 
    print_binary(N);
    printf("M ="); 
    print_binary(M);
    ret = insertBit(N,M,2,6);
    printf("ret = ");
    print_binary(ret);
    return 0;

}
