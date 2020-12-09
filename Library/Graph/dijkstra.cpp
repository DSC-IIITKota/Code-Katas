#include<bits/stdc++.h>
using namespace std;

template<typename T>

class Graph{
	
	unordered_map<T, list<pair<T, int> > > m;
	
	public:
		void addEdge(T u, T v, int dist, bool bidr=true){
			m[u].push_back(make_pair(v, dist));
			if(bidr){
				m[v].push_back(make_pair(u, dist));
			}
		}
		void printAdj(){
			
			for(auto j:m){
				cout<<j.first<<"-->";
				for(auto l:j.second){
					cout<<"("<<l.first<<","<<l.second<<") ";
				}
				cout<<endl;
			}
			
		}
		void dijkstraSSSP(T src){
			unordered_map<T, int> dist;
			for(auto j:m){
			    dist[j.first] = INT_MAX;
			}
			
			set<pair<int, T>> s;
			dist[src] = 0;
			s.insert(make_pair(0, src));
			
			while(!s.empty()){
			    auto p = *(s.begin());
			    T node = p.second;
			    int nodeDist = p.first;
			    s.erase(s.begin());
			    
			    for(auto childPair : m[node]){
			        if(nodeDist + childPair.second < dist[childPair.first]){
			            T dest = childPair.first;
			            auto f = s.find(make_pair(dist[dest], dest));
			            if(f!=s.end()){
			                s.erase(f);
			            }
			            
			            dist[dest] = nodeDist + childPair.second;
			            s.insert(make_pair(dist[dest], dest));
			        }
			    }
			}
			for(auto d : dist){
			    cout<<d.first<<" is located at a distance of "<<d.second<<endl;
			}
			
		}
};

int main()
{

	Graph<string> india;
	india.addEdge("amritsar", "delhi", 1);
	india.addEdge("amritsar", "jaipur", 4);
	india.addEdge("jaipur", "delhi", 2);
	india.addEdge("jaipur", "mumbai", 8);
	india.addEdge("bhopal", "agra", 2);
	india.addEdge("mumbai", "bhopal", 3);
	india.addEdge("agra", "delhi", 1);
	india.dijkstraSSSP("amritsar");

	return 0;
}