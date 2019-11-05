#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> p;
int m,n;
bool judge()
{
    stack<int> st;
    int i=0;
    int cnt = 1;
    while( i <= p.size())
    {
        if(!st.empty() && p[i] > st.top())
        {
          //  cout<<"2"<<endl;
            return false;
        }
        st.push(p[i]);
        //cout<<p[i]<<endl;
        i++;

        while(  !st.empty() && cnt == st.top())
        {
            //cout<<" "<<cnt<<" "<<st.top()<<endl;
            //cout<<st.size()<<endl;
            cnt++;
            st.pop();
        }
        if(st.size() > n )
        {
            return false;
        }
    }

    return true;

}
int main()
{

    int t;
    cin>>m>>n>>t;
    for(int i=0; i<t; ++i)
    {
        for(int j=0; j < m; ++j)
        {
            int ti;
            cin>>ti;
            p.push_back(ti);
        }
        if(judge())
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        p.clear();
    }
    return 0;

}
