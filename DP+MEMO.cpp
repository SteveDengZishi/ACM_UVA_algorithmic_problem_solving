#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring> // To use memset()

using namespace std;
//fib without memoization
int fib(int n){
	if(n<=0) return 0;
	else if(n==1) return 1;
	else{
		return fib(n-1)+fib(n-2);
	}
}
//fib with memoization
int fib(int n,int memo[]){
	if(n<=0) return 0;
	else if(n==1) memo[1]=1;
	else if(!memo[n]){
		memo[n]=fib(n-1,memo)+fib(n-2,memo);
	}
	return memo[n];
}

//testing the program
int main(){
	int memo[21];
	memset(memo,0,sizeof(memo));
	int fibNum=fib(20,memo);
	cout<<"The result is: "<<fibNum<<endl; // 6765
	for(size_t i=0;i<21;i++){
		cout<<memo[i]<<" "; // 0 1 1 2 3 5 8 13 21 34 55 89 144 
	}                       //233 377 610 987 1597 2584 4181 6765

	cout<<endl;
}