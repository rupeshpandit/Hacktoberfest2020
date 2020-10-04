#include<stdlib.h>
#include<iostream>
using namespace std;
//#ifndef Queue_h
#define Queue_h
struct node
{
    int data;
    struct node *next;
}  *front=NULL ,*rear=NULL;

void enqueue(int x)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
        cout<<"queue is full ";
    else
        {
         t->data=x;
         t->next=NULL;
         if(front==NULL)
            front=rear=t;
              //rear=t;
         else
            {
             rear->next=t;
             rear=t;
            }
        }
}

int dequeue()
{
    int x=-1;
    struct node *t;
    if(front==NULL)
        cout<<"queue is empty";
    else
        {
         x=front->data;
         t=front;
         front=front->next;
         delete(t);
        }
        return x;
}

int isempty()
{

    return front==NULL;
}

//#include<iostream>
//#include<queue.h>
//using namespace std;
void BFS(int g[][7],int start,int n)
{
    int i=start,j;
    int visited[7]={0};
    cout<<i<<" ";
    visited[i]=1;
    enqueue(i);
    while(!isempty())
     {
        i=dequeue();
        for(j=1;j<n;j++)
        {
            if(g[i][j]==1 && visited[j]==0)
            {
                cout<<j<<" ";
                visited[j]=1;
                enqueue(j);
            }
        }
      }
}

void DFS(int g[][7],int start,int n)
{
    static int visited[7]={0};
    int j;
    if(visited[start]==0)
    {
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++)
        {
            if(g[start][j]==1 && visited[j]==0)
            DFS(g,j,n);
        }
    }
}

int main()
{
    int g[7][7]={{0,0,0,0,0,0,0},
                 {0,0,1,1,0,0,0},
                 {0,1,0,0,1,0,0},
                 {0,1,0,0,1,0,0},
                 {0,0,1,1,0,1,1},
                 {0,0,0,0,1,0,0},
                 {0,0,0,0,1,0,0}};
    //BFS(g,1,7);
    DFS(g,1,7);
    return 0;
}

