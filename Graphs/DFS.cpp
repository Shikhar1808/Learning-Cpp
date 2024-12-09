// Depth First Seatch: based on depth traversal of a graph

#include <iostream>
#include <vector>

using namespace std;

class DFS{
    private:
        void dfs(int node, vector<int> adj[], int vis[], vector<int> ls){
            //dfs function takes the node, adjacency list, visited array and the list to store the DFS traversal as input
            
            vis[node] = 1;
            cout<<node<<" ";
            ls.push_back(node);

            for(auto it: adj[node]){
                if(!vis[it]){
                    dfs(it, adj, vis, ls);
                }
            }
        }
    
    public:

        vector<int> dfsOfGraph(int n, vector<int> adj[]){
            int vis[n] = {0}; //visited array to keep track of visited nodes and avoid revisiting them
            int start = 0;
            vector<int> ls; //vector to store the DFS traversal of the graph
            // dfs(start, adj, vis, ls);
            for(int i = 0; i < n; i++){
                if(!vis[i]){
                    dfs(i, adj, vis, ls);
                }
            }
            return ls;
        }
};

//Time Complexity: O(N) + O(2E) = O(N + E) where N is the number of nodes and E is the number of edges
//Space Complexity: O(N) + O(N) = O(N) where N is the number of nodes

int main(){
    int n = 7;
    vector<int> adj[n];

    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[4].push_back(3);
    adj[3].push_back(4);

    adj[4].push_back(5);
    adj[5].push_back(4);

    adj[4].push_back(6);
    adj[6].push_back(4);

    DFS obj;
    vector<int> res = obj.dfsOfGraph(n, adj);

    // cout<<"DFS Traversal of the graph is: ";
    for(auto i: res){
        cout << i << " ";
    }

    return 0;
}