#include<iostream>
#include<cmath>
using namespace std;
char figure[10];
double rec[10][4],cir[10][3],tri[10][6];
double count(int n,int i,double j,double k)
{
    double x1,x2,y1,y2;
    if(i!=4)
   {
        x1=tri[n][i]-j;
        y1=tri[n][i+1]-k;
        x2=tri[n][i+2]-j;
        y2=tri[n][i+3]-k;
   }
    else
    {
        x1=tri[n][i-4]-j;
        y1=tri[n][i-3]-k;
        x2=tri[n][i]-j;
        y2=tri[n][i+1]-k;
    }
    return abs(x1*y2-x2*y1)*0.5;
}
int main()
{
    int m=0,i=1,p;
    double x,y;
    while(cin>>figure[m]&&figure[m]!='*')
    {
        if(figure[m]=='r')
        cin>>rec[m][0]>>rec[m][1]>>rec[m][2]>>rec[m][3];
        else if(figure[m]=='c')
        cin>>cir[m][0]>>cir[m][1]>>cir[m][2];
        else if(figure[m]=='t')
        cin>>tri[m][0]>>tri[m][1]>>tri[m][2]>>tri[m][3]>>tri[m][4]>>tri[m][5];
        m++;
    }
    while(cin>>x>>y&&x!=9999.9&&y!=9999.9)
    {
        p=0;
        for(int n=0;n<=m-1;n++)
        {
            if(figure[n]=='r')
            {
                if(x>rec[n][0]&&x<rec[n][2]&&y<rec[n][1]&&y>rec[n][3])
                {
                    cout<<"Point "<<i<<" is contained in figure "<<n+1<<endl;
                    p=1;
                }
            }
            else if(figure[n]=='c')
            {
                if(pow((pow((x-cir[n][0]),2)+pow((y-cir[n][1]),2)),0.5)<cir[n][2])
                {
                    cout<<"Point "<<i<<" is contained in figure "<<n+1<<endl;
                    p=1;
                }
            }
            else if(figure[n]=='t')
            {
                double ans,a,b,c;
                ans=count(n,2,tri[n][0],tri[n][1]);
                a=count(n,0,x,y);
                b=count(n,2,x,y);
                c=count(n,4,x,y);
                if(abs(a+b+c-ans)<=pow(10,-6)&&a!=0&&b!=0&&c!=0)
                {
                    cout<<"Point "<<i<<" is contained in figure "<<n+1<<endl;
                    p=1;
                }
            }
        }
        if(p==0)
        cout<<"Point "<<i<<" is not contained in any figure\n";
        i++;
    }
    return 0;
}
