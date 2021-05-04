#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll test_case;
    cin>>test_case;

    while(test_case--){
        ll n; cin>>n;
        ll sum=0;
        if(n==1){
            sum+=20;
        }
        else if(n==2){
            sum+=36;
        }
        else if(n==3){
            sum+=51;
        }
        else{
            sum=(n/4)*44;
            if(n%4==0){
                sum+=16;
            }
            else if(n%4==1){
                sum+=32;
            }
            else if(n%4==2){
                sum+=44;
            }
            else if(n%4==3){
                sum+=55;
            }
        }
        cout<<sum<<endl;

    }
    return 0;
}