#include<iostream>
#include<string>
#include<set>
#include<vector>
using namespace std;
int main()
{
    set<string> st;
    string s;
    int n,m,k;
    cin>>n>>m>>k;
    vector<string> sv;

    for(int i=0; i<n; ++i){
        cin>>s;
        sv.push_back(s);
    }
    int cnt = 0;
    int i = k - 1;
    while( i < sv.size()){
        if(!st.count(sv[i]))
        {
            st.insert(sv[i]);
            cout<<sv[i]<<endl;
            cnt++;
            i+=m;

        }else{
            i = i + 1;
        }
    }
    if(!cnt){
        cout<<"Keep going..."<<endl;
    }
    return 0;

}
