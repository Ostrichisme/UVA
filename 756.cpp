#include<iostream>
using namespace std;
int main()
{
    int p,e,i,d,a,b,c,total,ans,x,count=1;
    while(cin>>p>>e>>i>>d)
    {
        if(p==-1&&e==-1&&i==-1&&d==-1)
        break;
        total=23*28*33;
        x=1;
        while((28*33*x-p)%23!=0)
        {
            x++;
        }
        a=28*33*x;
        x=1;
        while((23*33*x-e)%28!=0)
        {
            x++;
        }
        b=23*33*x;
        x=1;
        while((23*28*x-i)%33!=0)
        {
            x++;
        }
        c=23*28*x;

        ans=(a+b+c)%total;
        if(ans==0)
        ans=total;
        ans-=d;
        cout<<"Case "<<count<<": the next triple peak occurs in "<<ans<<" days.\n";
        count++;


    }
}
