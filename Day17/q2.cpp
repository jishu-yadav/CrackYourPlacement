#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph{
    unordered_map< T, list<pair<T,int>>>m;
    public:
    void addEdge(T u, T v,int dis, bool bidir = true){
        m[u].push_back(make_pair(v,dis));
        if(bidir){
            m[v].push_back(make_pair(u,dis));
        }
    }
    void printAdj(){
        //lets iterate in graph and print all key val pairs
        for(auto j:m){
            cout<<j.first<<" -> ";
            for(auto l:j.second){
                cout<<"("<<l.first<<","<<l.second<< ")";
            }
            cout<<"\n";
        }
    }
    void dijkstraSSSP(T src){
        unordered_map<T, int>dis;
        for(auto j:m){
            //set all distance to infinity
            dis[j.first] = INT_MAX;
        }
        //make a set to find out a node with minimum distance
        set<pair<int,T>>s;//int is for dis ..sorting is done with first parameter n we need min dis so yeah..
        dis[src] = 0;
        s.insert(make_pair(0,src));
        //find the pair at the front.
    while(!s.empty()){
        auto p = (*s.begin()); // pointer to pair
        T node = p.second;//this second val is of nodes
        int nodeDistance = p.first;
        s.erase(s.begin());
        //iterate over neighbour/children of current node
        for(auto childPair: m[node]){
            if(nodeDistance + childPair.second < dis[childPair.first]){
                //in a set , updation is not possible as like not possible in priority queues..but
                //we can remove the old pair and insert new one to simulate updation
                T dest = childPair.first;
                auto f = s.find(make_pair(dis[dest],dest));
                if(f!=s.end()){
                    s.erase(f);
                }
                dis[dest] = nodeDistance + childPair.second;
                s.insert(make_pair(dis[dest],dest));
                }
            }
        }
//lets print distances to all other nodes
        for(auto d:dis){
            cout<<d.first<<" is located at a dist of "<< d.second<<endl ;
        }


    }
};
using namespace std;
int main() {
    // Graph<int>g;
    // g.addEdge(1,2,1);
    // g.addEdge(1,3,4);
    // g.addEdge(2,3,1);
    // g.addEdge(3,4,2);
    // g.addEdge(1,4,7);
    // g.printAdj();
    // g.dijkstraSSSP(1);

    Graph<string>g;
    g.addEdge("amritsar","delhi",1);
    g.addEdge("amritsar","jaipur",4);
    g.addEdge("jaipur","delhi",2);
    g.addEdge("jaipur","mumbai",8);
    g.addEdge("bhopal","agra",2);
    g.addEdge("mumbai","bhopal",3);
    g.addEdge("agra","delhi",1);
    //g.printAdj();
    g.dijkstraSSSP("amritsar");
}







//SSSP : Dijkstras algorithm
