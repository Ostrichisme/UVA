#include<iostream>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        if(m==0)
        {
            cout<<1<<endl;
            continue;
        }
        long long int ans=1;
        for(int i=n;i>=(n-m+1);i--)
        {
            ans=ans*i;
            while(ans%10==0)
            {
                ans/=10;
            }
            long long int max=1e9;
            ans%=max;

        }
        cout<<ans%10<<endl;
    }
}
