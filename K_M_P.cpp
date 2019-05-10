#include<bits/stdc++.h>
using namespace std;

void pre_fun(string s)
{
    int lps[s.size()+5];
    int now=lps[0]=-1;
    for(int i=1;i<s.size();i++)
    {
        while(now!=-1&&lps[now+1]!=s[i])now=lps[now];
        if(s[now+1]==s[i])lps[i]=++now;
        else lps[i]=now=-1;
    }
}

int main()
{
    string s;cin>>s;
    pre_fun(s);
}
