#include<bits/stdc++.h>
using namespace std;

int main(){

    int a[10];
    for(int i=0; i<10; i++){
        cin>>a[i];
    }

    int prob;
    cin>>prob;
    int count=0;
    int zero_count=0;

    for(int i=9; i>=0; i--){
        a[i]=prob-a[i];
        prob=a[i];
        
        if(prob<0){
            break;
        }
        count++;
    }
    cout<<10-count<<endl;
 

    return 0;
}