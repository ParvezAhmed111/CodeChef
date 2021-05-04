#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll N;
    cin>>N;
    ll H;
    cin>>H;
    ll x;
    cin>>x;

    ll arr[N];
    for(ll i=0; i<N; i++){
        cin>>arr[i];
    }

    bool flag=false;

    for(ll i=0; i<N; i++){
        if((x+arr[i]>=H)){
            flag=true;
        }
    }

    if(flag){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}