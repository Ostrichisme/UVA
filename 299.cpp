#include<iostream>
using namespace std;
int main()
{
    int test,length,train[50],count;
    cin>>test;
    while(test--)
    {
        cin>>length;
        count=0;
        for(int i=0;i<length;i++)
        {
            cin>>train[i];
        }
        for(int i=0;i<=length-2;i++)
            for(int j=0;j<=length-2-i;j++)
            {
                if(train[j]>train[j+1])
                {
                    swap(train[j],train[j+1]);
                    count++;
                }
            }
        cout<<"Optimal train swapping takes "<<count<<" swaps.\n";
    }
}
