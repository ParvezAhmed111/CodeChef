#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll test_case;
    cin>>test_case;

    while(test_case>0){
        ll N, K;
        cin>>N;
        cin>>K;
        
        
        if(K!=0){
            if(N>=K){
                cout<<N%K<<endl;
            }
            else{
                cout<<N<<endl;
            }

        }
        else{
            cout<<N<<endl;
        }

        test_case--;
    }
    return 0;
}