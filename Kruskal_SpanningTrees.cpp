#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <list> // To use STL linked-list in dfs topological sort
#include <stack> // To use STL stack in topological sort
#include <cstring> // To use memset()
#include <cstdlib> // To use atoi(), abs(), malloc()
#include <algorithm> // To use sort(), next_permutation(), min(), max() etc.
#include <unordered_map> // To allow O(1) mapping access using key->value
#include <map>
#include <set> // To sort and remove duplicate when inserted
#include <unordered_set> //To remove duplicates and count size

//macro here
#define FOR(i,a,b) for(size_t i=a;i<b;i++)
#define DE(x) cout << #x << ":" << x << endl
#define DEIF cout<<"DEBUG: in if"<<endl
#define DEELSE cout<<"DEBUG: in else"<<endl
#define DEIFIF cout<<"DEBUG: in if if"<<endl
#define DEIFELSE cout<<"DEBUG: in if else"<<endl
#define DEELSEIF cout<<"DEBUG: in else if"<<endl
#define DEELSEELSE cout<<"DEBUG: in else else"<<endl
#define ALL(a) a.begin(),a.end()
#define CINLINE(a) getline(cin,a)
#define FILL(a,b) memset(a, b , sizeof(a)) //fill array a with all bs
#define INIT(a) FILL(a,0) //initialize array a with all 0s
#define INF 2e9

#define defaultTestCase //comment out this line if not default test case given
#define maximumSpanning
//name space here
using namespace std;

//typedef here
typedef vector<int> VI;
typedef vector<pair<int,pair<int,int>>> Edges;
typedef pair<int,int> PII;

//debugging functions here
template<class T>
void DEVEC(vector<T> vec){
    FOR(i,0,vec.size()){
        DE(vec[i]);
    }
    cout<<endl;
}

template<class T>
void DEARRAY(T array[],int num=20){
    FOR(i,0,num+1){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

//functions, global variables, comparators & Non-STL Data Structures definition here
template<class T>
bool pairCmp(pair<T,T> a,pair<T,T> b)  {
    if(a.first!=b.first)      return a.first<b.first;
    return a.second<b.second;
}

struct edgeCmp{
    //mapCmp functor in deciding minimum spanning tree or maximum spanning tree
    bool operator()(pair<int,pair<int,int>> a, pair<int,pair<int,int>> b){
#ifdef maximumSpanning
        return a.first>=b.first;
#endif
#ifndef maximumSpanning
        return a.first<=b.first;
#endif
    }
};

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
    
    //constructor
    unionFind(int num){
        FOR(i,0,num){
            push(i);
        }
    }
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

int cnt=0;int mini=INF;
Edges edges;
edgeCmp cmpE;

int kruskal(unionFind uf){
    mini=INF;
    int result=0;//minimum || maximum spanning
    stack<PII> stk;//To store path of the spanning
    
    sort(ALL(edges),cmpE);//sort in non-decreasing or non-increasing order
    
    FOR(i,0,edges.size()){
        //if the two pairs are not connected component
        if(uf.search(edges[i].second.first)!=uf.search(edges[i].second.second)) {
            //join them together
            uf.join(edges[i].second.first, edges[i].second.second);
            //push to stack
            stk.push(edges[i].second);
            //caculate spanning
            result+=edges[i].first;
            if(edges[i].first<mini) mini=edges[i].first;
        }
    }
    return result;
}

//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifdef defaultTestCase
    //Your code here if default test case given
    
    int x; cin>>x;
    while(x--){
        cnt++;
        edges.clear();
        int a,b; cin>>a>>b;
        unionFind uf(a);
        int start,end,weight;
        while(b--){
            cin>>start>>end>>weight;
            if(start==end) continue;
            PII p(start, end);
            pair<int,PII> ed(weight,p);
            edges.push_back(ed);
        }
        int result=kruskal(uf);
        cout<<"Case #"<<cnt<<": "<<result<<endl;
    }
#endif
#ifndef defaultTestCase
    //Your code here if customized test case
    
#endif
    return 0;
}
