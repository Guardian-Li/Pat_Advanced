#include<stack>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    queue<int> a;
    queue<int> b;
    int n;
    cin>>n;
    int flag = 0;
    for(int i=0; i<n; ++i){
        int t;
        cin>>t;
        if( t & 1){
            a.push(t);
        }else{
            b.push(t);
        }
        if( a.size( ) == 2 && !b.empty()){
            if(flag)
            cout<<" ";
            cout<<a.front()<<" ";
            a.pop();
            cout<<a.front();
            a.pop();
            cout<<" "<<b.front();
            b.pop();
            flag = 1;
        }
    }
    while(!a.empty() || !b.empty()){
       for(int i=0; i<2; ++i){
         if(!a.empty()){
            if(flag)
                cout<<" ";
            cout<<a.front();
            a.pop();
        }
       }
       if(!b.empty()){
        if(flag)
            cout<<" ";
        cout<<b.front();
        b.pop();
       }
    }

    return 0;
}
