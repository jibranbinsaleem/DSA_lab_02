#ifndef LIST_H
#define LIST_H

class List
{
    public:
        // constructor
        List();
        // destructor
        virtual ~List();
        // copy constructor
        List(const List& other);

        // boolean function
        bool empty() const;
        // access functions
        int headElement() const;
        // add to the head
        void addHead(int newdata);
        // delete the head
        void delHead();

        // utility function to get length of list
        int length() const;
        // display the list
        void print() const;

    private:
        int* list_elements;
        int size;
};

#endif // LIST_H
