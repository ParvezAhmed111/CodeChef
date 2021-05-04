#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define cmpl complex<long double>

using namespace std;

bool isSubSeq(string s1, string s2){
    int j=0;
    for(int i=0; i<s2.size(); i++){
        if(s2[i]==s1[j]) j++;
        if(j==s1.size()) return true;
    }
    return false;
}

string printBin(string str){
    queue<string> q;
    q.push("1");
    while(true){
        string s1= q.front();
        q.pop();
        if(isSubSeq(s1,str)==false) return s1;

        string s2=s1;
        q.push(s1.append("0"));
        q.push(s2.append("1"));
    }
}

int main(){
    ll test_case;
    cin>>test_case;

    while(test_case--){
        string str; cin>>str;

        bool flag=false;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='0') flag=true;
        }

        if(flag==0) cout<<"0"<<endl;
        else cout<<printBin(str)<<endl;
    }
    return 0;
}