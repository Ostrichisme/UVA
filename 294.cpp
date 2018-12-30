#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int num=sqrt(1000000000)+0.01,test,max,l,u,ans,count,temp1,temp2;
    vector <char> is_prime (num+1,0);
    vector <int>prime;
    for(int i=2;i<=num;i++)
    {
        if(is_prime[i]==0)
        {
            prime.push_back(i);
            for(int k=2*i;k<=num;k+=i)
                is_prime[k]=1;

        }
    }
    cin>>test;
    while(test--)
    {
        cin>>l>>u;
        count=-1;
        for(int i=l;i<=u;i++)
        {
            temp1=1;
            int dec=i;
            int flag=0;
            if(i==1)
            {
                ans=1;
                count=1;
                continue;
            }
            for(int j=0;j<prime.size()&&i>prime[j];j++)
            {

                temp2=0;
                if(dec%prime[j]==0)
                {
                    while(dec%prime[j]==0)
                    {
                        dec/=prime[j];
                        flag=1;
                        temp2++;
                    }
                    temp1*=(temp2+1);
                }
                if(dec==1)
                    break;
            }
            if(i==6)
            cout<<temp1<<endl;
            if(flag==0)
                temp1=2;
            if(temp1>count)
            {
                ans=i;
                count=temp1;
            }
        }
        cout<<"Between "<<l<<" and "<<u<<", "<<ans<<" has a maximum of "<<count<<" divisors.\n";
    }



}
