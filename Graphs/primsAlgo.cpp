//Prims Algorithm for MSTs

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

class spanningTree{ 
    private:
        void primsAlgo(int n, vector<pair<int, int>> adj[]){
            //primsAlgo function takes the number of nodes and the adjacency list as input
            //It returns the minimum spanning tree of the graph


            //Step 1: Initialize the parent, weight, mst vectors and the min heap
            //Step 2: Set the weight of the first node as 0 and push it into the min heap
            //Step 3: While the min heap is not empty, extract the node with the minimum weight
            //Step 4: Mark the node as included in the MST
            //Step 5: Iterate through the adjacency list of the current node and update the key value of the connected nodes
            //Step 6: If the weight of the connected node is less than the current weight of the node, update the weight and parent of the connected node and push it into the min heap for further processing
            //Step 7: Repeat steps 3-6 until the min heap is empty
            //Step 8: Print the parent and the connected node of each node in the MST
            
            vector<int> parent(n, -1); //vector to store the parent of each node in the MST
            vector<int> weight(n, INT_MAX); //vector to store the key value of each node
            //
            vector<bool> mst(n, false); //vector to keep track of the nodes included in the MST
            
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //min heap to store the nodes and their weights
            //structure of the min heap is {weight, node}

            weight[0] = 0; //initialize the weight of the first node as 0
            pq.push({0, 0}); //push the first node into the min heap

            while(!pq.empty()){
                int currentNode = pq.top().second; //extract the node with the minimum weight
                pq.pop();

                if(mst[currentNode]){
                    //if the node is already included in the MST, skip it
                    continue;
                }

                mst[currentNode] = true; //mark the node as included in the MST

                for(auto it: adj[currentNode]){
                    //iterate through the adjacency list of the current
                    //node and update the key value of the connected nodes
                    
                    //if the weight of the connected node is less than the
                    //current weight of the node, update the weight and parent
                    //of the connected node and push it into the min heap
                    //for further processing
                    
                    int connectedNode = it.first;
                    int weightOfConnectedNode = it.second;

                    if(!mst[connectedNode] && weightOfConnectedNode < weight[connectedNode]){
                        parent[connectedNode] = currentNode;
                        weight[connectedNode] = weightOfConnectedNode;
                        pq.push({weight[connectedNode], connectedNode});
                    }
                }
            }
            
            
            for(int i = 1; i < n; i++){
                cout<<parent[i]<<" - "<<i<<"\n";
            }
        }
    
    public:
        void findMST(int n, vector<pair<int, int>> adj[]){
            primsAlgo(n, adj);
        }
};

//Time Complexity: O(NlogN + E) where N is the number of nodes and E is the number of edges
//Space Complexity: O(N) + O(E) = O(N + E) where N is the number of nodes and E is the number of edges

int main(){

    int n = 5;
    vector<pair<int, int>> adj[n]; 
    //structure of the adjacency list is {node, weight}

    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    spanningTree obj;
    obj.findMST(n, adj);

    return 0;
}