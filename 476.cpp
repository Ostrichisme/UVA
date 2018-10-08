#include<iostream>
using namespace std;
double upper_left[10][2],lower_right[10][2],point[100000][2];
int flag=0,count_rect=0,count_point=0;

void rect_cin()
{
    char ch;
    cin>>ch;
    if(ch=='*')
        flag=1;
    else
    {
        cin>>upper_left[count_rect][0]>>upper_left[count_rect][1]>>lower_right[count_rect][0]>>lower_right[count_rect][1];
        count_rect++;
    }


}
void point_cin()
{
    double x,y;
    cin>>x>>y;
    if(x==9999.9&&y==9999.9)
        flag=1;
    else
    {
        point[count_point][0]=x;
        point[count_point][1]=y;
        count_point++;

    }

}
void calc()
{
    for(int i=0;i<count_point;i++)
    {
        flag=0;
        for(int j=0;j<count_rect;j++)
        {
            if(point[i][0]>upper_left[j][0]&&point[i][0]<lower_right[j][0]&&point[i][1]>lower_right[j][1]&&point[i][1]<upper_left[j][1])
            {
                cout<<"Point "<<i+1<<" is contained in figure "<<j+1<<endl;
                flag=1;
            }

        }
        if(flag==0)
            cout<<"Point "<<i+1<<" is not contained in any figure"<<endl;
    }

}
int main()
{

    while(!flag)
    {
        rect_cin();
    }
    flag=0;
    while(!flag)
    {
        point_cin();
    }
    calc();
    return 0;

}
