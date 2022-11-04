#include<iostream>
#include<vector>
using namespace std;
int selectKMax(int s, vector<int> A[]){
    int k = 0;
    int m = A[0];
    int count = A[0]; 
    int ans = 0 ; 
    while(++k < A.size()){
        if(A[k] != m )
            m = A[k];
        else{
            count += A[k];
            if(count == s){
                ans = max(ans ,s / count);
            }
        }
    }
    return  ans;
}

int main(){
    vector<int> A = {1,1,2,1,1,1,2,1};
    int s  = 3;
    int ans  = selectKMax(s, A);
    cout<<ans<<endl;
    return 0 ;
}