#include <iostream>
#include<map>
#include<list>
#include<climits>
using namespace std;
template<typename T>
class Graph{
    map<T,list<T>>l;
    public:
    void addEdge(T x,T y){
        l[x].push_back(y);
        // l[y].push_back(x);// cuz we have to make DIRECTED ACYCLIC GRAPH means not birectional :)
    }
    void dfs_helper(T src,map<T,bool>&visited,list<T>&ordering){
        // cout<<src<<" ";
        visited[src]=true;
        // to go to all nbr of that node which is not visited yet
        for(T nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited,ordering);
            }
        }
        ordering.push_front(src);
    }
    void dfs(){
        map<T,bool>visited;
        list<T> ordering;
        //mark all nodes as not visited in the beginning
        for(auto p:l){
            T node = p.first;
            visited[node]= false;
        }//call helper func now
        //iterate over al the vertices and init a dfs call
        for(auto p:l){
            T node = p.first;
            int cnt = 0;
            if(!visited[node]){
               // cout<<"Component "<<cnt<<" -->";
                dfs_helper(node,visited,ordering);
                cnt++;
                //cout<<endl;
            }
        }
        //finally we can either return the list or print it
        for(auto node:ordering){
            cout<<node<< endl;
        }
        

    }
};
int main() {
    Graph<string>g;
    g.addEdge("Python","DataProcessing");
    g.addEdge("Python","Pytorch");
    g.addEdge("Python","ML");
    g.addEdge("DataProcessing","ML");
    g.addEdge("Pytorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecog");
    g.addEdge("Dataset","FaceRecog");
    g.dfs();
    //cout<<"Hello World!";
}
// topological sorting dfs graphs
