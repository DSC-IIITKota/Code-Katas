#include<bits/stdc++.h>
using namespace std;

class Graph{
	int V;
	list<int> *l;
	public:
		Graph(int V){
			this->V = V;
			l = new list<int>[V];
		}
		void addEdge(int x, int y, bool directed = false){
			l[x].push_back(y);
			if(!directed){
				l[y].push_back(x);
			}
		}
		
		bool cycle_helper_undirected(int node, bool *visited, int parent){
			visited[node] = true;
			
			for(auto nbr:l[node]){
				if(!visited[nbr]){
					bool if_cycle = cycle_helper_undirected(nbr, visited, node);
					if(if_cycle){
						return true;
					}
				}
				
				else if(nbr != parent){
					return true;
				}
			}
			return false;
		}
		
		bool contains_cycle_undirected(){
			bool *visited = new bool[V];
			
			for(int i=0;i<V;i++){
				visited[i] = false;
			}
			
			return cycle_helper_undirected(0, visited, -1);
		}
};

int main()
{
	Graph g(5);
	g.addEdge(0,1);
	g.addEdge(1,2);
	g.addEdge(2,3);
	g.addEdge(3,4);
	g.addEdge(4,0);
	
	if(g.contains_cycle_undirected()){
		cout<<"Yes contains a cycle"<<endl;
	}
	else{
		cout<<"Not contains a cycle"<<endl;
	}
	
	return 0;
}