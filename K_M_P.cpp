#include<bits/stdc++.h>
using namespace std;

struct KMP{

    string tx,pt;
    vector<int>lps;

    KMP(string t,string p)
    {
        pt=p;
        tx=t;
        lps.resize(p.size());
    }

    void pre_fun()
     {
        int now=lps[0]=-1;
        for(int i=1;i<pt.size();i++)
         {
           while(now!=-1&&lps[now+1]!=pt[i])now=lps[now];
           if(pt[now+1]==pt[i])lps[i]=++now;
           else lps[i]=now=-1;
         }
     }

   bool matching()
   {
       int now=-1;

       for(int i=0;i<tx.size();i++)
       {
           while(now!=-1&&pt[now+1]!=tx[i])now=lps[now];
           if(pt[now+1]==tx[i])++now;
           else now=-1;
           if(now==pt.size()-1)return true;

       }
       return false;

   }


};


int main()
{
    string tx,pt;cin>>tx>>pt;
    KMP st(tx,pt);
    st.pre_fun();
    cout<<st.matching()<<"\n";
}
