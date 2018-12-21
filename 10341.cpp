#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<fstream>
using namespace std;
int p,q,r,s,t,u;
double calc_func(double x)
{
    return p*exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * pow(x,2)+u;
}
void binary_search(double lower,double upper)
{
    double mid;
    if(calc_func(upper)==0)
    {
        cout<<fixed<<setprecision(4)<<upper<<endl;
        return;
    }
    else if(calc_func(lower)==0)
    {
        cout<<fixed<<setprecision(4)<<lower<<endl;
        return;
    }
    else if(calc_func(upper)*calc_func(lower)>0)
    {
        cout<<"No solution"<<endl;
        return;
    }
    while(upper-lower>=1e-9)
    {

        mid=(upper+lower)/2;
        if(calc_func(mid)==0)
        {
            cout<<fixed<<setprecision(4)<<mid<<endl;
            return;
        }

        if(calc_func(upper)*calc_func(mid)<0)
            lower=mid;
        else
            upper=mid;
    }
    cout<<fixed<<setprecision(4)<<mid<<endl;
}
int main()
{
    while(cin>>p>>q>>r>>s>>t>>u)
    {
        binary_search(0,1);
    }
}
