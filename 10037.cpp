#include<iostream>
#include<sstream>
#include<algorithm>
#include<fstream>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int num;
        int people[1001];
        cin>>num;
        for(int i=0;i<num;i++)
            cin>>people[i];
        sort(people,people+num);
        reverse(people,people+num);
        if(num==1)
            cout<<people[0]<<endl<<people[0]<<endl;
        else if(num==2)
            cout<<people[0]<<endl<<people[1]<<" "<<people[0]<<endl;
        else if(num==3)
        {
            cout<<people[0]+people[1]+people[2]<<endl;
            cout<<people[2]<<" "<<people[1]<<endl;
            cout<<people[2]<<endl;
            cout<<people[2]<<" "<<people[0]<<endl;
        }
        else
        {
            stringstream ss;
            int a=people[num-1],b=people[num-2],i=0,time=0;
            while(num-i>=4)
            {
                int d=people[i],c=people[i+1];
                if(b+a+d+b<c+a+d+a)
                {
                    ss<<a<<" "<<b<<endl;
                    ss<<a<<endl;
                    ss<<c<<" "<<d<<endl;
                    ss<<b<<endl;
                    time+=b+a+d+b;;
                }
                else
                {
                    ss<<a<<" "<<c<<endl;
                    ss<<a<<endl;
                    ss<<a<<" "<<d<<endl;
                    ss<<a<<endl;
                    time+=c+a+d+a;
                }
                i+=2;
            }
            if(num-i==3)
            {
                time+=a+b+people[num-3];
                cout<<time<<endl;
                cout<<ss.str();
                cout<<a<<" "<<b<<endl;
                cout<<a<<endl;
                cout<<a<<" "<<people[num-3]<<endl;
            }
            else if(num-i==2)
            {
                time+=b;
                cout<<time<<endl;
                cout<<ss.str();
                cout<<a<<" "<<b<<endl;
            }
        }
        if(test>0)
            cout<<endl;
    }
}
