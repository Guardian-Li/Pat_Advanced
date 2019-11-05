#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cmath>
using namespace std;
bool prime(int n){
    if( n <= 1)
        return false;
    for(int i=2; i<= sqrt(n); ++i){
        if(n% i ==0)
            return false;
    }
    return true;


}

int main()
{
    vector<string> p;
    map<string,int> mp;
    map<string,int> check;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        string s;
        cin>>s;
        mp[s] = i+1;
        check[s] = 0;
    }

    cin>>n;
    for(int i=0; i<n; ++i){
        string s;
        cin>>s;
        if(mp.find(s) == mp.end()){
            cout<<s<<": Are you kidding?"<<endl;
            continue;
        }
        if(check[s] == 0){

            if(mp[s] == 1){
                cout<<s<<": Mystery Award"<<endl;
            }else if(prime(mp[s])){
                cout<<s<<": Minion"<<endl;
            }else{
                cout<<s<<": Chocolate"<<endl;
            }
            check[s] = 1;
        }else{
             cout<<s<<": Checked"<<endl;
        }
    }
    return 0;
}
