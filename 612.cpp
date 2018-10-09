#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
typedef struct DNA
{
    string str;
    int order;
}dna;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int length,number;
        vector<dna> v;
        string s;
        cin>>length>>number;
        cin.get();
        for(int i=0;i<number;i++)
        {
            int order_num=0;
            dna temp;
            cin>>s;
            temp.str=s;
            for(int j=0;j<=length-2;j++)
                for(int k=j+1;k<=length-1;k++)
                    if(s[j]>s[k])
                        order_num++;
            temp.order=order_num;
            v.push_back(temp);

        }

        for(int i=0;i<=number-2;i++)
            for(int j=0;j<=number-2-i;j++)
            {
                if(v[j].order>v[j+1].order)
                {
                    swap(v[j].order,v[j+1].order);
                    swap(v[j].str,v[j+1].str);
                }
            }
        for(int i=0;i<number;i++)
            cout<<v[i].str<<endl;
        if(test>0)
            cout<<endl;
    }
}
