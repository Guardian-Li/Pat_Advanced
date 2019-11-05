#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<cmath>
using namespace std;
typedef pair<string, int> psi;
const string eight = "08:00:00";


int to_int(string s){
    int hour = (s[0]-'0')*10 + s[1] -'0';
    int m = (s[3]-'0')*10 + s[4] -'0';
    int sec = (s[6]-'0')*10 + s[7] -'0';
    sec = hour*60*60+m*60+sec;
    return sec;
}


int main()
{
    int n,k;
    cin>>n>>k;
    vector<psi> p(n);
    for(int i=0; i<n; ++i)
    {
        cin>>p[i].first>>p[i].second;
        if(p[i].second > 60)
            p[i].second = 60;
    }
    sort(p.begin(),p.end());
   /* for(int i=0; i<n; ++i){
        cout<<p[i].first<<endl;
    }
    */
    int sum = 0;
    priority_queue< int ,vector<int> ,greater<int> > pq;
    for(int i=0; i<k ; ++i){
        pq.push(to_int(eight));
    }
    //cout<<to_int(eight)<<endl;
    int cnt = 0;
    for(int i=0; i<n; ++i){
        if(p[i].first >= "17:00:01" || pq.top() >= to_int("17:00:00"))
            continue;
        int t = pq.top();
        if(to_int(p[i].first) < to_int(eight))
            sum = sum + abs(to_int(p[i].first)-t);
        else if(to_int(p[i].first) - t < 0 )
            sum = sum + abs(to_int(p[i].first)-t);

        pq.pop();
        pq.push(max(to_int(p[i].first),t) + p[i].second*60);
        cnt++;
    }
    printf("%.1f",sum*1.0 / 60 /cnt);
    return 0;

}
