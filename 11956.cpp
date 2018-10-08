#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    int test,i,n,num[100],x;
    char ch[2];
    string order;
    cin>>test;
    for(n=1;n<=test;n++)
    {
         memset(num,0,sizeof(num));
         x=0;
        cin>>order;
        for(i=0;i<order.length();i++)
        {
            if(order[i]=='.');
            else if(order[i]=='+')
            num[x]++;
            else if(order[i]=='-')
            num[x]--;
            else if(order[i]=='>')
            {
                x++;
                if(x>99)
                x=x-100;
            }
            else if(order[i]=='<')
            {
                x--;
                if(x<0)
                x=x+100;
            }
        }
        cout<<"Case "<<n<<": ";


        for(i=0;i<100;i++)
        {
            x=1;
            memset(ch,'0',sizeof(ch));
            while(num[i]<0)
            num[i]=num[i]+256;
            while(num[i]/256)
            num[i]=num[i]-256;
            while(num[i]/16)
           {

            if(num[i]%16<10)
            {
                ch[x]=num[i]%16+48;
                x--;
            }
            else
            {
                ch[x]=num[i]%16+55;
                x--;
            }
            num[i]=num[i]/16;
           }
            if(num[i]%16<10)
            ch[x]=num[i]%16+48;
            else
            ch[x]=num[i]%16+55;

            cout<<ch[0]<<ch[1];
            if(i<99)
            cout<<" ";
        }
        cout<<endl;
    }
}
