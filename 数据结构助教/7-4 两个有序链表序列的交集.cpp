#include<iostream>
using namespace std;
typedef struct Link* link;
struct Link{
    int x;
    link next;
    Link(int x){
        this->next = NULL;
        this->x = x;

    }
};
link read(){
    int t;
    link head = new Link(0);
    link last = head;
    while(cin>>t,t != -1){
        link tmp = new Link(t);

        last->next = tmp;
        last = last->next;
    }
    return head;

}
int main()
{
    link l1 = read();
    link l2 = read();
    link p = l1->next;
    link q = l2->next;
    int flag = 0;
    while( p && q){
        if( p->x == q->x ){
            if(flag)
                cout<<" ";
            flag = 1;
            cout<<p->x;
            p = p->next;
            q = q->next;
        }else if( p->x < q->x){
            p = p->next;
        }else{
            q = q->next;
        }
    }
    if(!flag)
        cout<<"NULL"<<endl;


    return 0;
}
