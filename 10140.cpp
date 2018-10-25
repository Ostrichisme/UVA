#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int n=sqrt(2147483647)+0.001;
vector <char> is_prime (n+1,1);
vector <int>prime;
void prime_table()
{
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i])
        {
            prime.push_back(i);
            for(int k=2*i;k<=n;k+=i)
                is_prime[k]=0;
        }
    }
}
void calc(int count,int L,int U)
{
    vector <char> interval(count,1);
    vector <int> interval_prime;
    if(L==1)
        interval[0]=0;
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=U;i++)
    {
         int s=(L-1)/prime[i]+1;
         if(s<2)
            s=2;
        for(unsigned int k=s*prime[i];k<=U;k+=prime[i])
        {
            interval[k-L]=0;
        }

    }
    for(int i=0;i<count;i++)
    {
        if(interval[i]==1)
            interval_prime.push_back(i+L);
    }
    if(interval_prime.size()<2)
        cout<<"There are no adjacent primes."<<endl;
    else
    {
        int adjacent=2147483647,distant=-2147483647,p1,p2,p3,p4;
        for(int i=0;i<interval_prime.size()-1;i++)
        {
            if(interval_prime[i+1]-interval_prime[i]<adjacent)
            {
                p1=interval_prime[i];
                p2=interval_prime[i+1];
                adjacent=interval_prime[i+1]-interval_prime[i];
            }
            if(interval_prime[i+1]-interval_prime[i]>distant)
            {
                p3=interval_prime[i];
                p4=interval_prime[i+1];
                distant=interval_prime[i+1]-interval_prime[i];
            }
        }
        cout<<p1<<","<<p2<<" are closest, "<<p3<<","<<p4<<" are most distant."<<endl;
    }

}
int main()
{
    prime_table();
    int L,U;
    while(cin>>L>>U)
    {
        calc(U-L+1,L,U);
    }
}
