#include "List.h"
#include<iostream>

using namespace std;
List::List(){
    size = 0;
}

List::List(const List& other){
    if (other.size != 0)
        for (int i=0; i < other.size; i++)
       {

            head[i] = other.head[i];
            size++;
       }
}
bool List::empty() const{
    if (size == 0)
        return true;
    else
        return false;
}
int List::headElement() const{
    if (size != 0)
        return head[0];
    else{
        cout << "Error: Cannot find head of empty list\n";
        exit(1);
    }
}
void List::addHead(int newdata){
    if (size < 10000){
        for (int i = size; i>= 0; i--)
            head[i+1] = head[i];
        head[0] = newdata;
        size++;
    }

}
void List::delHead(){
    for (int i = 1; i < size; i++)
        head[i-1] = head[i];
    size--;
}
int List::length() const{
    return size;
}
void List::print() const{
    cout << "[" ;
    for (int i = 0; i < size; i++){

        cout << head[i];
        if (i < size - 1)
            cout << ", ";
    }
    cout << "]" << endl;

}
List::~List()
{
    //dtor
}
