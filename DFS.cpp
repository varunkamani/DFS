#include<iostream>
using namespace std;
struct node{
    char data;
    struct node *next;
    
};
struct vnode{
    struct node *head;
    char data;
    int visit;
};
class graph{
public:
    vnode *vertex;
    int n;
   
    graph(int n){
        this->n=n;
        vertex = new vnode[n];
        for(int i=0;i<n;i++){
            vertex[i].head=NULL;
            vertex[i].visit=0;
             }
    }
    void addedge(char a,char b){
        int flag=0;
        for(int i=0;i<n;i++){
            if(vertex[i].data==a){
                node *newnode = new node();
                newnode->data=b;
                newnode->next=vertex[i].head;
                vertex[i].head=newnode;
                flag+=1;
                }
            if(vertex[i].data==b){
                node *newnode = new node();
                newnode->data=a;
                newnode->next=vertex[i].head;
                vertex[i].head=newnode;
                flag+=1;
            }
            if(flag==2){
                break;
            } 
        }
     }
    void printgraph(){   //this function will print adjacency list representation of graph
        node *newnode;
        for(int i=0;i<n;i++){
            cout<<"Adjacent of "<<vertex[i].data<<" is : ";
            
            newnode=vertex[i].head;
            while(newnode){
                cout<<newnode->data<<" ";
                newnode=newnode->next;
            }
            cout<<"\n";
        }
    }
    bool isVisted(char data){
        for(int i=0;i<n;i++){
            if(vertex[i].data==data && vertex[i].visit==0){
                return false;
            }
        }
        return true;
    }
    void DFS(char a){
        node *newnode;
        for(int i=0;i<n;i++){
            if(vertex[i].data==a){
                if(vertex[i].visit==0){
                    vertex[i].visit=1;
                    cout<<vertex[i].data<<" ";
                    newnode=vertex[i].head;
                while(newnode!=NULL){
                    if(!isVisted(newnode->data)){
                        DFS(vertex[i].data);
                    }
                    newnode=newnode->next;
                }
                }
                break;
            }
        }
    }
    
};
int main(){
    cout<<"How many vertexes : ";
    int n;
    char x,y;
    cin>>n;
    graph gh(n);
    for(int i=0;i<n;i++){
        cout<<"Vertex "<<i+1<<" value : ";
        cin>>gh.vertex[i].data;
    }
    int c;
    c=1;
    while(c){
        
        cout<<"Two element to add edge : ";
        cin>>x>>y;
        gh.addedge(x,y);
        cout<<"Want to add ?(1/0) "; //1 for "yes" and 0 for "no".
        cin>>c;
    }
    gh.printgraph();
    char temp;
    cout<<"Character for DFS : ";
    cin>>temp;
    gh.DFS(temp);
    return 0;
}
