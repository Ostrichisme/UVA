#include<iostream>
using namespace std;
int main()
{
    int num[1001],num1[1001],num2[1001],order,i,test,x;
    while(cin>>test)
    {
        int flag1=1,flag2=1,flag3=1,count=0,count1=0,first=0;
        while(test--)
        {
            cin>>order>>x;
            if(order==1)
            {
                num[count]=x;
                num1[count]=x;
                num2[count]=x;
                count1=count;
                count++;
            }
            else
            {
                if(flag1==1)
                {
                    if(x==num[count1])
                    {
                        num[count1]=-1;
                        do
                        {
                            count1--;
                        }while(num[count1]==-1);
                    }
                    else
                    flag1=0;
                }
                if(flag2==1)
                {
                    if(x==num1[first])
                    first++;
                    else
                    flag2=0;
                }

                if(flag3==1)
                {
                      int max=-1,store;
                    for(i=0;i<=count-1;i++)
                    {
                        if(num2[i]>max)
                        {
                            max=num2[i];
                            store=i;
                        }
                    }
                    if(x==max)
                    num2[store]=-1;
                    else
                    flag3=0;
                }
            }
        }
        if(flag1==1&&flag2==0&&flag3==0)
        cout<<"stack"<<endl;
        else if(flag2==1&&flag1==0&&flag3==0)
        cout<<"queue"<<endl;
        else if(flag3==1&&flag2==0&&flag1==0)
        cout<<"priority queue"<<endl;
        else if(flag1==0&&flag2==0&&flag3==0)
        cout<<"impossible"<<endl;
        else
        cout<<"not sure"<<endl;
    }

}
