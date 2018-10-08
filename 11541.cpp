#include<iostream>
using namespace std;
int main()
{
    int test,num,n,i;
    char ch;
    cin>>test;
    cin.get();
    for(i=1;i<=test;i++)
    {
        n=0;
        while(cin.get(ch)&&ch!='\n')
        {
            cin>>num;
            while(num--)
            {
                if(n==0)
                {
                    cout<<"Case "<<i<<": ";
                    n=1;
                }
                cout<<ch;
            }
        }
    cout<<endl;
    }
    return 0;
}
