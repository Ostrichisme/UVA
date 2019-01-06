#include<iostream>
#include<vector>
using namespace std;
char prime[100000001]={0};
int main()
{
    for(int i=2;i*i<=100000000;i++)
    {
        if(prime[i]==0)
        {
            for(int k=2*i;k<=100000000;k+=i)
                prime[k]=1;
        }
    }
    int num;
    while(cin>>num)
    {
        if(num<5)
            cout<<num<<" is not the sum of two primes!\n";
        else if(num%2==1)
        {
            if(prime[num-2]==0)
                cout<<num<<" is the sum of 2 and "<<num-2<<".\n";
            else
                cout<<num<<" is not the sum of two primes!\n";
        }
        else
        {
            int flag=0;
            for(int i=(num-1)/2;i>=3;i--)
            {

                if(prime[i]==0&&prime[num-i]==0)
                {
                    flag=1;
                    cout<<num<<" is the sum of "<<i<<" and "<<num-i<<".\n";
                    break;
                }
            }
            if(flag==0)
                cout<<num<<" is not the sum of two primes!\n";
        }
    }

}
