#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

typedef struct node node;
void deletefirstnodefromcircular(node *&head)
{
    
    if(head==nullptr)
    {
        cout<<"nothing is here to delete";
        return ;
    }
    node *tmp=head,*temp=head;
    while(temp->next!=tmp)
    {
        temp=temp->next;
    }
    temp->next=tmp->next;
    head=tmp->next;
    delete tmp;

}
void deletelastnodefromcircular(node *&head)
{
    if(head==nullptr)
    {
        cout<<"nothing to delete";
        return;
    }
    node *current=head,*previous=nullptr;
    while(current->next->next!=head)
    {
        current=current->next;
    }
    previous=current;
    current=current->next;
    previous->next=head;
    delete current;
    return;

}


void display(node *head)
{
    if(head==nullptr)
    {
        cout<<"nothing to display";
        return;
    }
    // cout<<"hello";
    node *temp=head;
    // cout<<"1hello";
    
    while(temp->next!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    // cout<<"3hello";
    cout<<temp->data;
    return;
}
int main()
{
node *start=nullptr,*newnode,*current;
    
    int choice=1,i=0;
    while(i<10)
    {
        i++;
        newnode = new node;
        cout<<"enter the data in this node: ";
        cin>>newnode->data;
        // cout<<"do you want to enter more data(0/1): ";
        // int ch;
        // cin>>ch;
        // choice=ch;
        newnode->next=NULL;
        if(start==nullptr)
        {
            start=newnode;
            newnode->next=start;
            current =newnode;
            
        }
        else{
            current->next=newnode;
            newnode->next=start;
            current=newnode;
            
        }
    }
    display(start);
    deletefirstnodefromcircular(start);
    cout<<endl;
    display(start);
    cout<<endl;
    deletelastnodefromcircular(start);
    display(start);
    cout<<endl;
    return 0;
}

