#include<bits/stdc++.h>
using namespace std;

int result(int time1, int time2, int inpTime){

    if(inpTime>=time1 && inpTime<=time2){
        return 1; 
    }
    else{
        return 0;
    }
}

int amTime(int hh, int mm){
    if(hh==12){
        return mm;
    }
    return ((hh*100)+mm);
}
int pmTime(int hh, int mm){
    if(hh==12){
        return ((hh*100)+mm);
    }
    return (((12+hh)*100)+mm);
}

int am_pm(string time){
    string am_pm= time.substr(5,2);
    int hh= stoi(time.substr(0,2));
    int mm= stoi(time.substr(3,2));
    int ans;
    if(am_pm=="AM"){
        ans= amTime(hh,mm);
    }
    if(am_pm=="PM"){
        ans= pmTime(hh,mm);
    }

    return ans;
}

int main(){
    
    int test_case;
    cin>>test_case;

    while(test_case>0){

        string t="";
        char c;
        for (int i=0; i<7; i++){
            cin>>c;
            t.push_back(c);
        }

        int inpTime= am_pm(t);
    
        int n;
        cin>>n;
        for(int i=0; i<n; i++){
            string time="";
            char c;
            for (int i=0; i<14; i++){
                cin>>c;
                time.push_back(c);
            }

            int time1= am_pm(time.substr(0,7));
            int time2= am_pm(time.substr(7,7));

            cout<<result(time1, time2, inpTime);
        }
        cout<<endl;   

        test_case--;
    }
    return 0;
}

