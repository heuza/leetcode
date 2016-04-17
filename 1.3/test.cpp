#include<iostream>
using namespace std;
bool isPerm(char* str1, char* str2){
    int map[256]={0};
    while(*str1 && *str2){
       map[*(str1++)]++;
       map[*(str2++)]--;
    }
    if(*str1==*str2){
        for(int i =0;i<256;i++)
            if(map[i]!=0)
                return false;
        return true;
    }
    return false;
}
int main()
{
    cout<<isPerm("test1abcd","abdcest1t")<<endl;

    return 0;

}
