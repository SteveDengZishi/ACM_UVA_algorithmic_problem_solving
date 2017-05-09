//  Created by DENG ZISHI on 03/31/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//
// LIS stands for Longest Increasing Subsequence algorithm
// Finding LIS using a nlogn algorithm with binary search insertion and parent backtracking

//  Created by DENG ZISHI on 2/17/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
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
#define INIT(a) fill(a,0) //initialize array a with all 0s
#define INF 2e9

#define defaultTestCase //comment out this line if not default test case given

//name space here
using namespace std;

//typedef here
typedef vector<int> VI;

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

int here[10001];
int track[10001];
int maxLength;

int binSearch(int currIdx, int currVal){
    //cout<<"here"<<endl;
    int low=1,high=currIdx;
    int mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(here[mid]<=currVal) low=mid+1;
        else high=mid-1;
    }
    return low;
}

void recursivePrint(int idx){
    //cout<<"here"<<endl;
    if(idx==-INF) return;
    recursivePrint(track[here[idx]]);
    cout<<here[idx]<<endl;
}

//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifdef defaultTestCase
    //Your code here if default test case given
    VI vec;
    int x; cin>>x;
    while(x--){
        vec.clear();
        int y;
        while(cin>>y){
            vec.push_back(y);
        }
    }
    //DEVEC(vec);
    maxLength=0;
    here[0]=-INF;
    int count=0;
    FOR(i,0,vec.size()){
        if(vec[i]>here[count]){
            //DEIF;
            
            here[count+1]=vec[i];
            maxLength++;
            track[vec[i]]=here[count];//track last number;
            count++;
        }
        else{
            //DEELSE;
            int currVal=vec[i];
            int index=binSearch(i,currVal);
            here[index]=currVal;
            track[currVal]=here[index-1];
        }
        //DEARRAY(here);
        //DEARRAY(track);
    }
    cout<<"Max hits: "<<maxLength<<endl;
    
    recursivePrint(maxLength);
    if(x+1) cout<<endl;
#endif
#ifndef defaultTestCase
    //Your code here if customized test case
    
#endif
    return 0;
}
