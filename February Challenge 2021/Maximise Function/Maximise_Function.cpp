#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int test_case;
    cin>>test_case;

    while(test_case>0){

        long long int n;
        cin>>n;
        long long int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }

        long long Max= INT_MIN;
        long long Min= INT_MAX;
        for(int i=0; i<n; i++){
            Max=max(Max, arr[i]);
            Min=min(Min, arr[i]);
        }
        
        long long ans=2*abs(Max-Min);

        cout<<ans<<endl;

        test_case--;
    }



    return 0;
}