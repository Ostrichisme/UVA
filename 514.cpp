#include<iostream>
using namespace std;
int main()
{
    int train,result[1001],st[1001],i,n,m,b,x;
    while(cin>>train&&train!=0)
    {
           while (cin>>result[1])
           {
               if(result[1]==0)
                break;
                for(b=2;b<=train;b++)
                cin>>result[b];
                n=1;
                m=1;
                x=0;
                st[0]=0;
                for(i=1;i<=train;i++)//°j°é¶]§¹¥Nªíyes
                {
                    while(n<=train)
                    {
                        if(result[i]==n)
                        {
                            n++;
                            x=1;
                            break;
                        }
                        else if(result[i]==st[m-1])
                        {
                            m--;
                            x=1;
                            break;
                        }
                        else
                        {
                            st[m]=n;
                            m++;
                            n++;
                        }
                    }
                    if(x==1)
                    {
                        x=0;
                        continue;
                    }
                    if(result[i]==st[m-1])
                    {
                        m--;
                        continue;
                    }
                    else
                    break;
                }
                if(i==train+1)
                cout<<"Yes\n";
                else
                cout<<"No\n";
           }
        cout<<endl;
    }
    return 0;
}
