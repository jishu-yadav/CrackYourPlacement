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
            l[x].push_back(y);//directed graph from x to y
        }
        int bfs(T src, T dest){
            map<T,int>dis;
            map<T,T>parent;
            queue<T>q;
            //all other nodes will have INT_MAX dis except src with 0 dis
            for(auto node_pair:l){
                T node = node_pair.first;
                dis[node]= INT_MAX;
            }
            dis[src]=0;
            parent[src]=src;
            q.push(src);
            while(!q.empty()){
                T node = q.front();
                
                q.pop();
                //cout<<node<<" ";
                for(auto nbr:l[node]){
                    if(dis[nbr]==INT_MAX){
                        q.push(nbr);
                        dis[nbr]=dis[node]+1;
                        parent[nbr] = node;
                      //  cout<<nbr<<" "<<dis[nbr]<<"\n ";
                    }
                }
            }
            //print the dist to destination node
            //dest to src
            T temp = dest;
            while(temp!=src){
                cout<<temp<<" <--";
                temp = parent[temp];
            }
            cout<<src<<endl;
            return dis[dest];
            // for(auto node_pair:l){
            //     T node = node_pair.first;
            //     int d = dis[node];
            //     //print dis to every node
            //     cout<<"Node "<<node<<" - Dis from src = "<< d<<endl;
            // }

        }

};
int main() {
    int board[50]={0};
    //snakes and ladders
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    Graph <int>g;
    //add edges to graph with 36 nodes in a snakes n ladders
    for(int i=0;i<36;i++){
        for(int dice=1;dice<=6;dice++){// playing dice having just 6 faces
            int j = i + dice ;
            j += board[j];//jump to take if laddder comes in
            if(j<=36){
                g.addEdge(i,j);
            }

        }
    }
    cout<<g.bfs(0,36);//src is 0 n destination is 36
    
}
//snakes n ladders sssp bfs problem (check once)
