#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    stringstream ss;
    string str,angle; //角度
    double s,a,r;//衛星到地球表面的距離、夾角、半徑
    double arc,chord; //弧距、弦距
    while(getline(cin,str))
    {
        if(str=="")
            break;
        ss.str("");
        ss.clear();
        ss<<str;
        ss>>s>>a>>angle;
        r=6440+s;
        if(angle=="min")
            a=a/60;
        if(a>180)   //角度>180的話要用360去扣
            a=360-a;
        arc=a*M_PI/180*r;
        chord=sqrt(2*r*r-2*r*r*cos(a*M_PI/180));
        cout<<fixed<<setprecision(6)<<arc<<" "<<chord<<endl;
    }
}
