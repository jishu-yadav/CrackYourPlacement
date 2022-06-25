// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int find_parent(int node,vector<int>&parent){
	    if(node==parent[node])
	    return node;
	    return parent[node] = find_parent(parent[node],parent);
	}
	void find_union(int node1,int node2,vector<int>&rank,vector<int>&parent){
	    node1 = find_parent(node1,parent);
	    node2 = find_parent(node2,parent);
	    if(rank[node1]<rank[node2])
	        parent[node1]=node2;
	   else if(rank[node2]<rank[node1])
	        parent[node2] = node1;
	   else{
	       parent[node2] = node1;
	       rank[node1]++;
	   }
	}
	//comparator
	static bool comp(vector<int>&a,vector<int>&b){
	    return a[2]<b[2];
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>parent(V);
        vector<int>rank(V,0);
        vector<vector<int>>edges;
        for(int i=0;i<V;i++){
            parent[i] = i;
        }
        //storing nodes and its weight
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                edges.push_back({i,x[0],x[1]});
            }
        }
        sort(edges.begin(),edges.end(),comp);
        int cost=0;
        for(auto it:edges){
            if(find_parent(it[1],parent)!=find_parent(it[0],parent)){
                find_union(it[0],it[1],rank,parent);
                cost+=it[2];
            }
        }
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends