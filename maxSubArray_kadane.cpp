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

//Non-STL Data Structures definition here


//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifdef defaultTestCase
    //Your code here if default test case given
    VI vec;
    int x; cin>>x;
    FOR(j,0,x){
        vec.clear();
        vec.push_back(0);
        int y; cin>>y;
        while(--y){
            //DE(y);
            int z; cin>>z;
            //DE(z);
            vec.push_back(z);
            //cout<<"finished"<<endl;
        }
        //DEVEC(vec);
        int start=1, end=1, maxSum=0, currSum=0;
        int startStop, endStop;
        FOR(i,1,vec.size()){
            end=i;
            currSum+=vec[end];
            //DE(currSum);
            if(currSum>maxSum){
                //DEIF;
                maxSum=currSum;
                startStop=start;
                endStop=end+1;
            }
            else if(currSum<0){
                //DEELSEIF;
                currSum=0;
                start=i+1;
            }
            else if(currSum==maxSum){
                int dis=end-start;
                int lastDis=endStop-startStop;
                if(dis>lastDis){
                    startStop=start;
                    endStop=end+1;
                }
            }
        }
        if(maxSum<=0) cout<<"Route "<<j+1<<" has no nice parts"<<endl;
        else{
            cout<<"The nicest part of route "<<j+1<<" is between stops "<<startStop<<" and "<<endStop<<endl; 
        }
    }
#endif
#ifndef defaultTestCase
    //Your code here if customized test case
    
#endif
    return 0;
}

