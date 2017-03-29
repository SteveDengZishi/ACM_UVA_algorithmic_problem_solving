//  Topological sort with cycle detection
//  If it is not a DAG, output "IMPOSSIBLE", else output a possible topological sort start from vertex 0
//  Created by DENG ZISHI on 3/29/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//

#include <iostream>
#include <list>
#include <stack>
using namespace std;
 
// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
    
    // Pointer to an array containing adjacency listsList
    list<int> *adj;
    
    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
    
    // used by isCyclic()
    bool isCyclicUtil(int v, bool visited[], bool *rs);
    
public:
    Graph(int V);   // Constructor
    
    // function to add an edge to graph
    void addEdge(int v, int w);
    
    // prints a Topological Sort of the complete graph
    void topologicalSort();
    
    bool isCyclic();    // returns true if there is a cycle in this graph
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;
    
    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    
    // Push current vertex to stack which stores result
    Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
void Graph::topologicalSort()
{
    stack<int> Stack;
    
    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    
    // Call the recursive helper function to store Topological
    // Sort starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);
    
    // Print contents of stack
    while (!Stack.empty())
    {
        cout << Stack.top()+1 << endl;
        Stack.pop();
    }
}

// This function is a variation of DFSUytil()
bool Graph::isCyclicUtil(int v, bool visited[], bool *recStack)
{
    if(visited[v] == false)
    {
        // Mark the current node as visited and part of recursion stack
        visited[v] = true;
        recStack[v] = true;
        
        // Recur for all the vertices adjacent to this vertex
        list<int>::iterator i;
        for(i = adj[v].begin(); i != adj[v].end(); ++i)
        {
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack) )
                return true;
            else if (recStack[*i])
                return true;
        }
        
    }
    recStack[v] = false;  // remove the vertex from recursion stack
    return false;
}

// Returns true if the graph contains a cycle, else false.
// This function is a variation of DFS()
bool Graph::isCyclic()
{
    // Mark all the vertices as not visited and not part of recursion
    // stack
    bool *visited = new bool[V];
    bool *recStack = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
        recStack[i] = false;
    }
    
    // Call the recursive helper function to detect cycle in different
    // DFS trees
    for(int i = 0; i < V; i++)
        if (isCyclicUtil(i, visited, recStack))
            return true;
    
    return false;
}

//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a,b;
    while(cin>>a>>b){
        if(a==0 && b==0) break;
        //        cout<<"here"<<endl;
        Graph g(a);
        //        cout<<"finish graph"<<endl;
        while(b--){
            int c,d; cin>>c>>d;
            
            g.addEdge(c-1, d-1); // n-1 as the index of array starts from 0 to n-1
        }
        //cout<<"before sorting"<<endl;
        if(g.isCyclic()) cout<<"IMPOSSIBLE"<<endl;
        else g.topologicalSort();
    }
    return 0;
}
