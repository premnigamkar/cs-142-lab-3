#include<iostream>
#include<stdlib.h>
using namespace std;

class Node//Creating Node of the LinkedList
{
public:
    int data;
    Node *nxt;//pointer to the next Node
    Node()//creating a default LinkedList with data as 0 and head NULL
    {
        data=0;
        nxt=NULL;
    }
};

class CircularLinkedList//creating the doubly-LinkedList
{
private:
    Node*head;//the first element of the LinkedList
    Node*tail;//the last element of the LinkedList
    int n;//stores the size of the LinkedList
public:
    //creating an empty LinkedList
    CircularLinkedList(){
    head=NULL;
    tail=NULL;
    n=0;
    }
    //function to add an element to the end of the LinkedList
    void Insert(int x)
    {
        Node*temp=new Node;
        temp->data=x;
        //checking whether the LinkedList is empty
            if(head==NULL){
                head=temp;
                tail=temp;
                tail->nxt=head;
                ++n;//increasing the size by 1
            }
            else{
                tail->nxt=temp;
                tail=temp;
                tail->nxt=head;
                ++n;
            }
    }
    //function to add given element at any given position
    void InsertAt(int x, int y)
    {
        //checking if there are enough elements
        if (y>n+1){
            cout<<endl<<"Not enough nodes."<<endl;
        }
        //same as inserting an element at the end
        else if (y==n+1){
            Insert(x);
        }
        //inserting an element at the begining
        else if (y==1){
            Node *temp=new Node;
            temp->data=x;
            temp->nxt=head;
            head=temp;
            ++n;
        }
        //inserting at any other desired position
        else {
            Node *locate;
            locate=head;
            for (int i=1;i<y-1;i++){
                locate=locate->nxt;
            }
            Node *temp=new Node;
            temp->data=x;
            temp->nxt=locate->nxt;
            locate->nxt=temp;
            ++n;
        }
    }
    //deleting an element from the end of the linkedlist
    void Delete(){
        //checking whether the list is empty
        if(head==NULL){
            cout<<"LinkedList is empty"<<endl;
        }
        else
    {
        Node *locate;//locates the position where the Node is to be inserted
        locate=head;
        while(locate->nxt!=tail){
            locate=locate->nxt;
        }
        delete tail;
        tail=locate;
        locate->nxt=head;
        --n;//
    }
    }
    //function to delete Node at any given position
    void DeleteAt(int y)
    {
        //checking whether the List has enough elements
        if(y>n){
            cout<<endl<<"Not enough nodes."<<endl;
        }
        //this is same as deleting Node from the end
        else if (y==n){
            Delete();
        }
        //deleting from the begining of the list
        else if (y==1){
            delete head;
            head=head->nxt;
            --n;
        }
        //deleting from any other desired position
        else{
            Node *locate;
            locate=head;
            for(int i=1;i<y-1;i++){
                locate=locate->nxt;
            }
            Node *temp;
            temp=locate->nxt;
            locate->nxt=temp->nxt;
            delete temp;
            --n;
        }
    }
    //returns the number of Nodes in the List
    int Count()
    {
        return n;
    }
    //function to display all the elements of the list
    void Display()
    {
        Node *disp;
        disp=head;
        while (disp->nxt!=head){
            cout<<disp->data<<endl;
            disp=disp->nxt;
        }
        cout<<tail->data<<endl;
    }
};
int main(){
    CircularLinkedList List1;
    int s;
    do{
    cout<<"Choose one of the following: \n 1.Insert \n 2.InsertAt \n 3.Delete \n 4.DeleteAt\n 5.Count \n 6.Display \n 7.Exit\n\n";
    cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
    cin>>s;
    switch(s){
case 1:
    cout<<"Enter the element to be added: "<<endl;
        int a;
        cin>>a;
        List1.Insert(a);
        system("CLS");
        break;
case 2:
    system("CLS");
    cout<<"Enter the number to be added and it's position: "<<endl;
    int b,c;
    cin>>b>>c;
    List1.InsertAt(b,c);
    break;
case 3:
    system("CLS");
    List1.Delete();
    break;
case 4:
    system("CLS");
    cout<<"Enter the position of the element to be deleted:"<<endl;
    int d;
    cin>>d;
    List1.DeleteAt(d);
    break;
case 5:
    system("CLS");
    cout<<"The number of Nodes in the LinkedList is: "<<List1.Count()<<endl;
    break;
case 6:
    system("CLS");
    cout<<"The elements of the LinkedList are:"<<endl;
    List1.Display();
    break;
default:
    s=7;
    system("CLS");
    break;
}
}while (s!=7);
return 0;
}
