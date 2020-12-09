#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	vector<pair<int, int> > *l;
	
	public:
		
		Graph(int n){
			V = n;
			l = new vector<pair<int, int>>[n];
		}
		
		void addEdge(int x, int y, int w){
			l[x].push_back({y, w});
			l[y].push_back({x, w});
		}
		
		
		int prism_mst(){
			
			priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int >>> q;
			bool *vis = new bool[V]{0};
			int ans = 0;
			
			q.push({0,0});
			while(!q.empty()){
				auto node = q.top();
				q.pop();
				
				int to = node.second;
				int weight = node.first;
				
				if(vis[to]){
					continue;
				}
				ans+=weight;
				vis[to] = 1;
				
				for(auto x:l[to]){
					if(vis[x.first] == 0){
						q.push({x.second, x.first});
					}
				}
			}
			return ans;
		}
	
};

int main()
{
	int n,m;	cin>>n>>m;
	
	Graph g(n);
	for(int i=0;i<n;i++){
		int x,y,w;	cin>>x>>y>>w;
		g.addEdge(x-1, y-1, w);
	}
	
	cout<<g.prism_mst()<<endl;
	return 0;
}




