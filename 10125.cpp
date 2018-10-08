#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<fstream>
using namespace std;
int main()
{
    int n;
    ofstream fout;
    fout.open("1.txt");
    while(cin>>n&&n!=0)
    {
        vector<int> num(n);
        for(int i=0;i<n;i++)
            cin>>num[i];
        sort(num.begin(),num.end());
        map<int,vector<pair<int,int> > > x;
        int flag=0;
        for(int i=0;i<=n-2;i++)
            for(int j=i+1;j<=n-1;j++)
                x[num[i]+num[j]].push_back(pair<int,int>(num[i],num[j]));
        for(int i=n-1;i>=1;i--)
        {
            for(int j=0;j<=i-1;j++)
            {
                for(int k=0;k<x[num[i]-num[j]].size();k++)
                {
                    if(num[j]!=x[num[i]-num[j]][k].first&&num[j]!=x[num[i]-num[j]][k].second&&num[i]!=x[num[i]-num[j]][k].first&&num[i]!=x[num[i]-num[j]][k].second)
                    {
                        flag=1;
                        cout<<num[i]<<endl;
                        break;
                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag==0)
            cout<<"no solution"<<endl;
    }
}
