#include<unordered_map>
#include<string>
#include<iostream>
#include<algorithm>
#include<utility>
#include<vector>
using namespace std;

typedef struct student stu;
char p[] = {'A','C','M','E'};
typedef pair<int,char> pic;
struct student{
    string id;
    int c;
    int m;
    int e;
    int a;
    int flag;
    int nm;
    int g[4];

};
vector<stu> st;
bool cmpa(stu &a, stu &b){
    return a.a>b.a;
}

bool cmpm(stu &a, stu &b){
    return a.m>b.m;
}

bool cmpe(stu &a, stu &b){
    return a.e>b.e;
}

bool cmpc(stu &a, stu &b){
    return a.c>b.c;

}

void change(int flag){
    int cnt = 1;
    int index = 0;
    if( 1 < st[0].nm){
        st[0].nm = 1;
        st[0].flag = flag;
    }
    for(int i=1; i<st.size(); ++i){
        if(st[i].g[flag] != st[i-1].g[flag]){
            cnt = cnt + (i-index);
            index = i;
        }
        if(cnt < st[i].nm){
            st[i].nm = cnt;
            st[i].flag = flag;
        }
    }

}


int main()
{
    unordered_map<string,pic> mp;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        string s;
        int c,m,e;
        cin>>s>>c>>m>>e;
        stu tu;
        tu.id = s;
        tu.c = c;
        tu.m = m;
        tu.e = e;
        tu.nm = 9999;
        tu.a = (c+m+e)/3;
        tu.g[0] = tu.a;
        tu.g[1] = c;
        tu.g[2] = m;
        tu.g[3] = e;
        st.push_back(tu);

    }
    sort(st.begin(),st.end(),cmpa);
    change(0);
    sort(st.begin(),st.end(),cmpc);
    change(1);
    sort(st.begin(),st.end(),cmpm);
    change(2);
    sort(st.begin(),st.end(),cmpe);
    change(3);
    for(int i=0; i<st.size(); ++i){
        pic  ic = make_pair(st[i].nm,p[st[i].flag]);
        mp[st[i].id] = ic;
    }
    for(int i=0; i<m; ++i){
        string t;
        cin>>t;
        if(mp.find(t) == mp.end()){
            cout<<"N/A"<<endl;
        }else{
            cout<<mp[t].first<<" "<<mp[t].second<<endl;
        }
    }
    return 0;
}
