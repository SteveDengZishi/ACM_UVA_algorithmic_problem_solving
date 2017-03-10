//  Created by DENG ZISHI on 03/09/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//
//  unionFind_string.cpp
//  Union_find or disjointed_set data structure of strings using map<string,Node*>

//individual sets
struct Node{
    int rank;
    string data;
    Node* parent;
    
    Node(string str):data(str),rank(0),parent(this){}
};

struct unionFind{
    //pointers to individual set Nodes
    map<string,Node*> Mnode;
    
    //construct individual sets on heap and push_back into Vnode uf.push(num);
    void push(string name){
        Node* set=new Node(name);
        Mnode[name]=set;
    }
    
    //find function with path compression
    Node* find(Node* x){
        
        //    cout<<"in find"<<endl;
        
        if(x->parent!=x) x->parent=find(x->parent);
        return x->parent;
    }
    
    //Union
    void Union(Node* x,Node* y){
        
        //    cout<<"in union"<<endl;
        
        Node* xRoot = find(x);
        Node* yRoot = find(y);
        
        if(xRoot==yRoot) return;
        if(xRoot->rank < yRoot->rank) xRoot->parent = yRoot;
        else if(xRoot->rank > yRoot->rank) yRoot->parent = xRoot;
        else{
            yRoot->parent = xRoot;
            xRoot->rank+=1;
        }
    }
    
    //join two sets by its index in Vnode starts with index 0
    void join(string x,string y){
        Union(Mnode[x],Mnode[y]);
    }
    
    //search root by index and return its root's data
    string search(string name){
        return(find(Mnode[name])->data);
    }
};
ß
