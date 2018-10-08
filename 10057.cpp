#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int count;
    while(cin>>count)
    {
        vector<int> v;
        for(int i=0;i<count;i++)
        {
            int num;
            cin>>num;
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        int A_numbers=0;
        for(vector<int>::iterator it=v.begin();it!=v.end();it++)
        {
            if(count%2==1)
            {
                if(*it==v[count/2])
                     A_numbers++;
            }
            else
            {
                if(*it==v[count/2-1]||*it==v[count/2])
                    A_numbers++;
            }
        }
        if(count%2==1)
            cout<<v[count/2]<<" "<<A_numbers<<" 1"<<endl;
        else
            cout<<v[count/2-1]<<" "<<A_numbers<<" "<<v[count/2]-v[count/2-1]+1<<endl;

    }
}
