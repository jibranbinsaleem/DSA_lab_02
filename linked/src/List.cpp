#include "List.h"
#include<iostream>
#include<string>

using namespace std;

List::List()
{
    //constructor
    head=NULL;
}

List::~List()
{
    //destructor
    Nodeptr cur;
    while(head!=NULL)
    {
        cur=head;
        head=head->next;
        delete cur;
    }
}

List::List (const List& other)
{
    List temp;
    temp.head = NULL;

    Nodeptr cur = other.head;
    while(cur !=NULL)
    {
        temp.addHead(cur->data); //inverse list order
        cur = cur->next;
    }
    head = NULL;
    Nodeptr cur2 = temp.head;
    while(cursor !=NULL)
    {
        addHead(cur2->data); //inverse list order
        cur2 = cur2->next;
    }
}

bool List::empty() const
{
    if(head==NULL)
        return true;
    else
        return false;
}

int List::headElement() const
{
    if(head != NULL)
    return head->data;
    else
    {
        cout << "error: trying to find head of empty list" << endl;
        exit(1);
    }
}

void List:: addHead(int newdata)
{
    Nodeptr newptr = new Node;
    newptr->data = newdata;
    newptr->next = head;
    head = newptr;
}

void List::delHead()
{
    if(head != NULL)
    {
        Nodeptr cur = head;
        head = head->next;
        delete cur;
    }
}

int List::length() const
{
    int n=0;
    Nodeptr cur = head;
    while(cur != NULL)
    {
        n++;
        cur = cur->next;
    }
    return n;
}

void List::print() const
{
    cout<<"[";
    Nodeptr cur = head;
    int size = length();
    for(int i=1; i<=size; i++ )
    {
        cout<< cur->data;
        if(i < size)
            cout <<", ";
        cur = cur->next;
    }
    cout<<"]"<<endl;
}

