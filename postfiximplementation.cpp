#include<iostream>
#include<vector>

using namespace std;
char stack[24];
int top=0;
void push(char x)
{
    stack[++top]=x;
}
char pop()
{
    return stack[top--];
}
char Top()
{
    return stack[top];
}
int isEmpty()
{
    return top==0;
}
int isFull()
{
    return top==10;
}


// vector<char> v;
// int top=0;
// int empty()
// {
//     return v.size()==0;
// }
// void push(char x,int top)
// {

// }
int main()
{
    
    int i,j=0;
    char postfix[25];
    string s,v;
    cout<<"Enter the string: ";
    cin>>s;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='('||s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='$'||s[i]=='.')
        {
            push(s[i]);
        }
        else if(s[i]==')')
        {
            while(Top()!='(')
            {
                postfix[j]=pop();
                j++;
            }
            pop();
        }
        else{
            postfix[j]=s[i];
            j++;
        }
    } 
    while(!isEmpty())
    {
        postfix[j]=pop();
        j++;
    }
    postfix[j]='\0';
    for(i=0;(postfix[i])!='\0';i++)
    {
    cout<<postfix[i];
    }


}
