#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& 
recStack){
    //modifying dfs recusion to return true is cycle exists or the element already exist is recStack

    vis[node] = 1;
    recStack[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it,adj,vis,recStack)){
                return true;
            }
        }
        else if(recStack[it]){
            return true;
        }
    }

    recStack[node] = 0;
    return false;
}


void detectCycle(int n, vector<int> adj[]){
    vector<int> vis(n,0);
    vector<int> recStack(n,0);

    for(int i =0; i<n; i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,recStack)){
                cout<<"Cycle Detected"<<endl;
                return;
            }
        }
    }

    cout<<"No cycle detected"<<endl;
}

int main(){
    int n =4 ;
    vector<int> adj[n];

    adj[0].push_back(1);
    // adj[0].push_back(2);
    adj[1].push_back(2);
    // adj[2].push_back(0);
    adj[2].push_back(3);
    // adj[3].push_back(3);

    detectCycle(n ,adj);

    return 0;
}
    
