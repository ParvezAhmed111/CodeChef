#include<bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){
    
    ll test_case;
    cin>>test_case;

    while(test_case){

        string s;
        cin>>s;

        ll count=0;
        for (ll i=0; i<s.size(); i++){
            if(s[i]=='1'){
                count++;
                for(ll j=i+1; j<s.size(); j++){
                    if(s[j]=='1'){
                        i++;
                    }
                    else{
                        break;
                    }
                }
            }
        }

        cout<<count<<endl;


        test_case--;
    }

    return 0;
}

