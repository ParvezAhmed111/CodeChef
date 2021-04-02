#include<bits/stdc++.h>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2){
    return p1.first<p2.first;
}

int main(){
    
    int test_case;
    cin>>test_case;

    while(test_case){

        int n; cin>>n;

        int element;
        vector <int> weight;
        for(int i=0; i<n; i++){
            cin>>element;
            weight.push_back(element);
        }
        vector <int> length;
        for(int i=0; i<n; i++){
            cin>>element;
            length.push_back(element);
        }

        vector <pair<int, int>> index;
        for(int i=0; i<n; i++){
            index.push_back(make_pair(weight[i], i+1));
        }

        sort(index.begin(), index.end(), myCompare);

        // for(int i=0; i<index.size(); i++){
        //     cout<<index[i].second<<endl;
        //     cout<<index[i].first<<endl;
        // }

        int tempPrev= index[0].second;
        int jump=0;


        for(int i=1; i<n; i++){
            int temp= index[i].second;
            int x=temp;
            // cout<<"tempPrev- "<<tempPrev<<" "<<"temp- "<<temp<<endl;


            while(tempPrev>=temp){
                // cout<<"length[temp-1] "<<length[x-1]<<endl;
                temp=temp+length[x-1];
                // cout<<"temp "<<temp<<endl;
                
                jump++;
                // cout<<"Jump "<<jump<<" "<<endl;   
            }

            tempPrev=temp;
        }
        cout<<jump<<endl;

        test_case--;
    }

    return 0;
}