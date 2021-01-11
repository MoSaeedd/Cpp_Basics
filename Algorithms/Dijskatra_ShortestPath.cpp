#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
// #define INT_MAX 2147483647
vector<string> split_string(string);

// Complete the shortestReach function below.
int minDistance(const vector<int> dist, const vector <bool> sptSet, int n) 
{ 
    int min = INT_MAX, min_index;   
    for (int v = 0; v < n; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}
vector<int> shortestReach(int n, vector<vector<int> > edges, int s) {
    vector <vector <int> > graph (n,vector <int> (n,0));
    fill(graph.begin(), graph.end(), vector<int>(n, 0));
    vector <bool> visited (n,false);
    vector<int> AR (n,INT_MAX);

    for(int i=0 ; i<edges.size() ; i++)
    {
        graph[edges[i][0]-1][edges[i][1]-1]= edges[i][2];
        graph[edges[i][1]-1][edges[i][0]-1]= edges[i][2];
            
    }        
    AR[s-1]=0;  
    for(int i=0 ; i< n-1 ; i++)
    {        
        int u = minDistance(AR, visited,n); 
        visited[u] = true; 
        for (int v = 0; v < n; v++) 
        {        
        if (!visited[v] && graph[u][v] && AR[u]!=INT_MAX && AR[u] + graph[u][v] < AR[v]) 
            AR[v] = AR[u] + graph[u][v];
            
        }
    }
    for(int i= 0 ; i<AR.size() ; i++)
    {
        if(AR[i]==INT_MAX)
            AR[i]=-1;
    }     
    vector<int>::iterator it= AR.begin();
    advance(it,s-1);
    AR.erase(it);
    return AR;
}

int main()
{
    int nodes=3;
    int start_node= 1;

    // edges , each edge is in the form of start _node, end_node, weight
    vector<vector<int> > edges   { {1,3,2},{1,2,2},{2,3,2} };// this init needs c++ 11 or higher
    vector<int> distToEachNode= shortestReach(nodes, edges, start_node);

    //print the distance to each node in order
    for (int i = 0; i < distToEachNode.size(); i++)
    {
        cout<<distToEachNode[i]<<endl;
    }

    return 0;
}

  