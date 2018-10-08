#include<iostream>
#include<cmath>
using namespace std;
void func(int first,int end,int h)
{
    int n;
    for(n=first;n<=end;n++)
    {
        if((n-first)<=(pow(2,h-1)-1)&&(end-n)<=(pow(2,h-1)-1))
        {
            cout<<" "<<n;
            if(n-first!=0)
            func(first,n-1,h-1);
            if(end-n!=0)
            func(n+1,end,h-1);
            break;
        }
    }
}
int main()
{
    int num,h,m,i=1;
    while(cin>>num>>h&&num!=0&&h!=0)
    {
        cout<<"Case "<<i<<":";
        if(num>pow(2,h)-1)
        cout<<" Impossible.";
        else
        func(1,num,h);
        cout<<endl;
        i++;
    }
}
