#include<algorithm>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;
typedef struct stu_ stu;
typedef pair<int,int > pii;
struct stu_{
    string id;
    int g;
};

vector<stu> s;
vector<stu> adv;
vector<stu> base;
vector<stu> top;
map<int , pii> D;

bool cmpa(stu a, stu b){
    return a.g == b.g ? a.id < b.id : a.g > b.g;

}
void A(char rank){
    vector<stu> tmp;
    if(rank == 'A')
        tmp = adv;
    else if( rank == 'B')
        tmp = base;
    else
        tmp = top;
    for(int i=0; i<tmp.size(); ++i){
        cout<<tmp[i].id<<" "<<tmp[i].g<<endl;
    }
    if(tmp.size() == 0)
        cout<<"NA"<<endl;

}

int change(string s){
    int sum = 0;
    for(int i=0; i<s.size(); ++i){
        sum = sum * 10 +s[i]- '0';
    }
    return sum ;

}

void B(int b){
    if(D.find(b) == D.end()){
        cout<<"NA"<<endl;
    }
    else
        cout<<D[b].first<<" "<<D[b].second<<endl;
}

void C(string  b){
    unordered_map<int,int> mp;
    for(int i=0; i< s.size(); ++i){
        string t = s[i].id.substr(4,6);
        if(b == t){
            string test = s[i].id.substr(1,3);
            int dest = change(test);
            //cout<<dest<<endl;
            if(mp.find(dest) != mp.end()){
                mp[dest]++;
            }else{
                mp[dest] = 1;
            }
        }
    }
    vector<pii> p;
    for(auto it = mp.begin(); it != mp.end(); ++it){
        p.push_back(make_pair(it->first,it->second));
    }
    sort(p.begin(),p.end(), [](pii a,pii b)->bool{return a.second == b.second ? a.first < b.first : a.second > b.second;});
    for(auto it = p.begin(); it != p.end(); ++it){
        cout<<it->first<<" "<<it->second<<endl;
    }
    if(p.size() == 0)
        cout<<"NA"<<endl;
}

void Dog(){
    for(int i=0; i<s.size(); ++i){
        string tmp = s[i].id.substr(1,3);
        int tm = change(tmp);
        if(D.find(tm) == D.end())
        {
            D[tm].first = 1;
            D[tm].second = s[i].g;
        }
        else{
            D[tm].first++;
            D[tm].second += s[i].g;
        }
    }




}
int main()
{
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; ++i){
        stu t;
        cin>>t.id>>t.g;
        s.push_back(t);
        if(t.id[0] =='A'){
            adv.push_back(t);
        }else if( t.id[0] == 'B'){
            base.push_back(t);
        }else{
            top.push_back(t);
        }
    }
    sort(adv.begin(),adv.end(),cmpa);
    sort(base.begin(),base.end(),cmpa);
    sort(top.begin(),top.end(),cmpa);
    Dog();
    for(int i=1; i<=m; ++i){
        int a,b;
        cin>>a;
        if( a == 1){
            char c;
            cin>>c;
            cout<<"Case "<<i<<": "<<a<<" "<<c<<endl;
            A(c);
        }else if (a == 2){
            int b;
            cin>>b;
            cout<<"Case "<<i<<": "<<a<<" "<<b<<endl;
            B(b);


        }else if( a == 3){
            string b;
            cin>>b;
            cout<<"Case "<<i<<": "<<a<<" "<<b<<endl;
            C(b);
        }


    }
    return 0;

}
