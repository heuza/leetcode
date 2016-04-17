#include<iostream>
using namespace std;
void replace(char* str){
    int space_cnt=0;
    char* p = str;
    char* last;
    while(*p!='\0'){
        if(*p == ' ')
            space_cnt++;
        p++;
    }
    printf("p=%d\n",p-str);
    last=p+2*space_cnt;
    printf("l=%d\n",last-str);
    while(str<=p){
        if(*p!=' ')
            *last=*p;
        else {
            *last--='0';
            *last--='2';
            *last='%';
        }
        last--;
        p--;
    }
    cout<<str<<endl;
}
int main()
{
    char s[256]="test";
    char s1[256]="te st";
    //char s2[256]="test ";
    char s2[256]=" test test ";
    replace(s);
    replace(s1);
    replace(s2);
    return 0;

}
