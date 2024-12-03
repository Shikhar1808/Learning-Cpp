// Breadth First Search: based on level order traversal of a graph
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class BFS {
    public:
        vector<int> bfsOfGraph(int n, vector<int> adj[]){  //bfaOfGraph function takes the
        //number of nodes and the adjacency list as input 
        //and returns the BFS traversal of the graph
            int vis[n] = {0}; //visited array to keep track of visited nodes 
            //and avoid revisiting them
            vis[0] = 1; //assuming the first node i.e. 0 is visited
            
            queue<int> q; //queue is used to store the nodes and traverse them level by level
            q.push(0);

            vector<int> bfs;//vector to store the BFS traversal of the graph

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }

            return bfs;
        }
};

//Time Complexity: O(N) + O(2E) = O(N + E) where N is the number of nodes and E is the number of edges

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

    BFS bfs;
    vector<int> res = bfs.bfsOfGraph(n, adj);

    for(auto i: res){
        cout << i << " ";
    }

    return 0;
}