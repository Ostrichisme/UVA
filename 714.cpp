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
            for(i=0;i<k;i++)  //分成k堆
            {
                temp=mid;
                while(temp>0)
                {
                    temp-=page[j];
                    if(temp>=0)
                    {
                        j++; //被分到的書本數++
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
        j=m-1;  //j從後面數回來
        for(i=0;i<k;i++)  //有k堆要跑k次
        {
            temp=mid;
            while(temp>=0&&j>=(k-i-1))  //每人都要至少1本，所以最多是k-i-1
            {
                temp-=page[j];
                if(temp>=0)
                {
                    s.push(page[j]);
                    j--;
                }
            }
            if(i<k-1)
                s.push(-1);//分隔
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
