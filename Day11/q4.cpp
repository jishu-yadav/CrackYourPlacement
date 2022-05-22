#include <iostream>
#include<map>
#include<queue>
#include<list>
#include<climits>
using namespace std;
template<typename T>
class Graph{
    map<T, list<int>>l;
    public:
        void addEdge(int x,int y){
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void bfs(T src){
            map<T,int>dis;
           
            queue<T>q;
           
            //all other nodes will have INT_MAX dis except src with 0 dis
            for(auto node_pair:l){
                T node = node_pair.first;
                dis[node]= INT_MAX;
            }
            q.push(src);
            dis[src]=0;
            while(!q.empty()){
                T node = q.front();
                q.pop();
                //cout<<node<<" ";
                for(int nbr:l[node]){
                    if(dis[nbr]==INT_MAX){
                        q.push(nbr);
                        dis[nbr]=dis[node]+1;
                    }
                }
            }
            for(auto node_pair:l){
                T node = node_pair.first;
                int d = dis[node];
                //print dis to every node
                cout<<"Node "<<node<<" Dis from src "<< d<<endl;
            }
        }

};
int main() {
    Graph<int>g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.bfs(0);
    cout<<"Hello World!";
}
// check once but its logic is for shortest path using bfs in graphs. 
