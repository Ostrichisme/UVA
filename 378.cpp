#include<iostream>
#include<iomanip>
using namespace std;
double x1,y1,x2,y2,x3,y3,x4,y4,ansx,ansy,xa,ya,xb,yb,ma,mb,ba,bb;
void calc_m()
{
    if(y1==y2)
        {
            ya=y1;
            ma=0;
        }
        else if(x1==x2)
        {
            xa=x1;
            ma=2;
        }
        else
        {
            ma=(y2-y1)/(x2-x1);
        }
        if(y3==y4)
        {
            yb=y3;
            mb=0;
        }
        else if(x3==x4)
        {
            xb=x3;
            mb=2;
        }
        else
        {
            mb=(y4-y3)/(x4-x3);
        }
}
void calc_ans()
{
    if(ma==mb)
        {
            if(ma==2)
            {
                if(xa==xb)
                    cout<<"LINE\n";
                else
                    cout<<"NONE\n";
            }
            else if(ma==0)
            {
                if(ya==yb)
                    cout<<"LINE\n";
                else
                    cout<<"NONE\n";
            }
            else
            {
                ba=y1-x1*ma;
                if(x3*ma+ba==y3)
                    cout<<"LINE\n";
                else
                    cout<<"NONE\n";
            }
        }
        else
        {
            if(ma==2)
            {
                ansx=xa;
                bb=y3-mb*x3;
                ansy=mb*ansx+bb;
                cout<<"POINT "<<fixed<<setprecision(2)<<ansx<<" "<<ansy<<endl;
            }
            else if(mb==2)
            {
                ansx=xb;
                ba=y1-x1*ma;
                ansy=ma*ansx+ba;
                cout<<"POINT "<<fixed<<setprecision(2)<<ansx<<" "<<ansy<<endl;
            }
            else
            {
                ba=y1-ma*x1;
                bb=y3-mb*x3;
                ansx=(bb-ba)/(ma-mb);
                ansy=ma*ansx+ba;
                cout<<"POINT "<<fixed<<setprecision(2)<<ansx<<" "<<ansy<<endl;
            }
        }
}

int main()
{
    int test;
    cin>>test;
    cout<<"INTERSECTING LINES OUTPUT\n";
    while(test--)
    {
        cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
        calc_m();
        calc_ans();

    }
    cout<<"END OF OUTPUT\n";
}
