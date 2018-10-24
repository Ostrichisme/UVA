#include<iostream>
#include<vector>
using namespace std;
bool prime_judge(long long num, vector <char> &is_prime,vector <long long> &prime)
{
    if(num<=100000)
    {
        if(is_prime[num])
            return true;
        else
            return false;
    }
    else
    {
        for(long long i=0;i<prime.size();i++)
        {
            if(num%prime[i]==0)
                return false;
        }
        return true;
    }
}
long long digit_add(long long num)
{
    long long ans=0;
    while(num)
    {
        ans+=num%10;
        num/=10;
    }
    return ans;

}
int main()
{
    vector <char> is_prime(100001,1);
    vector <long long> prime;
    long long test,num;
    for(long long i=2;i<=100000;i++)
    {
        if(is_prime[i]==1)
        {
            prime.push_back(i);
            for(long long k=2*i;k<=100000;k=k+i)
                is_prime[k]=0;
        }
    }
    cin>>test;
    while(test--)
    {

        cin>>num;
        for(long long i=num+1;;i++)
        {
            long long temp=i,ans,factor_ans=0;

            if(prime_judge(i,is_prime,prime))
                continue;
            ans=digit_add(i);
            for(long long j=0;j<prime.size()&&prime[j]*prime[j]<=temp;j++)
            {
                while(temp%prime[j]==0)
                {
                    temp/=prime[j];
                    factor_ans+=digit_add(prime[j]);
                }

            }
            if(temp==i)
                continue;
            if(temp!=1)
            {
                factor_ans+=digit_add(temp);
            }
            if(ans==factor_ans)
            {
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
