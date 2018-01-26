#include <iostream>
#include<stdlib.h>
using namespace std;

class Node{//Creating Node of the doubly-LinkedList
public:
    int data;
    Node*next;//pointer to the next Node
    Node *previous;//pointer to the previous Node
    Node(){//creating a default LinkedList with data as 0 and head and tail NULL
        data=0;
        next=NULL;
        previous=NULL;
    }
};

class DoublyLinkedLists//creating the doubly-LinkedList
{
private:
    int Size;//stores the size of the LinkedList
    Node *head;//the first element of the LinkedList
    Node *tail;//The last element of the LinkedList
public:
    DoublyLinkedLists(){//creating an empty LinkedList
    Size=0;
    head=NULL;
    tail=NULL;
    }
    void Insert(int x){//function to add an element to the end of the LinkedList
    Node *temp=new Node;
    temp->data=x;

    if (head==NULL){//checking whether the LinkedList is empty
        head=temp;
        tail=temp;
        temp->next=NULL;
        temp->previous=NULL;
        ++Size;//increasing the Size by one
    }
    else {
        tail->next=temp;
        temp->previous=tail;
        temp->next=NULL;
        tail=temp;
        ++Size;
    }
    }
    //function to add given element at any given position
    void InsertAt(int x, int y)
    {
        //checking whether the LinkedList has enough elements
        if (y>Size+1){
            cout<<"Not enough elements."<<endl;
            }
        //this is the same as adding an element to the end of the LinkedList
        else if(y==Size+1){
            Insert(x);
        }
        //Adding an element to at the begining the List
        else if(y==1){
            Node*temp=new Node;
        temp->data=x;
        if (head==NULL){
            head=temp;
            tail=temp;
            temp->next=NULL;
            temp->previous=NULL;
            ++Size;
        }
        else {
            head->previous=temp;
            temp->previous=NULL;
            temp->next=head;
            head=temp;
            ++Size;
        }
        }
        //for any other position
        else {
            Node *temp=new Node;
            temp->data=x;
            Node *locate;//to locate the position at which the Node is to be inserted
            locate=head;
            for (int i=1;i<y-1;i++){
                locate=locate->next;
            }
            temp->next=locate->next;
            temp->previous=locate;
            locate->next=temp;
            ++Size;
        }
    }
    //function to delete Node from the end of the LinkedList
    void Delete(){
    //checking whether the LinkedList is empty
    if(head!=NULL)
    {
        Node *temp=tail;
        (temp->previous)->next=NULL;
        tail=temp->previous;
        delete temp;
        --Size;//decreasing the size by 1
    }
    else
        cout<<"The linkedlist is empty."<<endl;
    }
    //function to delete Node at any given position
    void DeleteAt(int x)
    {
        //checking whether the List has enough elements
        if (x>Size){
            cout<<"Not enough elements"<<endl;
        }
        //this is same as deleting Node from the head
        else if(x==Size){
            Delete();
        }
        //deleting a Node from the begining of the List
        else if(x==1){
        head=head->next;
        (head->next)->previous==NULL;
        --Size;
        }
        //deleting from any other desired position
        else {
            Node *locate=head;//to locate and store the address of the Node to be deleted
            for (int i=1;i<x;i++){
                locate=locate->next;
            }
            (locate->previous)->next=locate->next;
            (locate->next)->previous=locate->previous;
            --Size;
        }
    }
    //returns the size of the list
    int Count(){
        return Size;
    }
    //displays the elements of the list
    void Display(){
    Node *disp=head;
    while(disp!=NULL){
        cout<<disp->data<<endl;
        disp=disp->next;
    }
    }
};
int main(){
int s;
DoublyLinkedLists List1;
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
