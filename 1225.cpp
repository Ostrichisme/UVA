#include<iostream>
using namespace std;
int main()
{
    int test,i,num,digit[10];
    cin>>test;
    while(test--)
    {
        for(i=0;i<=9;i++)
        digit[i]=0;
        cin>>num;
        for(i=1;i<=num;i++)
        {
            int count,count1;
            count=i;
            while((count/10)>0)
            {
                count1=count%10;
                digit[count1]++;
                count=count/10;
            }
            count1=count%10;
            digit[count1]++;
        }
        for(i=0;i<=9;i++)
        {
            cout<<digit[i];
            if(i<9)
            cout<<" ";
        }
        cout<<endl;
    }
}
