#include<iostream>
#include<sstream>
#include<string>
#include<cstring>
#include<iomanip>
using namespace std;
int main()
{
    stringstream ss;
    double charge[5][4]={{0.02,0.1,0.06,0.02},{0.05,0.25,0.15,0.05},{0.13,0.53,0.33,0.13},{0.17,0.87,0.47,0.17},{0.3,1.44,0.8,0.3}};
    char ch;
    string temp,str;
    int s_hr,s_min,e_hr,e_min,time[1440];
    int interval[5]={0,480,1080,1320,1440};
    int sum[4];
    double total;
    while(getline(cin,temp))
    {
        if(temp=="#")
            break;
        ss<<temp;
        ss>>ch>>str>>s_hr>>s_min>>e_hr>>e_min;
        memset(time,0,sizeof(time));
        memset(sum,0,sizeof(sum));
        if(s_hr*60+s_min>=e_hr*60+e_min)
        {
            for(int i=0;i<e_hr*60+e_min;i++)
                time[i]=1;
            for(int i=s_hr*60+s_min;i<1440;i++)
                time[i]=1;
        }
        else
        {
            for(int i=s_hr*60+s_min;i<e_hr*60+e_min;i++)
                time[i]=1;
        }
        for(int i=0;i<4;i++)
            for(int j=interval[i];j<interval[i+1];j++)
                sum[i]+=time[j];
        sum[3]+=sum[0];
        total=charge[ch-65][1]*sum[1]+charge[ch-65][2]*sum[2]+charge[ch-65][3]*sum[3];
        cout<<setw(10)<<str<<setw(6)<<sum[1]<<setw(6)<<sum[2]<<setw(6)<<sum[3]<<setw(3)<<ch<<setw(8)<<fixed<<setprecision(2)<<total<<endl;
        ss.str("");
        ss.clear();
    }
}
