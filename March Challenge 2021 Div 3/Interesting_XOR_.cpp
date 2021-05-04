#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
    ll c;
    cin>>c;

    ll d=0;
    while((1<<d)<=c){
        d++;
    }

    ll A=(1<<d-1)-1;
    ll sum=(1<<d)-c;
    ll ans=A*(A+sum);
    cout<<ans<<endl;

}

int main(){
    ll test_case;
    cin>>test_case;

    while(test_case){
        solve();

        test_case--;
    }
    return 0;
}