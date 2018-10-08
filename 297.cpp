#include<iostream>
#include<string>
using namespace std;
int tree_1[33][33]={0},tree_2[33][33]={0},x=-1;
string str;
void func(int i,int j,int m,int n)
{

    x++;
    if(str[x]=='p')
    {
        func(i,i+(j-i)/2,m+(n-m)/2+1,n);
        func(i,i+(j-i)/2,m,m+(n-m)/2);
        func(i+(j-i)/2+1,j,m,m+(n-m)/2);
        func(i+(j-i)/2+1,j,m+(n-m)/2+1,n);
    }
    else if(str[x]=='e');
    else if(str[x]=='f')
    {
        for(int row=i;row<=j;row++)
        for(int line=m;line<=n;line++)
        tree_1[row][line]=1;
    }
}
void func2(int i,int j,int m,int n)
{
    x++;
    if(str[x]=='p')
    {
        func2(i,i+(j-i)/2,m+(n-m)/2+1,n);
        func2(i,i+(j-i)/2,m,m+(n-m)/2);
        func2(i+(j-i)/2+1,j,m,m+(n-m)/2);
        func2(i+(j-i)/2+1,j,m+(n-m)/2+1,n);
    }
    else if(str[x]=='e');
    else if(str[x]=='f')
    {
        for(int row=i;row<=j;row++)
        for(int line=m;line<=n;line++)
        tree_2[row][line]=1;
    }
}
int main()
{
    int test,ans=0;

    cin>>test;
    while(test--)
    {
        cin>>str;
        func(1,32,1,32);
        x=-1;
        cin>>str;
        func2(1,32,1,32);
        x=-1;
        for(int row=1;row<=32;row++)
        for(int line=1;line<=32;line++)
        if(tree_1[row][line]==1||tree_2[row][line]==1)
        ans++;
        cout<<"There are "<<ans<<" black pixels.\n";
        ans=0;
        for(int row=1;row<=32;row++)
        for(int line=1;line<=32;line++)
        {
            tree_1[row][line]=0;
            tree_2[row][line]=0;
        }
    }
    return 0;
}
