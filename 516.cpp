#include<iostream>
#include<vector>
#include<cmath>
#include<sstream>
#include<string>
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
    string s;
    stringstream ss;
    int a,b,num,count,index,flag;
    while(1)
    {
        getline(cin,s);
        if(s=="0")
            break;
        ss.str("");
        ss.clear();
        ss<<s;
        num=1;
        while(ss>>a>>b)
        {
            num=num*pow(a,b);
        }
        num=num-1;
        index=prime.size()-1;
        flag=0;
        while(prime[index]>num)
        {
            index--;
        }
        for(int i=index;i>=0;i--)
        {
            if(num==1)
                break;
            else if(num%prime[i]==0)
            {
                count=0;
                while(num%prime[i]==0)
                {
                    num/=prime[i];
                    count++;
                }
                if(flag==0)
                    flag=1;
                else
                    cout<<" ";
                cout<<prime[i]<<" "<<count;
            }
        }
        cout<<endl;

    }

}
