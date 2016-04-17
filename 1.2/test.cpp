#include<iostream>
using namespace std;
#define SWAP(x,y) ((x=x^y),(y=x^y),(x=x^y))
void reverse(char* str){
    int len=0;
    char* p= str;
    char* p1= str;
    while(*p++!='\0')len++;
    //printf("p  =%lu\nstr=%lu\n",p,str);
    //cout<<"len="<<len<<endl;
    p=str+len-1;
    while(str<  p){
        SWAP(*str,*p);
        str++;
        p--;
    }
    printf("%s\n",p1);
}
int main()
{
    reverse(strdup("test"));
    reverse(strdup("test1"));
    reverse(strdup("123456"));
        return 0;

}
