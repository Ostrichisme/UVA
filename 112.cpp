#include<iostream>
using namespace std;
bool check;
int test;
char ch;
void func(int sum,int aa)//sum=At present the total  when you call  func aa is 0
{
    int num1=0;
    while(cin.get(ch))//eat space&endl
    {
        if(ch==')')
        {
            aa=1;
            break;
        }
        else if (ch=='-')
        {
            cin>>num1;
            num1=num1*-1;//the value of the node字
            while(cin.get(ch)&&ch!='(');//before you call the func,you need to eat '(' ex:(5(-10'('
            func(sum+num1,0);
            break;
        }
        else if(ch>=48&&ch<=57)
        {
          do
          {
              if(ch>=48&&ch<=57)//if ch==' '||'\' do not calculate
              num1=10*num1+ch-48;//the value of the node
          }
          while(cin.get(ch)&&ch!='(');//before you call the func,you need to eat '(' ex:(5(10'('
          func(sum+num1,0);
            break;
        }
    }
    num1=0;//以under the line is the code of right node
    while(cin.get(ch)&&ch!='(');//you need to ignore space endl &')' and need  to eat '(' ex : (5()'('
    while(cin.get(ch))
    {

        if(ch==')')
        {
            if(aa==1)//空的if left node &right node are both no value
            {
                if(sum==test)
                check=1;
            }
            break;
        }
        else if (ch=='-')
        {
            cin>>num1;
            num1=num1*-1;
            while(cin.get(ch)&&ch!='(');//before you call the func,you need to eat '(' ex:(5()(-10'('
            func(sum+num1,0);
            while(cin.get(ch)&&ch!=')');
            break;
        }
        else if(ch>=48&&ch<=57)
        {
          do
          {
              if(ch>=48&&ch<=57)//if ch==' '||'\' do not calculate
              num1=10*num1+ch-48;//the value of the node字
          }
          while(cin.get(ch)&&ch!='(');
          func(sum+num1,0);
          while(cin.get(ch)&&ch!=')');//吃before you call the func,you need to eat '(' ex:(5()(10'('
            break;
        }
    }
}
int main()
{
    int x,num=0;
    while(cin>>test)
    {
        x=0;
        check=0;
        num=0;
       while(cin.get(ch))//eat the first'(' ex: 15 '('
    {
        if(ch==')')// no tree
        {
            x=1;
            break;
        }
        else if (ch=='-')
        {
            cin>>num;
            num=num*-1;
            while(cin.get(ch)&&ch!='(');

                      //before you call the func,you need to eat '(' ex:(-5'('
            break;
        }
        else if(ch>=48&&ch<=57)
        {
          do
          {
              if(ch>=48&&ch<=57)//if ch==' '||'\' do not calculate
              num=10*num+ch-48;//the value of the node
          }
          while(cin.get(ch)&&ch!='(');//before you call the func,you need to eat '(' ex:(5'('
            break;
        }
    }
        if(x==1)
        cout<<"no\n";
        else
        {
            func(num,0);
            while(cin.get(ch)&&ch!=')');//eat the final ')'  ex:(5()()')'
            if(check==1)
            cout<<"yes\n";
            else
            cout<<"no\n";
        }
    }

    return 0;
}
