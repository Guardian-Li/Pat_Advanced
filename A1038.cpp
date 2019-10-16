#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(const string &a ,const string &b){
    return a + b < b + a;



}
int main()
{
    vector<string> sp;
    string s;
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        int n;
        cin>>n;
        s = to_string(n);
        sp.push_back(s);
    }


    sort(sp.begin(),sp.end(),cmp);
    string res;
    for(int i=0; i<sp.size(); ++i){
        res += sp[i];
    }
    int flag = 0;
    int i=0;
    while(i < res.length()){
        if(res[i] != '0'){
            flag = 1;
        }
        if(flag){
            cout<<res[i];
        }
        i++;
    }
    if(flag == 0)
        cout<<"0"<<endl;
    cout<<endl;
    return 0;

}
