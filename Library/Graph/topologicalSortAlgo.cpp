#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
	map<T, list<T>> l;
	public:
		void addEdge(T x, T y){
			l[x].push_back(y);
		}
		
		void DFS_helper(T src, map<T, bool> &visited, list<T> &ordering){
			visited[src]=true;
			
			for(T nbr:l[src]){
				if(!visited[nbr]){
					DFS_helper(nbr, visited, ordering);
				}
			}
			ordering.push_front(src);
			return ;
		}
		
		void DFS(){
			map<T, bool> visited;
			list<T> ordering;
			for(auto p:l){
				T node = p.first;
				visited[node] = false;
			}
			for(auto p:l){
				T node = p.first;
			
				if(!visited[node]){
					DFS_helper(node, visited, ordering); 
				}
			}	
			for(auto node:ordering){
				cout<<node<<endl;
			}
		}
};

int main()
{
	Graph<string> g;
	g.addEdge("Python" , "Data Process");
	g.addEdge("Python", "Pytorch");
	g.addEdge("Python", "ML");
	g.addEdge("Data Process", "ML");
	g.addEdge("Pytorch", "DL");
	g.addEdge("ML", "DL");
	
	g.addEdge("DL", "FaceRecogn");
	g.addEdge("dataset", "FaceRecogn");
	
	g.DFS();
	return 0;
}