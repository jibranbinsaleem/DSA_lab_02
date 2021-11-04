#include "List.h"
#include<iostream>
#include<string>

using namespace std;
//ctor
List :: List(){

    list_elements = NULL;
    size = 0;
}

//copy ctor
List:: List(const List& other){

    this->size=other.size;
    this->list_elements = other.list_elements;
}

bool List :: empty() const{
    if(list_elements!=NULL)
       return false;
    else
        return true;
}


void List :: addHead(int newdata){

    int *n = new int[size+1];
    n[0] = newdata;
    for(int i = 0;i < size; i++)
        n[i+1] = list_elements[i];

    n[0] = newdata;
    int*  temp = list_elements;
    list_elements = n;

    delete[] temp;
    size++;
}

//delete head
void List:: delHead(){

    int *n = new int[size];

    for(int i = 0;i<size;i++)
        n[i] = list_elements[i];

    list_elements = new int[size-1];

    for(int i=0; i<size-1; i++)
        list_elements[i] = n[i+1];

    delete[] n;
    size--;
}

//Accessing the Head element
int List:: headElement() const{

    if(size==0){
            cout << "Error: Trying to find head of Empty List" << endl;
            exit(1);
    }
    else
        return *list_elements;
}

int List::length() const{
    return size;
}


 void  List::print()const{

    cout<<"[";
    for(int i=0;i<size;i++){
        if(i>0){
            cout<< ", ";
        }
        cout<< (list_elements[i]);
     }
     cout<< "]"<<endl;
 }

 // dtor
List::~List(){
    delete [] list_elements;
}
