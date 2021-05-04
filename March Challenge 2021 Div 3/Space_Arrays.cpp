#include<bits/stdc++.h>
using namespace std;

int main(){
    int test_case;
    cin>>test_case;

    while(test_case){
        int n;
        cin>>n;

        int a[n];
        for(int i=0; i<n;i++){
            cin>>a[i];
        }
        sort(a, a+n);

        bool flag=false;
        int diff;
        int sum=0;
        for(int i=0; i<n; i++){
            if(a[i]>(i+1)){
                flag=true;
                break;
            }
            diff=a[i]-(i+1);
            sum+=diff;
        }
        if(flag){
            cout<<"Second"<<endl;
        }
        else{
            if(sum%2!=0){
                cout<<"First"<<endl;
            }
            else{
                cout<<"Second"<<endl;
            }
        }

        test_case--;
    }
    return 0;
}