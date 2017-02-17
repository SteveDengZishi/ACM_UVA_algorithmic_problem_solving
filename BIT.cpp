//  Created by DENG ZISHI on 2/17/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//
//  Binary indexed tree supporting binary search.

struct BIT {
    int n;// original vector size
    vector<int> bit;//size is (n+1) where f[0] is a dummy node
    // BIT can be thought of as having entries f[1], ..., f[n]
    // which are 0-initialized
    BIT(int n):n(n), bit(n+1) {}
    // construct from vector
    BIT(vector<int> vec):n(vec.size()),bit(vec.size()+1){
        for(size_t i=0;i<vec.size();i++){
            update(i+1,vec[i]);
        }
    }
    // returns f[0] + ... + f[idx] including this end idx in the original vector
    // precondition idx <= n+1
    int sum(int idx) {
        int total = 0;
        while (idx > 0) {
            total += bit[idx];
            idx -= idx & -idx;
        }
        return total;
    }
    // returns f[idx1] + ... + f[idx2]
    // precondition idx1 <= idx2 <= n+1
    int sumWithRange(int idx1, int idx2) {
        return sum(idx2) - sum(idx1-1);//(idx-1) as includes the first end bound f[idx1] in the result
    }
    // adds val to f[idx]
    // precondition 1 <= idx <= n (there is no element 0!)
    void update(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
};

////Test Code
//int main(int argc, const char * argv[]) {
//    //optimize iostream
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    
//    //Your code here
//    VI vec;
//    FOR(i,1,101){
//        vec.push_back(i);
//    }
//    BIT tree(vec);
//    
//    int result1=tree.sum(100);
//    int result2=tree.sumWithRange(11,100);
//    
//    cout<<"the sum from 1 to 100 is: "<<result1<<endl; //5050
//    cout<<"the sum from 11 to 100 is: "<<result2<<endl; //4995
//    
//    return 0;
//}
