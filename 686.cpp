#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<char> is_prime(32768,0);
    vector<int> prime;
    for(int i=2;i<=32767;i++)
    {
        if(is_prime[i]==0)
        {
            prime.push_back(i);
            for(int k=2*i;k<=32767;k+=i)
                is_prime[k]=1;
        }
    }
    int num,count;
    while(cin>>num&&num!=0)
    {
        count=0;
        for(int i=0;prime[i]<=num/2;i++)
        {
            if(is_prime[num-prime[i]]==0)
                count++;
        }
        cout<<count<<endl;
    }
}
