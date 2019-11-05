#include<stdio.h>
#include<malloc.h>
typedef struct Link* link;
struct Link{
    int x;
    link next;
};


int main()
{
    int n;
    scanf("%d",&n);
    link head  = (link) malloc(sizeof(struct Link));
    head->next =NULL;
    link last = head;
    for(int i=0; i<n; ++i){
        int t;
        scanf("%d",&t);
        link tlink = (link)malloc(sizeof(struct Link));
        tlink->next = NULL;
        tlink->x = t;
        last->next = tlink;
        last = last->next;
    }
    link p = head->next;
    int flag = 1;
    while( p != NULL){
        if(flag == 1)
            printf("%d",p->x);
        else
            printf(" %d",p->x);
        flag = 0;
        p = p->next;
    }
    return 0;
}
