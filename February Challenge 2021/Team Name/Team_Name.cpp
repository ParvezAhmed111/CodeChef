#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll mycount(vector<string> u, vector<string> v ){
    set<string> s(u.begin(), u.end());
    
    ll temp=0;
    for(auto& el: v){
        if(s.find(el) != s.end()){
            temp++;
        }
    }
    return temp;
}

int main(){
    int test_case;
    cin>>test_case;

    while(test_case>0){
        
        int n; cin>>n;
        string elements;
        unordered_map<string, vector<string> > word;
        for(int i= 0; i<n; i++){
            cin>>elements;
            if(elements.length()>0){
                word[elements.substr(1)].push_back(elements.substr(0,1));
            }
        }

        ll result=0;
        for(auto& el:word){
            for(auto& el2: word){
                if(el.first != el2.first){
                    // cout<<el.first<<" "<<el2.first<<endl;
                    // for(auto i:el2.second){
                    //     cout<<i<<" ";
                    // }cout<<endl;
                    ll temp= mycount(el.second, el2.second);
                    // cout<<"Temp is "<<temp<<endl;
                    result+=(el.second.size()-temp)*(el2.second.size()-temp);
                    // cout<<"Ans "<<ans<<endl;
                }
            }
        }
        
        cout<<result<<endl;

        test_case--;
    }
    return 0;
}






// #include<bits/stdc++.h>
// #define ll long long int
// using namespace std;

// int main(){

//     ll test_case;
//     cin>>test_case;

//     while(test_case){
        
//         ll n; cin>>n;
    
//         string elements;
//         vector <string> word;
//         vector <string> uniqueHead;  // sort head body to find unique elements
//         vector <string> uniqueBody;  // sort head body to find unique elements

//         for(ll i=0; i<n; i++){
//             cin>>elements;
//             transform(elements.begin(), elements.end(), elements.begin(),::tolower);
//             word.push_back(elements);
//             uniqueHead.push_back(elements.substr(0,1));
//             uniqueBody.push_back(elements.substr(1,20));
//         }
    
      
//         vector <string> garbage;
//         vector <string> notfunnywords;
//         //for getting all possible words (CARTESIAN PRODUCT)
//         vector <string> newWords(uniqueHead.size() * uniqueBody.size());	
//         for(size_t i = 0, s = uniqueBody.size(); i < newWords.size(); ++i){
//             newWords[i] = uniqueHead[i/s] +uniqueBody[i%s];

//             if(find(word.begin(), word.end(), newWords[i])!=word.end()){
//                 garbage.push_back(newWords[i]);
//             }
//             else{
//                 if(find(notfunnywords.begin(), notfunnywords.end(), newWords[i]) != notfunnywords.end()){
//                     garbage.push_back(newWords[i]);
//                 }
//                 else{
//                     notfunnywords.push_back(newWords[i]);
//                 }
//             }
//         }

//         vector <string> notfunnywords_head;
//         vector <string> notfunnywords_body;
//         for(ll i=0; i<notfunnywords.size(); i++){
//             notfunnywords_head.push_back(notfunnywords[i].substr(0,1));
//             notfunnywords_body.push_back(notfunnywords[i].substr(1,20));
//         }

//         int count=0;
//         vector <string> newWords1(notfunnywords_head.size() * notfunnywords_body.size());
//         for(size_t i=0, s=notfunnywords_body.size(); i<newWords1.size(); ++i){
//             newWords1[i]= notfunnywords_head[i/s] + notfunnywords_body[i%s];
//             if(find(word.begin(), word.end(), newWords1[i])!=word.end()){
//                 count++;
//             }
//         }

//         cout<<count<<endl;

        

//         test_case--;
//     }
//     return 0;
// }