#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<char> is_prime(1001,0);
    vector<int> prime;
    for(int i=2;i<=1000;i++)
    {
        if(is_prime[i]==0)
        {
            prime.push_back(i);
            for(int k=i*2;k<=1000;k+=i)
                is_prime[k]=1;
        }
    }
    int test,flag1,flag2,b;
    while(cin>>test&&test!=0)
    {
        flag1=0;
        for(int i=0;i<prime.size();i++)
        {

            if(prime[i]%2==1)
            {
                b=test-prime[i];
                flag2=0;
                for(int j=0;j<prime.size()&&prime[j]<b;j++)
                {
                    if(b%prime[j]==0)
                    {
                        flag2=1;
                        break;
                    }
                }
                if(flag2==0&&b%2==1)
                {
                    cout<<test<<" = "<<prime[i]<<" + "<<b<<endl;
                    flag1=1;
                    break;
                }

            }
        }
        if(flag1==0)
        {
            cout<<"Goldbach's conjecture is wrong.\n";
        }
    }
}
