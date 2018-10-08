#include<iostream>
using namespace std;
int main()
{
    double test,max,count,store,length,width;
    while(cin>>test&&test!=0)
    {
        count=1;
        store=1;
        max=0;
        while(test--)
        {
            cin>>length>>width;
            if(length<width)
            swap(length,width);
            if(width/2>max)
            {
                max=width/2;
                store=count;
            }
            if(length/4<=width)
            {
                if(length/4>max)
               {
                   max=length/4;
                    store=count;
               }
            }
            else if(4*width<=length)
            {
                if(width>max)
                  {
                      max=width;
                    store=count;
                  }
            }
            count++;
        }
           cout<<store<<endl;
    }
}
