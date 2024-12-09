#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

// Dijkstra's Algorithm is used to find the shortest path from a source vertex to all other vertices in the given graph.
// It is a greedy algorithm.
// It works for both directed and undirected graphs.
// It works for graphs with positive edge weights.
// It does not work for graphs with negative edge weights or cycles because it will keep on traversing the cycle and the distance will keep on decreasing.

// Time Complexity: O(V^2) for adjacency matrix representation and o(ElogV) for adjacency list representation using priority queue. V: Number of vertices, E: Number of edges
// Space Complexity: O(V) + O(V) = O(V) for distance array and priority queue

class dijkstrasAlgorithm{
    public:
        vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){ // V: Number of vertices, adj: Adjacency list, S: Source vertex
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min-heap; pair<distance, vertex>

            vector<int> dist(V); // Initialize distance of all vertices to infinity
            for(int i = 0; i < V; i++){
                dist[i] = INT_MAX;
            }

            dist[S] = 0; // Distance of source vertex from itself is 0
            pq.push({0, S}); // Push source vertex into the priority queue

            while(!pq.empty()){
                int dis = pq.top().first; // Distance of vertex u
                int node = pq.top().second; // Extract the vertex with minimum distance value
                pq.pop();

                for(auto it: adj[node]){ //Traversal of adjacency list
                    int nextNode = it[0];
                    int edgeWeight = it[1];

                    if(dist[nextNode] > dis + edgeWeight){ // If the distance of vertex u + edge weight < distance of vertex v, then update the distance of vertex v
                        dist[nextNode] = dis + edgeWeight; // Update the distance of vertex v
                        pq.push({dist[nextNode], nextNode}); // Push the vertex v into the priority queue or min-heap
                    }
                }
            }

            return dist; // Return the distance array
        };

        
};

int main(){
    int V = 5; // Number of vertices
    vector<vector<int>> adj[V]; // Adjacency list

    // Add edges
    adj[0].push_back({1, 2}); // Edge from vertex 0 to vertex 1 with weight 2
    adj[0].push_back({2, 4}); // Edge from vertex 0 to vertex 2 with weight 4
    adj[1].push_back({2, 1}); // Edge from vertex 1 to vertex 2 with weight 1
    adj[1].push_back({3, 7}); // Edge from vertex 1 to vertex 3 with weight 7
    adj[2].push_back({3, 3}); // Edge from vertex 2 to vertex 3 with weight 3
    adj[2].push_back({4, 5}); // Edge from vertex 2 to vertex 4 with weight 5
    adj[3].push_back({4, 2}); // Edge from vertex 3 to vertex 4 with weight 2

    dijkstrasAlgorithm obj;
    vector<int> res = obj.dijkstra(V, adj, 0); // Source vertex is 0

    for(int i = 0; i < V; i++){
        cout<<res[i]<<" "; //Output: 0 2 3 6 8
    }

    return 0;
}