#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
    int num;
    vector <char> is_prime(10000001,1);
    int n=sqrt(10000000)+0.001,count=0;
    vector <int> prime;
    for(int i=2;i<=n;i++)
    {
        if(is_prime[i]==1)
        {
            prime.push_back(i);
            for(int k = i*2 ; k <= 10000000 ; k = k+i)
                is_prime[k] = 0;
        }
    }
    while(cin>>num)
    {
        if(num%2==0)
        {
            num=num-4;
            if(num<4)
                cout<<"Impossible."<<endl;
            else
                {
                    for(int i=0;i<prime.size();i++)
                    {
                        if(is_prime[num-prime[i]]==1)
                        {
                            cout<<"2 2 "<<prime[i]<<" "<<num-prime[i]<<endl;
                            break;
                        }
                    }
                }
        }
        else
        {
            num=num-5;
            if(num<4)
                cout<<"Impossible."<<endl;
            else
                {
                    for(int i=0;i<prime.size();i++)
                    {
                        if(is_prime[num-prime[i]]==1)
                        {
                            cout<<"2 3 "<<prime[i]<<" "<<num-prime[i]<<endl;
                            break;
                        }
                    }
                }
        }
    }

}

