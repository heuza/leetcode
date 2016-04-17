#include<iostream>
using namespace std;
char* compress(char* str)
{
    char* p = str;
    char* p2;
    char* p3= (char*)calloc(256,0);
    char* p4=p3;
    char tmp[10];
    int len=0;
    int power=0;
    while(*p != '\0'){
        p2=p; 
        while(*p != '\0' && *p==*(p+1))p++;
        p++;
        len+=1;
        *p3++=*p2;
        p3+=sprintf(p3,"%d",p-p2);
    }
    //cout<<"px="<<p4<<endl;
    if(strlen(p4)<strlen(str))
        return p4;
    free(p4);
    return str;
}
int main()
{
    cout<<compress("tttttttttttaaab");
    cout<<endl;
        return 0;

}
