
// union search   f[fx] = fy maybe fx has many leaves


#include<iostream>
#include<set>
#include<vector>
using namespace std;
const int N = 1000+10;
int f[N];
int n,m,k;
vector<int> u,v;

int find(int x){
    return f[x] == x? f[x] : f[x] = find(f[x]);
}

void init(){

    for(int i=0; i<N; ++i)
        f[i] = i;
}

void merge(int x, int y){
    int fx = find(x);
    int fy = find(y);
    if( fx != fy)
        f[fx] = fy;
}

int getAns(int op){
    init();
    for(int i=0; i<m; ++i){
        if( u[i] == op || v[i] == op)
            continue;
        merge(u[i],v[i]);
    }
    set<int> st;
    for(int i=1; i<= n; ++i){
        if( i == op)
            continue;
        st.insert(find(i));
    }

    return st.size() - 1;

}

int main()
{
    cin>>n>>m>>k;
    u.resize(m);
    v.resize(m);
    for(int i=0; i<m; ++i){
        cin>>u[i]>>v[i];
    }
    for(int i=0; i<k; ++i){
        int t;
        cin>>t;
        cout<<getAns(t)<<endl;

    }
    return 0;






}
