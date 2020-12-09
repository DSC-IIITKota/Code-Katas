#include <bits/stdc++.h>
#define pb push_back
#define endll "\n";
using namespace std;
int t1,count1;
int disc[30001],low[30001],vis[30001],parent[30001],ans[30001];
void dfs(vector<int> adj[],int i,int n){
    disc[i]=low[i]=++t1;
    vis[i]=1;
    int child=0;
    for(int j=0;j<adj[i].size();j++){
        if(vis[adj[i][j]]==0){
            child++;
            int u=adj[i][j];
            parent[u]=i;
            dfs(adj,u,n);
            low[i]=min(low[i],low[adj[i][j]]);
            if(parent[i]==-1&&child>1){
                ans[i]=1;
            }
            else if(parent[i]!=-1&&disc[i]<=low[adj[i][j]]){
                ans[i]=1;
            }
        }
        else if(parent[i]!=adj[i][j]){
            low[i]=min(low[i],disc[adj[i][j]]);
        }
    }
    
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        vector<int> adj[n+1];
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        t1=0;
        count1=0;
        memset(disc,0,sizeof(disc));
        memset(low,0,sizeof(low));
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        memset(parent,-1,sizeof(parent));
        for(int i=1;i<=n;i++){
            if(vis[i]==0){
                dfs(adj,i,n);
            }
        }
        for(int i=1;i<=n;i++){
            if(ans[i])
            count1++;
        }
        cout<<count1<<endll;
        
    }
    return 0;
}