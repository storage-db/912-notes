#include<iostream>
using namespace std;

int searchK(int A[],int lo,int hi) {
    int left = lo,right = hi;
    while(lo < hi ){
        int mi = (lo + hi) >> 1;
        if(mi ==  left)  return lo;
        if(mi + 1 == right)  return mi;
        if(  A[mi -1] < A[mi]  && A[mi] > A[mi + 1])
            return mi;
        else if(A[mi- 1] < A[mi]  && A[mi] < A[mi + 1]) //A[mid]和左右按升序
            return searchK(A,mi + 1 ,hi);
        else if(A[mi +1] < A[mi]  && A[mi] < A[mi - 1]) //A[mid]和左右按降序
            return searchK(A,lo,mi); 
    }
}

int main(){
    int a1[] = {1,2,3,4,5,6,7};
    int a2[] = {7,6,5,4,3,2,1};
    int a3[] = {1,2,3,4,7,6,5};
    int k1 = searchK(a1, 0, 7);
    cout<<"k1="<<k1<<endl;
    int k2 = searchK(a2, 0, 7);
    cout<<"k2="<<k2<<endl;
    int k3 = searchK(a3, 0, 7);
    cout<<"k3="<<k3<<endl;
    return 0;
}