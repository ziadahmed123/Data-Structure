#include <iostream>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
template<class T>
class myList
{
private :
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };
    int Size;
    Node *head,*tail;
public:
    class Iterator
    {
    private :
        friend class myList;
        Node *NODE;
    public:
        Iterator()
        {
            NODE = NULL;
        }
        Iterator(Node *other)
        {
            NODE = other;
        }

        void operator++ (int)
        {
            //hence i point to next node and if next node is will null then we throw exception i throw exception because i haven't any node next me
            if (NODE->next == NULL)
                throw "hence iterator pointing last element so there isn't next element  ";

            NODE = NODE->next;
        }
        void operator-- (int)
        {
            //hence i point to Previous node and if prev node is will null then we throw exception
            if (NODE->prev == NULL)
            {
                throw "hence iterator pointing first element so there isn't previous element  ";
            }
            NODE = NODE->prev;
        }
        bool operator== (const Iterator &other)
        {
            return other.NODE == NODE;
        }
        T& operator* ()//return data or information that store in node
        {
            return NODE->data;
        }
    };
    myList()
    {
    Size = 0;
}
    myList(T value, int initial_size)
    {
    Size=initial_size;
    Node *NewNode = new Node;
    NewNode->data = value;
    head = tail = NewNode;
    NewNode->prev = NULL;
    NewNode->next = NULL;
    for (int i = 1; i < initial_size; i++)
    {
        Node *NewNode = new Node;
        NewNode->data = value;
        NewNode ->next = head;//must point to head before initialize head to be new node because don't lose sequence
        NewNode->prev = NULL;
        if (head != NULL)
            head->prev = NewNode;
        head = NewNode;//hence we add new node in head to be head and hence we don't lose sequence
    }
}
    ~myList()
    {
    Node *temp = head;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
    tail = NULL;
    Size = 0;
}
    int size()
    {
    return Size;
    }
    void Insert(T value, Iterator& position)
    {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    Size++;
    if (position.NODE == head )
    {
        newNode->prev = NULL;//because hence new node be first element

        newNode->next = head;//remark again first i point to head (about next new node)then i do prev second        element(who was first element before add new node )point to first element then assign i do all these because don't lost sequence
        head->prev = newNode;

        head = newNode;
        position.NODE = head;
    }
    else
    {
        newNode->next = position.NODE;
        newNode->prev = position.NODE->prev;
        //if i swap last two line with after two lines i will lose Sequence
        position.NODE->prev->next = newNode;
        position.NODE->prev = newNode;
    }
}
    void print()
    {
    Node  *moveNODE = head;
    cout<<"\n myList is : ";
    while (moveNODE != NULL)
    {
        cout << moveNODE->data << " " ;
        moveNODE = moveNODE->next;
    }
    cout<<"\tsize is = "<<Size<<endl;
}
    myList<T>& operator= (const myList<T> &anotherList);

    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(tail);
    }
    Iterator erase(Iterator &position)
    {
        if (Size>0)
        {
            Node *temp ;
            if (position.NODE == NULL)
            {
                throw "there isn't node to erase  ";
            }
            else
            {
                Size--;
                if (position.NODE == head )
                {
                    /*
                       5->6->7->8
                       hence if i need delete 5 i save value head  in temp first then  i do head point to next not vice versa because vice    versa do me lose sequence
                       */
                    temp = head;
                    head = head->next;
                   delete temp;
                    return head;

                }
                else
                {
                    /*
                       5->6->7->8
                       hence if i need delete 6 i save value 6 in temp first then  i do 6point to next not vice versa because vice versa
                       do me lose sequence
                       */
                    temp = position.NODE;
                    position.NODE->prev->next = position.NODE->next;//hence i do previous deleted element point to next deleted element
                    if(position.NODE->next!= NULL)
                        position.NODE->next->prev = position.NODE->prev;
                    //hence in if i need do previous for next deleted element point to previous deleted element because don't lose Sequence
                    delete temp;
                    return position.NODE;
                }

            }
        }
        else
        {
            throw "Sorry you can not delete from empty list";
        }
    }
};
template<class T>
myList<T>& myList<T>::operator=(const myList<T> &NewList)
{
    //first i emptying old list
    if (head != NULL)
    {
        Node* temp;
        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        tail = NULL;
        Size = 0;
    }

    //if new list contain data if no then head and tail remain =null
    if (NewList.head != NULL)
    {
        Node *new_node=new Node;
        Node *current = NewList.head;
        Size = NewList.Size;
        new_node->data = current->data;
        new_node->next = NULL;
        new_node->prev = NULL;
        tail = head = new_node;
        current = current->next;
        while (current != NULL)
        {
            new_node = new  Node;
            new_node->data = current->data;
            new_node->next = NULL;
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
            current = current->next;
        }
    }
    return *this;
}

int main()
{
try{
        int defualtSizeList1=5;
        myList<int> list1(5 ,defualtSizeList1);
        myList<int>::Iterator position =list1.begin();
        for (int i=1;i<defualtSizeList1;i++)
                position=list1.erase(position);
        for (int i=0;i<defualtSizeList1-1;defualtSizeList1--)
                list1.Insert(defualtSizeList1-1,position);
                        list1.print();

/////////////////////////////////////////above first list ////////////////////////////////////////////////////////////////
  int defualtSizeList2=5;
        myList<int> list2(5 ,defualtSizeList2);
        myList<int>::Iterator position2 =list2.begin();
        for (int i=1;i<defualtSizeList2;i++)
                position2=list2.erase(position2);
        for (int i=6;i<10;i++)//
                list2.Insert(i,position2);
        list2.print();
////////////////////////////////////////////////////above second list///////////////////////////////////////////////////////////////////

}
catch (const char *msg )
{
    cout<<msg;
}
    return 0;
}
