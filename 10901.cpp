#include<iostream>
#include<string>
#include<fstream>
using namespace std;
int main()
{
    ofstream fout;
    fout.open("1.txt");
    int test;
    cin>>test;
    while(test--)
    {
       int transform,time,car,flag=0,x,clock=0,car_left[2][10001]={{-1},{-1}},car_right[2][10001]={{-1},{-1}},count=0,left_num=0,right_num=0,m=-1,n=-1,store;
        string stop;
        cin>>transform>>time>>car;
        while(car--)
        {
            cin>>x>>stop;
            if(stop=="left")
            {
                car_left[0][left_num]=x;

                car_left[1][left_num]=count;
                left_num++;
            }
            else
           {
               car_right[0][right_num]=x;

               car_right[1][right_num]=count;
                right_num++;
           }
           count++;
        }
        while(1)
        {
            if(m==left_num-1&&n==right_num-1)
            break;
            store=transform;
            if(m==left_num-1)
            {

                 if(clock<car_right[0][n+1])
                clock=car_right[0][n+1];

                if(flag==0)
                    clock=clock+time;

                while(store--)
                {
                  if(n!=right_num-1&&car_right[0][n+1]<=clock)
                  {
                      car_right[0][n+1]=clock+time;


                      n++;
                      flag=0;
                  }
                  else
                  break;
                }
            }
            else if(n==right_num-1)
            {

                if(clock<car_left[0][m+1])
                    clock=car_left[0][m+1];
                if(flag==1)
                    clock=clock+time;
                while(store--)
                {
                  if(m!=left_num-1&&car_left[0][m+1]<=clock)
                  {
                      car_left[0][m+1]=clock+time;

                      m++;
                      flag=1;
                  }
                  else
                  break;
                }
            }
            else
            {
                if(flag==0&&car_left[0][m+1]<=clock)
                {
                    while(store--)
                    {
                      if(m!=left_num-1&&car_left[0][m+1]<=clock)
                      {
                          car_left[0][m+1]=clock+time;
                          m++;
                          flag=1;
                      }
                      else
                      break;
                    }
                }
                else if(flag==1&&car_right[0][n+1]<=clock)
                {
                    while(store--)
                    {
                      if(n!=right_num-1&&car_right[0][n+1]<=clock)
                      {
                          car_right[0][n+1]=clock+time;

                          n++;
                          flag=0;
                      }
                      else
                      break;
                    }
                }
                   else if(car_left[0][m+1]<car_right[0][n+1])
                {

                    if(clock<car_left[0][m+1])
                    clock=car_left[0][m+1];
                    if(flag==1)
                        clock=clock+time;
                    while(store--)
                    {
                      if(m!=left_num-1&&car_left[0][m+1]<=clock)
                      {
                          car_left[0][m+1]=clock+time;
                          m++;
                          flag=1;
                      }
                      else
                      break;
                    }
                }
                else if(car_left[0][m+1]==car_right[0][n+1])
                {

                    if(clock<car_left[0][m+1])
                    clock=car_left[0][m+1];
                    if(flag==0)
                    {
                        while(store--)
                        {
                          if(m!=left_num-1&&car_left[0][m+1]<=clock)
                          {
                              car_left[0][m+1]=clock+time;

                              m++;
                          }
                          else
                            break;
                        }
                        flag=1;
                    }
                    else
                    {

                         while(store--)
                        {
                          if(n!=right_num-1&&car_right[0][n+1]<=clock)
                          {
                              car_right[0][n+1]=clock+time;

                              n++;
                          }
                          else
                            break;
                        }
                        flag=0;
                    }
                }
                else if(car_left[0][m+1]>car_right[0][n+1])
                {
                     if(clock<car_right[0][n+1])
                    clock=car_right[0][n+1];
                    if(flag==0)
                        clock=clock+time;
                    while(store--)
                    {
                      if(n!=right_num-1&&car_right[0][n+1]<=clock)
                      {
                          car_right[0][n+1]=clock+time;

                          n++;
                          flag=0;
                      }
                      else
                      break;
                    }
                }
            }

            clock=clock+time;
        }
        m=0;
        n=0;
        for(int i=0;i<=count-1;i++)
        {

            if(car_left[1][m]==i)
            {
                cout<<car_left[0][m]<<endl;
                m++;
            }
            else if(car_right[1][n]==i)
            {
                cout<<car_right[0][n]<<endl;
                n++;
            }
        }
        if(test>0)
        cout<<endl;
    }
    return 0;
}
