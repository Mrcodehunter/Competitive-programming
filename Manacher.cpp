#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define _IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const ll N=1e6+9,mod=1e9+7,inf=1e18;
int d1[N],d2[N];

void Manacher(string s)
{
    int n=s.size();
    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int cl=(i>r)?1:min(d1[l+r-i],r-i+1);
        while(i-cl>=0&&i+cl<n&&s[i-cl]==s[i+cl])cl++;
        d1[i]=cl--;
        if(i+cl>r)
        {
            r=i+cl;
            l=i-cl;
        }
    }

    for(int i=0,l=0,r=-1;i<n;i++)
    {
        int cl=(i>r)?0:min(r-i+1,d2[l+r-i+1]);
        while(i-cl-1>=0&&i+cl<n&&s[i-cl-1]==s[i+cl])cl++;
        d2[i]=cl--;
        if(i+cl>r)
        {
            r=i+cl;
            l=i-cl-1;
        }
    }

}

void print(int n)
{
    for(int i=0;i<n;i++)cout<<d1[i]<<" ";
    cout<<"\n";
    for(int i=0;i<n;i++)cout<<d2[i]<<" ";
    cout<<"\n";
}

int main()
{
    _IO;
    string s;
    cin>>s;
    Manacher(s);
    print(s.size());
}
