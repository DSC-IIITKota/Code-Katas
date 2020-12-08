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
		
		bool cycle_helper_directed(int node, bool *visited, bool *stack){
			visited[node] = true;
			stack[node] = true;
			
			for(auto nbr:l[node]){
				if(stack[nbr] == true){
					return true;
				}
				
				if(visited[nbr] == false){
					bool if_cycle = cycle_helper_directed(nbr, visited, stack);
					if(if_cycle){
						return true;
					}
				}
			}
			stack[node] = false;
			return false;
		}
		
		bool contains_cycle_directed(){
			bool *visited = new bool[V];
			bool *stack = new bool[V];
			
			for(int i=0;i<V;i++){
				visited[i] = stack[i] = false;
			}
			
			return cycle_helper_directed(0, visited, stack);
		}
};

int main()
{
	Graph g(7);	 
	g.addEdge(0, 1);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 4);
	g.addEdge(4, 5);
	g.addEdge(1, 5);
	g.addEdge(5, 6);
	
	if(g.contains_cycle_directed()){
		cout<<"Yes contains a cycle"<<endl;
	}
	else{
		cout<<"Not contains a cycle"<<endl;
	}

	return 0;
}