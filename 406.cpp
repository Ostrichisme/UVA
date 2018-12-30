#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("1.txt");
    bool num[1001]={0};
    int prime[1001]={0},count=1,n,c,temp,l,r;
    prime[0]=1;
    for(int i=2;i<=1000;i++)
    {
        if(num[i]==0)
        {
            prime[count]=i;
            count++;
            for(int k=2*i;k<=1000;k+=i)
            {
                num[k]=1;
            }
        }
    }
    while(cin>>n>>c)
    {
        cout<<n<<" "<<c<<":";
        count=0;
        for(int i=1;i<=n;i++)
        {
            if(num[i]==0)
                count++;
        }
        //cout<<count<<endl;

        if(count%2==1)
        {
            temp=2*c-1;
            if(temp>=count)
            {
                l=0;
                r=count-1;
            }
            else
            {
                count=count/2;
                l=count;
                r=count;
                temp--;
                while(temp)
                {
                    l--;
                    r++;
                    temp-=2;
                }
            }
        }
        else
        {
            temp=2*c;
            if(temp>=count)
            {
                l=0;
                r=count-1;
            }
            else
            {
                count=count/2;
                l=count-1;
                r=count;
                temp-=2;
                while(temp)
                {
                    l--;
                    r++;
                    temp-=2;
                }
            }
        }

        for(int i=l;i<=r;i++)
            cout<<" "<<prime[i];
        cout<<endl<<endl;
    }
}

