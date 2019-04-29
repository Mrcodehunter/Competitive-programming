#include<bits/stdc++.h>
using namespace std;
struct _EDGE
{

    int u,v;
    long long cap,fl;
    _EDGE(int uu,int vv,long long capp,long long fll)
    {
        u=uu,v=vv,cap=capp,fl=fll;
    }


};

struct FLOW
{
    const long long inf= 0x3f3f3f3f3f3f3f3f;
    vector< vector < int > >adj;
    vector<_EDGE>edges;
    vector<int>lvl,frm;
    queue<int>q;
    int st,ed,nd=0,n;
    FLOW(int s,int e,int nn)
    {
        st=s,ed=e,n=nn;
        lvl.resize(n);
        frm.resize(n);
        adj.resize(n);
    }

    void    addedge(int u,int v,int cap)
    {
        edges.push_back(_EDGE(u,v,cap,0));
        edges.push_back(_EDGE(v,u,0,0));
        adj[u].push_back(nd);
        adj[v].push_back(nd^1);
        nd+=2;
    }

    bool bfs()
    {
        fill(lvl.begin(),lvl.end(),-1);
        q.push(st);
        lvl[st]=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto x: adj[u])
            {
                if(edges[x].cap-edges[x].fl>0&&lvl[edges[x].v]==-1)
                {
                    lvl[edges[x].v]=lvl[u]+1;
                    q.push(edges[x].v);
                }
            }
        }
        return lvl[ed]!=-1;
    }

    long long dfs(int u,long long fl)
    {
        if(!fl||u==ed)
            return fl;
        for(; frm[u]<adj[u].size(); frm[u]++)
        {
            int x=adj[u][frm[u]];
            if(lvl[u]+1==lvl[edges[x].v])
            {
                long long p=dfs(edges[x].v,min(fl,edges[x].cap-edges[x].fl));
                if(p)
                {
                    edges[x].fl+=p;
                    edges[x^1].fl-=p;
                    return p;
                }
            }
        }

        return 0;
    }


    long long dinic()
    {
        long long flow=0;
        while(bfs())
        {
            fill(frm.begin(),frm.end(),0);
            while(long long x=dfs(st,inf))
                flow+=x;
        }
        return flow;
    }

    void mem()
    {
        for(int i=0; i<nd; i++)
            edges[i].fl=0;
    }
    void show()
    {
        for(int i=0; i<nd; i++)
            cout<<edges[i].u<<" "<<edges[i].v<<" "<<edges[i].cap<<" "<<edges[i].fl<<"\n";
    }



};
int main()
{

}
