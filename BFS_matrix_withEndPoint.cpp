//
//  BFS using adjacency matrix with starting and ending points
//  backtracking path and calculating the unweighted shortest path in undirected graph
//
//  Created by Steve DengZishi on 5/7/17.
//  Copyright © 2017 Steve DengZishi. All rights reserved.
//

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

//adjacency matrix to represent vertices & edges
int graph [10001][10001];
int visited [10001];
int previous[10001]; //back track parent vertex

void addEdge(int start,int end){
    graph[start][end]=1;
    graph[end][start]=1;
}

//backtracking and print shortest path and length
void printPath(int end){
    stack<int> st;
    int len=0;
    st.push(end);
    while(previous[end]!=-1){
        end=previous[end];
        st.push(end);
        len++;
    }
    printf("Path: ");
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<"The shortest length is: "<<len<<endl;
}

//dfs can be a recursive call or using stack while bfs is using a while loop and push adjacent
//points to a queue
void bfs(int start, int end){
    queue<int> q;
    
    q.push(start);
    visited[start]=1; // visited must be marked directly after push queue to prevent double queue
    
    while(!q.empty() && start!=end){
        start=q.front();
        q.pop();
        //cout<<start<<" "; // uncomment this line to show full bfs path
        
        //visit and push all non-visited adjacent vertices to queue
        for(int i=0;i<10001;i++){
            if(graph[start][i] && !visited[i]){
                q.push(i);
                visited[i]=1; // mark visited
                previous[i]=start; // store parent
            }
        }
        
    }
    
    //stop and the end point to reduce excessive running time
    if(start==end){
        printPath(end);
        return;
    }
    
    printf("There is no path from %d to %d\n", start, end);
    return;
}

// need to call init() before making a graph
void init(){
    memset(graph, 0, sizeof(graph));
    memset(visited, 0, sizeof(visited));
    memset(previous, -1, sizeof(previous));
}

// need to call reset() between queries
void reset(){
    memset(visited, 0, sizeof(visited));
    memset(previous, -1, sizeof(previous));
}


int main(){
    init();
    
    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(1, 4);
    addEdge(0, 3);
    addEdge(3, 4);
    addEdge(0, 5);
    addEdge(5, 6);
    addEdge(3, 6);
    addEdge(6, 7);
    
    bfs(3, 2); //Path: 3 0 1 2 The shortest length is: 3
    reset();
    bfs(1, 7); //Path: 1 0 3 6 7 The shortest length is: 4
    reset();
    bfs(2, 7); //Path: 2 1 0 3 6 7 The shortest length is: 5
    reset();
    bfs(8, 2); //There is no path from 8 to 2
    reset();
    bfs(3, 2); //Path: 3 0 1 2 The shortest length is: 3
}
