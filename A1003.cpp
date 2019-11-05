#include<bits/stdc++.h>
using namespace std;
const int N = 500+5;
int aid[N];
bool flag[N];
int mind[N];
int path[N];
int cnt[N];
int num[N];
typedef pair<int,int> pii;
vector<pii> graph[N];
vector<int> U,V,W;
priority_queue<pii,vector<pii>,greater<pii> > pq;
void getAnswer(int n, int m,int s,int t){
    memset(mind,127,sizeof(mind));
    memset(flag,0,sizeof(flag));
    memset(path,-1,sizeof(path));
    while(!pq.empty())
            pq.pop();
    for(int i =0 ; i<=n; ++i)
            graph[i].clear();
    for(int i=0; i<m; ++i){
        graph[U[i]].push_back(make_pair(V[i],W[i]));
        graph[V[i]].push_back(make_pair(U[i],W[i]));
    }
    mind[s] = 0;
    num[s] = 1;
    cnt[s] = aid[s];
    pq.push(make_pair(mind[s],s));
    while(!flag[t]){
        int u = pq.top().second;
        pq.pop();
        if(!flag[u]){
            flag[u] = true;
            for(auto it = graph[u].begin(); it != graph[u].end(); ++it){
                int v = it->first;
                int w = it->second;
               if(mind[u] +  w  < mind[v]){
                    num[v] = num[u];
                    mind[v] = mind[u] + w;
                    cnt[v] = cnt[u] + aid[v];
                    path[v] = u;
                    pq.push(make_pair(mind[v],v));
               }else if ( mind[u] + w == mind[v]){
                   if(cnt[v]  < cnt[u] + aid[v]){
                        cnt[v] = cnt[u] + aid[v];
                        path[v] = u;
                   }
                   num[v] += num[u];
               }
            }
        }
    }

}
void dfs(int s,int v){
    if(v == s)
        printf("%d",s);
    else{
        dfs(s,path[v]);
        printf(" %d",v);
    }
}
int main()
{
    int n,m,s,t;
    cin>>n>>m>>s>>t;
    for(int i=0; i<n; ++i)
        cin>>aid[i];
    for(int i=0;i<m;++i){
        int u,v,w;
        cin>>u>>v>>w;
        U.push_back(u);
        V.push_back(v);
        W.push_back(w);
    }
    getAnswer(n,m,s,t);
    printf("%d %d\n",num[t],cnt[t]);


    return 0;



}
