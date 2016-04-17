#include<iostream>
using namespace std;
#define ISBIT(x,n) ((x)&(1<<(n)))
#define SETBIT(x,n) ((x)|=(1<<(n)))
bool uniq(const char* str) {
    char map[32]={0};
    for(const char* p=str;*p!='\0';p++){
        printf("col =%d,shift=%d\n",*p>>3,*p&7);
       if(ISBIT(map[*p>>3],(*p&7)) ==0){
          SETBIT(map[*p>>3],(*p&7));
       }else{
          return false; 
       }
    }
    return true;
}
int main()
{
    cout<<uniq("esat");
    cout<<endl;
    return 0;

}
