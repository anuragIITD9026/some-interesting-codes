#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};

typedef struct node node;
void display(node *head)
{
    node *temp;
    temp=head;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int search(node *head,int target)
{
    node *temp=head;
    while(temp!=nullptr)
    {
        if(temp->data==target)
        {
            return 1;
        }
        else{temp=temp->next;}
    }
    return 0;
}
void insertatend(node *head,int data)
{
    node *temp=head,*newnode;
    newnode->data=data;
    newnode->next=nullptr;
    while(temp->next!=nullptr)
    {
        temp=temp->next
        ;
    }
    temp->next=newnode;
    return;
    
}
void insertatgivennode(node *head,int data,int target)
{
    cout<<"hello";
    node *temp=head,*newnode;
    newnode=new node;
    newnode->data=data;
    newnode->next=nullptr;
    
    while(temp->data!=target)
    {
        temp=temp->next;
    }
    
    newnode->next=temp->next;
    temp->next=newnode;
    return;
}
void deleteatfront(node *head)
{
    if(head==nullptr)
    {
        cout<<"nothing is here to delete";
        return ;
    }
    node *temp=head;
    head=temp->next;
    free(temp);
}
void deleteatend(node *head)
{
    if(head==nullptr)
    {
        cout<<"nothing is here to delete";
        return ;
    }
    node *temp=head,*del;
    while(temp->next->next!=nullptr)
    {
        temp=temp->next;
    }
    del=temp->next;
    free(del);
    temp->next=nullptr;
}
void deleteatanyposition(node *head,int position)
{
    if(head==nullptr)
    {
        cout<<"there is nothing to delete here";
        return ;
    }
    node *current=head,*previous=nullptr;
    int count=0;
    while(current!=nullptr&&count<position)
    {
        previous=current;
        current=current->next;
        count++;

    }
    if(count!=position)
    {
        cout<<" position not found";
        return ;
    }
    previous->next=current->next;
    free(current);
    return ;
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
            current =newnode;
        }
        else{
            current->next=newnode;
            current=newnode;
        }
    }
   // display(start);
    cout<<endl;
    // cout<<search(start,5);
    // insertatend(start,5);
    display(start);
    cout<<endl;
    insertatgivennode(start,5,3);
    display(start);



    return 0;
}
