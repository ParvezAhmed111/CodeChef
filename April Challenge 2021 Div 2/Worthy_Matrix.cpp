#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    ll test_case;
    cin>>test_case;

    while(test_case--){
        ll row, col, k;
        cin>>row>>col>>k;

        ll dp[row+1][col+1];

        memset(dp, 0, sizeof(dp));

        for(ll i=1; i<=row; i++){
            for(ll j=1; j<=col; j++){
                cin>>dp[i][j];
            }
        }

        //row wise sum
        for(ll i=1; i<=row; i++){
            for(ll j=1; j<=col; j++){
                dp[i][j]+=dp[i][j-1];
            }
        }
        //column wise sum
        for(ll j=1; j<=col; j++){
            for(ll i=1; i<=row; i++){
                dp[i][j]+=dp[i-1][j];
            }
        }

        ll ans=0;

        for(ll side=1; side<=row; side++){
            //side = length of submatrix, side iterates from 1 to n
            for(ll i=1; i<=row-side+1; i++){
                //iterating row wise to find the left most submatrix of size (side x size) having top left
                //element in the rows

                ll low=1;
                ll high=col-side+1;
                ll mid, p;
                ll flag=0;

                while(low<=high){
                    //bimary search along the row
                    mid=(high+low)/2;

                    //calculating the sum of submatrices whose top left element is a[i][mid]
                    ll sum= dp[i+side-1][mid+side-1] - dp[i+side-1][mid-1] - dp[i-1][mid+side-1] + dp[i-1][mid-1];

                    //if the average of current submatrix is greater than or equal to K, then all the submatrices which are
                    //right to the current submatrix also have greater than or equal to k
                    if(sum>=k*side*side){
                        high=mid-1;
                        p=mid;
                        flag=1;
                        //to make sure that there exist atleast one matrix
                    }
                    else{
                        low=mid+1;
                    }
                }
                if(flag==1){
                    ans+=(col-side-p+2);
                }
            }
        }
            cout<<ans<<endl;

    }
    return 0;
}