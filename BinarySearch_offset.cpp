//  BinarySearch_offset.cpp
//  Using binarySearch to guess the value
//
//  Created by DENG ZISHI on 3/10/17.
//  Copyright © 2017 DENG ZISHI. All rights reserved.
//

VI vec;

bool check(int mid,int num){
    int count=1;
    int tmp=vec[0];
    FOR(i,0,vec.size()){
        if(vec[i]-tmp>=mid) {
            count++;
            tmp=vec[i];
        }
    }
    return count>= num;
    
}

//start of main()
int main(int argc, const char * argv[]) {
    //optimize iostream
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //Your code here
    int x;
    cin>>x;
    while(x--){
        vec.clear();
        int a,b;
        cin>>a>>b;
        
        while(a--){
            int c;
            cin>>c;
            vec.push_back(c);
        }
        sort(all(vec));
        //        DEVEC(vec);
        int maxVal = vec[vec.size()-1]-vec[0];
        int minVal = 0;
        //        DE(b);
        while(maxVal>minVal){
            //            DE(minVal);
            int midVal=minVal+(maxVal-minVal+1)/2;
            if(check(midVal,b)) minVal=midVal;
            else maxVal=midVal-1;
        }
        cout<<minVal<<endl;
    }
    
    return 0;
}
