#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll orient(pair <ll, ll> p, pair <ll, ll> q, pair <ll, ll> r ){
    // if r lies on the right side of ray pq then orient function return 1
    // if r lies on the left side of ray pq then orient function return 2
    // if r lies on the ray pq then orient function return 0

    ll val= (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);

    if(val==0) return 0;    //points are collinear 
    if(val>0) return 1;  

    return 2;
}

pair <ll, ll> secondTop (stack<pair<ll, ll>> &s){
    // to access the second top element in the stack
    pair<ll, ll> p = s.top();
    s.pop();
    pair<ll, ll> r = s.top();
    s.push(p);

    return r; 
}

// ll max_val(ll a, ll b){
//     if(a>b) return a;

//     return b;
// }

ll abs1(ll a, ll b){
    if (a>b) return a-b;

    return b-a;
}



int main(){
    ll test_case;
    cin>>test_case;

    while(test_case--){

        ll n;  //total o of points/section
        cin>>n;

        vector <pair<ll, ll>> vec; //sorting all points
        for(ll i=0; i<n; i++){
            ll temp;
            cin>>temp;
            vec.push_back(make_pair(i+1, temp));
        }

        stack <pair<ll, ll>> st;
        st.push(vec[0]);
        st.push(vec[1]);

        for(ll i=2; i<n; i++){
            if(st.size()<2){
                //if the stack size is less than 2, we simply push the points to the stack
                st.push(vec[i]);
            }
            else{
                if(orient(secondTop(st), st.top(), vec[i]) == 1){
                    // if the orientation of the ray is clockwise the we push the current point into the stack
                    st.push(vec[i]);
                }
                else{
                    // while the orientation of the ray is anti-clockwise and stack size is greater than 2, we keep on popping the stack elements
                    while(st.size()>=2 && orient(secondTop(st), st.top(), vec[i]) != 1){
                        st.pop();
                    }
                    st.push(vec[i]);
                }
            }
        }

        ll ans=1;
        //minimum answer in any given case will be 1

        while(st.size() >= 2){
            //finding the maximum difference between the adjacent ponts in the stack
            pair<ll, ll> pt= st.top();
            st.pop();
            pair<ll, ll> qt= st.top();
            ans= max(ans, abs1(pt.first, qt.first));
        }
        cout<<ans<<endl;
    }
    return 0;
}
















// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// bool pointIsOnLine(int m, int c, int x, int y) 
// { 
//     if (y == ((m * x) + c)) 
//         return true; 
  
//     return false; 
// }

// void solve(vector<pair<int, int>> arr, ll n){
//     // for(auto &i: arr){
//     //     cout<<i.first<<" "<<i.second<<endl;
//     // }

//     vector <pair<int, int>> idx;
//     ll i;

//     for(ll i=0; i<n; i++){
//         for (ll j=n; j<0; j--){
//             for(int k=i; k<j; k++){
//                 int m=(arr[j].second - arr[i].second) / (arr[j].first- arr[i].first);
//                 int c=arr[i].second - m*arr[i].first; 
//                 if(pointIsOnLine(m,c,arr[i].first, arr[i].second)){
//                     continue;
//                 }
//                 else{
//                     idx.push_back(make_pair(arr[i].second, arr[j].second));
//                 }
//             }
//         }
//     }

//     for(auto &i: idx){
//         cout<<i.first<<" "<<i.second<<endl;
//     }

//     // int MIN= INT_MIN;
//     // for(int i=0; i<n; i++){
//     //     int diff=(idx[i]-idx[i-1]);
//     //     MIN= min(MIN, diff);
//     // }

//     // cout<<MIN<<endl;


// }

// int main(){
//     ll test_case;
//     cin>>test_case;

//     while(test_case--){

//         ll n; cin>>n;

//         vector <pair <int, int>> arr;
//         for(ll i=0; i<n; i++){
//             int ele;
//             cin>>ele;
//             arr.push_back(make_pair(i+1,ele));
//         }
//         // for(auto &i: arr){
//         //     cout<<i.first<<" "<<i.second<<endl;

//         // }
//         solve( arr, n);
//     }
//     return 0;
// }