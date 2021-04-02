#include<iostream>
#include<climits>
using namespace std;

int main(){
     int n;
     cin>>n;

    int MAX= INT_MIN;
     for(int i=1; i<=10; i++){
         if(n%i==0){
            //  cout<<i<<" ";
            MAX=max(i, MAX);
         }
     }
     cout<<MAX<<endl;

    return 0;
}