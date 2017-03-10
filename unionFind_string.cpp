//  Created by DENG ZISHI on 03/09/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//
//  unionFind_string.cpp
//  Union_find or disjointed_set data structure of strings using map<string,Node*> with count updated!

//individual sets
struct Node{
    int rank;
    int cnt;// keep track of count in root node
    string data;
    Node* parent;
    
    Node(string str):data(str),rank(0),cnt(1),parent(this){}
};

struct unionFind{
    //pointers to individual set Nodes
    map<string,Node*> Mnode;
    
    //construct individual sets on heap and push_back into Vnode uf.push(num);
    void push(string name){
        Node* set=new Node(name);
        pair<string,Node*> pair(name,set); // use pair & insert to prevent insertion of duplicates after union
        Mnode.insert(pair);
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
        if(xRoot->rank < yRoot->rank) {
            xRoot->parent = yRoot;
            yRoot->cnt+=xRoot->cnt;
        }
        else if(xRoot->rank > yRoot->rank) {
            yRoot->parent = xRoot;
            xRoot->cnt+=yRoot->cnt;
        }
        else{
            yRoot->parent = xRoot;
            xRoot->rank+=1;
            xRoot->cnt+=yRoot->cnt;
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
