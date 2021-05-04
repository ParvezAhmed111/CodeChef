#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll test_case;
    cin>>test_case;

    while(test_case>0){
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
        

        test_case--;
    }
    return 0;
}