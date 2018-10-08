#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long int num[5843],count=1,i,amount=1,test,keep;
    num[1]=1;
    while(1)
    {
        for(i=1;i<=count;i++)
        {
            if(num[amount]*2>2000000000||num[amount]*2==num[i])
            break;
        }
        if(i==count+1)
        {
                 count++;
                num[count]=num[amount]*2;
        }
        if(count>=5842)
        break;
        for(i=1;i<=count;i++)
        {
            if(num[amount]*3>2000000000||num[amount]*3==num[i])
            break;
        }
        if(i==count+1)
        {
            count++;
            num[count]=num[amount]*3;
        }
        if(count>=5842)
        break;
        for(i=1;i<=count;i++)
        {
            if(num[amount]*5>2000000000||num[amount]*5==num[i])
            break;
        }
        if(i==count+1)
        {
                count++;
                num[count]=num[amount]*5;
        }
        if(count>=5842)
        break;
        for(i=1;i<=count;i++)
        {
            if(num[amount]*7>2000000000||num[amount]*7==num[i])
            break;
        }
        if(i==count+1)
        {
                count++;
                num[count]=num[amount]*7;
        }
        if(count>=5842)
        break;
        amount++;
    }
    sort(num+1,num+5843);
    while(cin>>test&&test!=0)
   {
       keep=test;
       keep=keep%100;
       if(keep==1||keep==21||keep==31||keep==41||keep==51||keep==61||keep==71||keep==81||keep==91)
       cout<<"The "<<test<<"st humble number is "<<num[test]<<".\n";
       else if(keep==2||keep==22||keep==32||keep==42||keep==52||keep==62||keep==72||keep==82||keep==92)
       cout<<"The "<<test<<"nd humble number is "<<num[test]<<".\n";
       else if(keep==3||keep==23||keep==33||keep==43||keep==53||keep==63||keep==73||keep==83||keep==93)
       cout<<"The "<<test<<"rd humble number is "<<num[test]<<".\n";
       else
       cout<<"The "<<test<<"th humble number is "<<num[test]<<".\n";
   }

}
