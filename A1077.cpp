#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;
int judge(string a, string b){
    for(int i=0; i < a.size() && i < b.size(); ++i){
        if(a[i] != b[i])
            return i ;
    }
    return min(a.size(), b.size());

}
int main()
{
    int n;
    cin>>n;
    cin.ignore();
    string a;
    getline(cin,a);
    reverse(a.begin(),a.end());
    int flag = 0;
    int len = INT_MAX;
    for(int i=0; i < n-1; ++i){
        string b;
        getline(cin,b);
        reverse(b.begin(),b.end());
        int t = judge(a,b);
        len = min(len,t);
       // cout<<t<<endl;
        if( len == 0){
            flag = 1;
        }
    }
    if(flag ){
        cout<<"nai"<<endl;
    }else{
        string res = a.substr(0,len);
        reverse(res.begin(),res.end());
        cout<<res<<endl;
    }

}
