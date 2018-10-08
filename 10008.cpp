#include<iostream>
#include<cctype>
#include<string>
using namespace std;
int main()
{
    string s;
    int time[26]={0},test;
    char alpha[26];
    for(int i=0;i<26;i++)
    {
        alpha[i]=65+i;
    }
    cin>>test;
    cin.get();
    while(test--)
    {
        getline(cin,s);
        for(int i=0;i<s.length();i++)
        {
            s[i]=toupper(s[i]);
            if(isalpha(s[i]))
                time[s[i]-65]++;
        }
    }
    for(int i=0;i<25;i++)
        for(int j=0;j<25-i;j++)
        {
            if(time[j]<time[j+1])
            {
                swap(time[j],time[j+1]);
                swap(alpha[j],alpha[j+1]);
            }
        }
    for(int i=0;i<26;i++)
    {
        if(time[i]==0)
            break;
        else
            cout<<alpha[i]<<" "<<time[i]<<endl;
    }
}

