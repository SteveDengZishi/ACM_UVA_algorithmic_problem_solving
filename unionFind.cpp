//  Created by DENG ZISHI on 2/17/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//
//  unionFind.cpp
//  Union_find or disjointed_set data structure implementation

//individual sets
struct Node{
    int rank;
    int data;
    Node* parent;
    
    Node(int d):data(d),rank(0),parent(this){}
};

struct unionFind{
    //pointers to individual set Nodes
    vector<Node*> Vnode;
    
    //construct individual sets on heap and push_back into Vnode uf.push(num);
    void push(int num){
        Node* set=new Node(num);
        Vnode.push_back(set);
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
    void join(int x,int y){
        Union(Vnode[x],Vnode[y]);
    }
    
    //search root by index and return its root's data
    int search(int num){
        return(find(Vnode[num])->data);
    }
};

////Test Code
//int main(int argc, const char * argv[]) {
//    //optimize iostream
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    
//    //Your code here
//    unionFind uf;
//    FOR(i,0,10){
//        uf.push(i);
//    }
//    uf.join(3,4);
//    uf.join(0,1);
//    uf.join(1,4);
//    uf.join(8,9);
//    FOR(i,0,10){
//        int num=uf.search(i);
//        cout<<num<<endl;
//    }
//    return 0;
//}

