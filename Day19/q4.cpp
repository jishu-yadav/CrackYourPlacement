#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
//DSU data structure
//Used here Path compression + Union By rank optimizations of DSU
using namespace std;
class DSU{
    int *parent;//parent of each set
    int *rank;//rank of each node
public:
    DSU(int n){//n vertices
        parent = new int[n];
        rank = new int[n];
        //initially : parent = -1 ,  rank = 1; 
        for(int i=0;i<n;i++){
            rank[i] = 1;
            parent[i] = -1;
        }
    }
    //find function
    int find(int i){
        if(parent[i]==-1){
            return i;
        }else{
            return parent[i] = find(parent[i]);
        }
    }
    //Unite (Union)
    void unite(int x,int y){
        int s1 = find(x);
        int s2 = find(y);
        if(s1!=s2){
            //union by rank
            if(rank[s1]<rank[s2]){
                parent[s1] = s2;
                rank[s2]+=rank[s1];
            }
            else{
                parent[s2] = s1;
                rank[s1]+=rank[s2];
            }
        }
    }
};
//here also i am using edge list representation not adjacency list // bcoz i need to sort all edges
class Graph{
    vector< vector<int> > edgelist;//it could have been vector<edge>edgelsit but as edge list comprises of 3 things : x,y,wt so we made it in a vector;
    int V;
    public:
    Graph(int v){
        this->V = v;
    }
    void addEdge(int x,int y,int w){
        edgelist.push_back({w,x,y});//weight is pushed first so that while sorting it igets easily sorted based upon wts
    }
    int kruskal_mst(){
        //Main logic and it is easy imo :))
        //1.sort all edges based upon wt.
        sort(edgelist.begin(),edgelist.end());
        //init a DSU
        DSU s(V);
        int ans = 0;
        for(auto edge:edgelist){
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            //take that edge in MST if it does not form a cycle
            if(s.find(x)!=s.find(y)){
                s.unite(x,y);
                ans+=w;
            }
        }
        return ans;
    }
};
int main() {
    Graph g(4);
    g.addEdge(0,1,1);
    g.addEdge(1,3,3);
    g.addEdge(3,2,4);
    g.addEdge(2,0,2);
    g.addEdge(0,3,2);
    g.addEdge(1,2,2);

    cout<< g.kruskal_mst();

    return 0;
}
//kruskals algo
