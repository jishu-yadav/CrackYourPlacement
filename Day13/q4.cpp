#include <iostream>
#include<map>
#include<queue>
#include<list>
#include<cstring>
using namespace std;
class Graph{
    list<int>*l;
    int V;
    public:
    Graph(int v){
        this->V=v;
        l = new list<int>[V];
    }
    void addEdge(int x,int y,bool directed=true){
        l[x].push_back(y);
        if(!directed){
            l[y].push_back(x);
        }
    }
    bool cycle_helper(int node, bool*visited,int parent){
        visited[node] = true;
        for(auto nbr:l[node]){
            //two cases
            if(!visited[nbr]){
                //go n recursively visit the neighbour
                bool cycle_mila = cycle_helper(nbr,visited,node);
                if(cycle_mila)
                    return true;
            }
            else if(nbr!=parent){
                return true;
            }
        }
        return false;
    }
    bool contains_cycle(){
        //check for cycle in directed graph
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        return cycle_helper(0,visited,-1);
    }
};
int main() {
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,0);//  Back Edge
   
    if(g.contains_cycle()==true)
        cout<< "in this undirected graph, cycle has been found!";
    else
        cout<<"Cycle not found!";
    
}
//detect cycle in undirected graph using dfs
