//  Graph with DFS
//  Only partially done

//  Created by DENG ZISHI on 2/20/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//
#include <unordered_map>
#include <list>
#include <stack>

template <class T>
struct Node{
    bool visited;
    T data;
    
    typedef unordered_map<Node,list<Node>> adjacencyList;
    
    Node(T info):visited(0),data(info){}
};

template <class T>
struct Graph{
    int size;
    typename Node<T>::adjacencyList adjL;
    
    bool isConnected(T x,T y){
        return false;
    }
    
    void addEdge(T x,T y){
        
    }
    
    void dfs(T start,T end){
        stack<T> st; //build a stack to begin dfs
        st.push(start);
        Node<T> begin(start);
        //mark visited
        
    }
    
    int solve(){
        
    }
};
