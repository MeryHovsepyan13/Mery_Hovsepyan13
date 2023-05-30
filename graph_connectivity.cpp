#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

void dfs(int v, vector<bool>& visited, vector<vector<int>>& adj, vector<int>& component) {
    visited[v] = true;
    component.push_back(v);
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, visited, adj, component);
        }
    }
}

int main() {
    ifstream inputFile("input.txt");  
    ofstream outputFile("output.txt");  

    int n, m;
    inputFile >> n >> m;  
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1, false);

    for (int i = 0; i < m; i++) {
        int u, v;
        inputFile >> u >> v;  
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<vector<int>> components;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> component;
            dfs(i, visited, adj, component);
            components.push_back(component);
        }
    }

    if (components.size() == 1) {
        outputFile << "The graph is connected" << endl;  
    }
    else {
        outputFile << "The graph is not connected" << endl;
        outputFile << "The connected components are:" << endl;
        for (auto component : components) {
            for (int v : component) {
                outputFile << v << " ";  
            }
            outputFile << endl;  
        }
    }

    inputFile.close();  
    outputFile.close();  

    return 0;
}
