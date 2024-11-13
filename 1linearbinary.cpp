#include<iostream>
using namespace std;

int linear(int a[],int s, int n){
    for(int i=0; i<s; i++){
        if(a[i]==n){
            return i;
        }
        else{
            return -1;
        }
    }
}

int binary(int a[], int l ,int r, int n){
    if(l<r){
        int m= (l+r)/2;
        if(a[m]==n){
            return m;
        }
        else if(a[m]>n){
            binary(a,l,m-1,n);
        }
        else{
            binary(a,m+1,r,n);
        }
    }
    else{
        return -1;
    }
}
