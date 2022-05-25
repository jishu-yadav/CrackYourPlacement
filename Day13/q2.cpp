#include <iostream>
#include<map>
#include<list>
#include<queue>
#include<cstring>
using namespace std;
//QUESTION IS TELL IF THE GRAPH IS TREE OR NOT OR BASICALLY DETECT IF THE GRAPH HAS CYCLE
class Graph{
    list<int>*l;
    int V;
public:
    Graph(int v){
        this->V = v;
        l = new list<int>[V];
    }
    void addEdge(int x,int y){
        l[x].push_back(y); 
        l[y].push_back(x);
    }
    bool isTree(){
        bool *visited = new bool[V];
        int *parent = new int[V];
        queue<int>q;
        //initially lets mark all visited nodes as false and their parent as itself
        for(int i=0;i<V;i++){
            visited[i] = false;
            parent[i] = i;
        }
        int src = 0;
        q.push(src);
        visited[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int nbr:l[node]){
                if(visited[nbr]==true and parent[node] != nbr){//condition that it should not have parent as nbr
                    return false;//if it is already visited means cycle is present and the graph is not tree
                }
                else if(!visited[nbr]){
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);

                }
            }
        }
        return true;
    }
};
int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
   

    // Function Call
    if(g.isTree())
        cout<<"This graph is tree";
    else
        cout<<"This is not a tree";
    // cout<<"Hello World!";
}
//check if graph is a tree or not OR if it has cycle or not
