//  Created by DENG ZISHI on 2/17/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib> // To use atoi(), abs(), malloc()
#include <algorithm> // To use sort(), next_permutation(), min(), max() etc.
#include <unordered_map> // To allow O(1) mapping access using key->value
#include <set> // To sort and remove duplicate when inserted

//macro here
#define FOR(i,a,b) for(size_t i=a;i<b;i++)
#define DE(x) cout << #x << ":" << x << endl
#define all(a) a.begin(),a.end()
#define cinLine(a) getline(cin,a)
#define fill(a,b) memset(a, b , sizeof(a)) //fill array a with all bs
#define init(a) fill(a,0) //initialize array a with all 0s
#define INF 2e9

#define multiTestCases //comment out this line if only one test case

//name space here
using namespace std;

//typedef here
typedef vector<int> VI;

//debugging functions here
void DEVEC(VI vec){
    FOR(i,0,vec.size()){
        DE(vec[i]);
    }
    cout<<endl;
}

//Non-STL Data Structures definition here


//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
#ifdef multiTestCases
    //Your code here if there are many test cases
    VI vec;
    int x; cin>>x;
    while(x--){
        vec.clear();
        
    }
#endif
#ifndef multiTestCases
    //Your code here if only one test case
    
#endif
    return 0;
}
