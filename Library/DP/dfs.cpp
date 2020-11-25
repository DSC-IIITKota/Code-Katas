#include<iostream>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph{

private:
    map<int,list<int> > l;

public:

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(int src,map<int,bool> &visited){

        cout<<src<<" ";
        visited[src] = true;

        for(auto x: l[src]){
            if(!visited[x]){    
                dfs_helper(x,visited);
            }
        }

    }

    void dfs(int src){

        map<int,bool> visited;
        for(auto x: l){
            visited[x.first] = false;
        }

        dfs_helper(src,visited);

    }

};

int main(){

    Graph g;

    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    g.dfs(0);
  

}