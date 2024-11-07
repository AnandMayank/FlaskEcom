#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--){
	    int N,X;
	    cin>>N>>X;
	    int count_e=0;
	   int count_o=0;
	    for ( int i=1; i<=N;i++){
	        if (i%2==0){
	            count_e++;
	        }
	        else{
	            count_o++;
	        }
	        
	    }
	    if (X%2==0){
	        cout<<(count_e-1)<<endl;
	    }
	    else{
	        cout<<(count_o-1)<<endl;
	    }
	}

}
