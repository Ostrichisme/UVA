#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    stringstream ss;
    string str,angle; //����
    double s,a,r;//�ìP��a�y�����Z���B�����B�b�|
    double arc,chord; //���Z�B���Z
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
        if(a>180)   //����>180���ܭn��360�h��
            a=360-a;
        arc=a*M_PI/180*r;
        chord=sqrt(2*r*r-2*r*r*cos(a*M_PI/180));
        cout<<fixed<<setprecision(6)<<arc<<" "<<chord<<endl;
    }
}
