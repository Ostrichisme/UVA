#include<iostream>
#include<iomanip>
#include<cmath>
#include<fstream>
using namespace std;
int main()
{
    double ax,ay,bx,by,cx,cy,m1,m2,temp1_x,temp1_y,temp2_x,temp2_y,circle_x,circle_y,r,cons1,cons2;
    while(cin>>ax>>ay>>bx>>by>>cx>>cy)
    {
        if(ax!=bx&&ay!=by&&bx!=cx&&by!=cy)
        {
            m1=-1*(bx-ax)/(by-ay);
            temp1_x=(ax+bx)/2;
            temp1_y=(ay+by)/2;
            cons1=-1*m1*temp1_x+temp1_y;

            m2=-1*(cx-bx)/(cy-by);
            temp2_x=(bx+cx)/2;
            temp2_y=(by+cy)/2;
            cons2=-1*m2*temp2_x+temp2_y;

            circle_x=(cons2-cons1)/(m1-m2);
            circle_y=m1*circle_x+cons1;
        }
        else if(ax==bx&&ay!=by&&bx!=cx&&by==cy)
        {
            circle_y=(ay+by)/2;
            circle_x=(bx+cx)/2;
        }
        else if(ax!=bx&&ay==by&&bx==cx&&by!=cy)
        {
            circle_x=(ax+bx)/2;
            circle_y=(by+cy)/2;
        }
        else if(ax==bx&&ay!=by&&bx!=cx&&by!=cy)
        {
            circle_y=(ay+by)/2;

            m2=-1*(cx-bx)/(cy-by);
            temp2_x=(bx+cx)/2;
            temp2_y=(by+cy)/2;
            cons2=-1*m2*temp2_x+temp2_y;

            circle_x=(circle_y-cons2)/m2;
        }
        else if(ax!=bx&&ay==by&&bx!=cx&&by!=cy)
        {
            circle_x=(ax+bx)/2;

            m2=-1*(cx-bx)/(cy-by);
            temp2_x=(bx+cx)/2;
            temp2_y=(by+cy)/2;
            cons2=-1*m2*temp2_x+temp2_y;

            circle_y=m2*circle_x+cons2;
        }
        else if(ax!=bx&&ay!=by&&bx==cx&&by!=cy)
        {
            circle_y=(by+cy)/2;

            m1=-1*(bx-ax)/(by-ay);
            temp1_x=(ax+bx)/2;
            temp1_y=(ay+by)/2;
            cons1=-1*m1*temp1_x+temp1_y;

            circle_x=(circle_y-cons1)/m1;
        }
        else if(ax!=bx&&ay!=by&&bx!=cx&&by==cy)
        {
            circle_x=(bx+cx)/2;

            m1=-1*(bx-ax)/(by-ay);
            temp1_x=(ax+bx)/2;
            temp1_y=(ay+by)/2;
            cons1=-1*m1*temp1_x+temp1_y;

            circle_y=m1*circle_x+cons1;
        }


        r=sqrt((circle_x-ax)*(circle_x-ax)+(circle_y-ay)*(circle_y-ay));
        char signx,signy;

        if(circle_x>=0)
            signx='-';
        else if(circle_x<0)
        {
            circle_x=fabs(circle_x);
            signx='+';
        }

        if(circle_y>=0)
            signy='-';
        else if(circle_y<0)
        {
            circle_y=fabs(circle_y);
            signy='+';
        }

        cout<<fixed<<setprecision(3)<<"(x "<<signx<<" "<<circle_x<<")^2 + (y "<<signy<<" "<<circle_y<<")^2 = "<<r<<"^2"<<endl;
        cout<<fixed<<setprecision(3)<<"x^2 + y^2 "<<signx<<" "<<2*circle_x<<"x "<<signy<<" "<<2*circle_y<<"y ";
        double n=(circle_x*circle_x+circle_y*circle_y-r*r);
        if(n>=0)
            cout<<fixed<<setprecision(3)<<"+ "<<n<<" = 0"<<endl;
        else if(n<0)
        {
            cout<<fixed<<setprecision(3)<<"- "<<-n<<" = 0"<<endl;
        }


        cout<<endl;

    }
}
