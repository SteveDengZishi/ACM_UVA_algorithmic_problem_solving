//  Graham Scan Algorithm for Convex Hull
//
//  Created by Steve DengZishi on 4/29/17.
//  Copyright © 2017 Steve DengZishi. All rights reserved.
//
//  1. Anchor point P0 is the one with lowest y coordinates (leftmost if tied)
//  2. Sort by polar angles (counter clockwise order)
//  3. Check whether left turn to the point on top of stack
//  4. Push the point on to the stack if left turn
//  5. Pop the point if right turn & repeat the checking process (not on the hull)
//
//  Running time: O(nlogn) sorting + O(n) scanning  OVERALL O(nlogn)


#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath> // To use sqrt()
#include <list> // To use STL linked-list in dfs topological sort
#include <stack> // To use STL stack in topological sort
#include <queue> // To use STL queue in bfs, dijkstra's, maxflow
#include <cstring> // To use memset()
#include <cstdlib> // To use atoi(), abs(), malloc()
#include <algorithm> // To use sort(), next_permutation(), min(), max() etc.
#include <unordered_map> // To allow O(1) mapping access using key->value
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
//point struct
typedef struct pnode
{
    double x;
    double y;
    double d;
    
    pnode( double a, double b ){
        x = a;
        y = b;
    }
    
    pnode(){}
    
}point;

point P[ 1005 ];

//distance between points
double dist( point a, point b )
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

//cross product vec_ab * vec_ac
double crossproduct( point a, point b, point c )
{
    return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}

//coordinate comp
bool cmp1( point a, point b )
{
    return (a.x == b.x)?(a.y < b.y):(a.x < b.x);
}

//angle cmp
bool cmp2( point a, point b )
{
    double cp = crossproduct( P[0], a, b );
    if ( cp == 0 ) return a.d < b.d;
    else return cp > 0;
}

double Graham( int n )
{
    if ( n > 1 ) {
        sort( P, P+n, cmp1 );
        for ( int i = 1 ; i < n ; ++ i )
            P[i].d = dist( P[0], P[i] );
        sort( P+1, P+n, cmp2 );
    }
    
    //calculates convex hull
    int top = n-1;
    if ( n > 2 ) {
        top = 1;
        for ( int i = 2 ; i < n ; ++ i ) {
            while ( top > 0 && crossproduct( P[top-1], P[top], P[i] ) < 0 ) -- top;
            P[++ top] = P[i];
        }
    }
    P[++ top] = P[0];
    
    //calculating circumference
    double sum = 0.0;
    for ( int i = 0 ; i < top ; ++ i )
        sum += dist( P[i], P[i+1] );
    
    return sum;
}

//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //reminder to clear vector between test cases
    //Your code here
    
    int t,n,l;
    cin>>t;
    while(t--) {
        cin >> l >> n;
        for ( int i = 0 ; i < n ; ++ i )
            cin >> P[i].x >> P[i].y;
        
        double ans = Graham( n );
        if ( ans < l ) ans = l+0.0;
        printf("%.5lf\n",ans);
    }
    
    return 0;
}
