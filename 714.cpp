#include<iostream>
#include<stack>
using namespace std;
int main()
{
    int k,m,page[500],test,i,j;
    long long upper,lower,mid,temp;
    cin>>test;
    while(test--)
    {
        cin>>m>>k;
        cin>>page[0];
        lower=page[0];
        upper=page[0];
        for(i=1;i<m;i++)
        {
            cin>>page[i];
            upper+=page[i];
        }

        while(upper>lower)
        {
            mid=(lower+upper)/2;
            j=0;
            for(i=0;i<k;i++)  //だΘk帮
            {
                temp=mid;
                while(temp>0)
                {
                    temp-=page[j];
                    if(temp>=0)
                    {
                        j++; //砆だセ计++
                        if(j==m)
                            break;
                    }
                }
                if(j==m)
                        break;
            }
            if(j<m)
                lower=mid+1;
            else
                upper=mid;
        }
        if(lower==upper)
            mid=lower;
        stack<int> s;
        j=m-1;  //j眖计ㄓ
        for(i=0;i<k;i++)  //Τk帮璶禲kΩ
        {
            temp=mid;
            while(temp>=0&&j>=(k-i-1))  //–常璶ぶ1セ┮程琌k-i-1
            {
                temp-=page[j];
                if(temp>=0)
                {
                    s.push(page[j]);
                    j--;
                }
            }
            if(i<k-1)
                s.push(-1);//だ筳
        }
        while(!s.empty())
        {
            if(s.top()>0)
                cout<<s.top();
            else
                cout<<"/";
            s.pop();
            if(!s.empty())
                cout<<" ";

        }
        cout<<endl;

    }

}
