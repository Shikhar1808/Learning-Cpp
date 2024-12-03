//Kruskal's Algorithm

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class kruskalsAlgo{
    private:
        int findParent(int node, vector<int> &parent){
            //findParent function takes the node and the parent array as input
            //It returns the parent of the node
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findParent(parent[node], parent); //this line is for path compression meaning that the parent of the node is directly set to the root node
        }

        void unionNodes(int node1, int node2, vector<int> &parent){
            //unionNodes function takes the two nodes and the parent array as input
            //It merges the two nodes by setting the parent of one node as the other node

            int parent1 = findParent(node1, parent);
            int parent2 = findParent(node2, parent);

            parent[parent1] = parent2;
        }

    public:
        vector<pair<int, pair<int, int>>> kruskals(vector<pair<int, pair<int, int>>> edges, int n){
            //kruskals function takes the edges and the number of nodes as input
            //structure of the edges: {weight, {node1, node2}}
            //It returns the minimum spanning tree of the graph

            //Step1
            //1. Initialize the parent array
            //2. Initialize the result vector to store the MST

            //Step2
            //1. Sort the edges based on the weight

            //Step3
            //1. Iterate through the edges
            //2. If the parent of the two nodes is not the same, merge the two nodes
            //3. Add the edge to the result vector

            vector<int> parent(n);

            for(int i = 0; i < n; i++){ //initially, each node is the parent of itself
                parent[i] = i;
            }

            sort(edges.begin(), edges.end());

            vector<pair<int, pair<int, int>>> mst;

            for(auto &it: edges){ //this is the main logic of Kruskal's algorithm
                int weight = it.first;
                int node1 = it.second.first;
                int node2 = it.second.second;

                if(findParent(node1, parent) != findParent(node2, parent)){
                    mst.push_back({weight, {node1, node2}});
                    unionNodes(node1, node2, parent);
                }
            }

            return mst;
        }
};

//Time Complexity: O(ElogE + ElogV) where E is the number of edges and V is the number of vertices
//Space Complexity: O(V) + O(E) = O(V + E) where V is the number of vertices and E is the number of edges


int main(){
    int n = 6; //number of nodes
    vector<pair<int, pair<int, int>>> edges; //vector to store the edges of the graph

    //structure of the edges: {weight, {node1, node2}}
    edges.push_back({1, {0, 1}});
    edges.push_back({2, {1, 2}});
    edges.push_back({3, {2, 3}});
    edges.push_back({4, {3, 4}});
    edges.push_back({5, {4, 5}});
    edges.push_back({6, {0, 2}});
    edges.push_back({7, {1, 3}});
    edges.push_back({8, {2, 4}});
    edges.push_back({9, {3, 5}});

    kruskalsAlgo obj;
    vector<pair<int, pair<int, int>>> mst = obj.kruskals(edges, n);

    cout<<"Minimum Spanning Tree of the graph is: \n";
    for(auto it: mst){
        cout<<it.second.first<<" - "<<it.second.second<<" : "<<it.first<<"\n";
    }

    return 0;
}