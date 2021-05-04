#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll n, ll e, ll h, ll a, ll b, ll c){
    //initialisig result to max value
    ll res= 1e15;
    ll temp;
    if(n<=0){
        //when there are no orders
        return 0;
    }

    if(2*n <= e){
        //condition for all the orders are omlette
        //1 omlette = 2 eggs
        //so n omlette requires at least 2*n eggs
        res= min(res, n*a); //cost of n omlette will be n*a, where a is the cost of 1 omlette
    }
    if(3*n <= h){
        //condition for all the orders are milkshake
        //1 shake = 3 choc bar
        //so n shake requires at least 3*n bars
        res= min(res, n*b);     //cost of n shakes will be n*b, where b is the cost of 1 shake
    }
    if((n <= e) && (n <= h)){
        //condition for all the orders are choclate cake
        //1 cake = 1 egg and 1 choc bar
        //so n cake requires at least n eggs and n bars
        res= min(res, n*c); //cost of n cakes will be n*c, where c is the cost of 1 cake
    }

    
    if(((h-n)/2 >= 1) && ((h-n)/2 >= n-e)){  //1 <= (n-e) <= x <=(h-n)/2 
        if(b-c<0){
            temp= min(n-1, (h-n)/2);
            res= min(res, temp*(b-c) + n*c);
        }
        else{
            temp= max((ll)1, n-e);
            res= min(res, temp*(b-c) + n*c);
        }
    }

    if((e/2 >= 1) && (e/2 >= (3*n-h+2)/3 )){   //1 <= (3*n-h+2)/3 <= x <= e/2
        if(a-b<0){
            temp= min(n-1, e/2);
            res= min(res, temp*(a-b)+ n*b);
        }
        else{
            temp= max((ll)1, (3*n-h+2)/3);
            res= min(res, temp*(a-b)+ n*b);
        }
    }

    if((e-n >= 1) && (e-n >= n-h) ){  //1<= (n-h) <= x <= (e-h)
        if(a-c<0){
            temp= min(n-1 , e-n);
            res= min(res, temp*(a-c) + n*c);
        }
        else{
            temp= max((ll)1, n-h);
            res= min(res, temp*(a-c) + n*c);
        }
    }

    if((n>=3) && (e>=3) && (h>=4)){
        res= min(res, a+b+c+solve(n-3, e-3, h-4, a,b,c));
    }

    return res;
}

int main(){
    int test_case;
    cin>>test_case;

    while(test_case--){
        ll n,e,h,a,b,c;
        cin>>n>>e>>h>>a>>b>>c;
        ll ans= solve(n,e,h,a,b,c);

        if(ans==1e15){
            cout<<"-1"<<endl;
        }
        else{
            cout<<ans<<endl;
        }

    }
    return 0;
}


