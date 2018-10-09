#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue <int> blue,red;
    int test,build,num,flag;
    cin>>test;
    while(test--)
    {
        int ans=1;
        while(!red.empty())
        red.pop();
        while(!blue.empty())
            blue.pop();

        cin>>build;
        if(build==0)
        {
            continue;
        }
        while(build--)
        {
            cin>>num;
            if(num>0)
                blue.push(num);
            else
                red.push(-num);
        }
        if(blue.empty())
        {
            continue;
        }
        else if(red.empty())
        {
            continue;
        }
        if(blue.top()>red.top())
            flag=1;
        else
            flag=0;
        while(1)
        {
            if(flag==1)
            {
                if(red.empty())
                    break;
                if(red.top()>blue.top())
                    red.pop();
                else
                {
                    blue.pop();
                    ans++;
                    flag=0;
                }
            }
           else
            {
                if(blue.empty())
                    break;
                if(blue.top()>red.top())
                    blue.pop();
                else
                {
                    red.pop();
                    ans++;
                    flag=1;
                }
            }
        }
        cout<<ans<<endl;
        while(!red.empty())
            red.pop();
        while(!blue.empty())
            blue.pop();
    }
}
