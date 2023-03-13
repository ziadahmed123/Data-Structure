#include <iostream>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
using namespace std;
#define MAX_COUNT 10000// Maximum number of numbers made of 0 and 9
vector<string> vec; // vector to store numbers that can be formed using 0 and 9

////////////////////// class queue
template <class T>
class queuee
{
private:
    T *q;
    int sizee ;

public:
////// default constructor
    queuee()
    {
        sizee=0;
        q = new T[1000];
    }
////// parametrized constructor
    queuee(T value, int initialsize)
    {
        sizee=initialsize;
        q = new T[initialsize];
        for (int i=0; i<sizee; i++)
            q[i]=value;
    }
    //////  distructor
    ~queuee()
    {
        sizee=0;
        delete []q;
    }
////get first element
    T& front()
    {
        return q[0];
    }
    ///// remove elements from queue
    void pop()
    {
        for (int i=1 ; i<sizee; i++)
            q[i-1]=q[i];
        sizee--;
    }
///// add elements to queue
    void push(T value)
    {
        q[sizee++]=value;
    }
    /////// get the size
    int getsize()
    {
        return sizee;
    }
};
//////////////////////end of class queue

/////new class to the second part of the problem
class ZerosAndNines
{
public:
    // function to do that
void findNumbers()
{
    // create queue of strings
    queue <string> q;

    // enqueue the first number
    q.push("9");

    // This loops has 9 as root , 0 from left and 9 right
    for (int c = MAX_COUNT; c > 0; c--)
    {
        string s1 = q.front();
        q.pop();

        // storing the front of queue
        vec.push_back(s1);
        string s2 = s1;

        // Append "0" to s1 and enqueue it and "9" to s2 (that has the previous front)and enqueue it
        q.push(s1.append("0"));
        q.push(s2.append("9"));
    }
}

// function to find smallest number of digits 9 and 0, (multiple of n)
  string findSmallestMultiple(int n)
{
    for (int i = 0; i < vec.size(); i++)

         //to convert string into int
        if (stoi(vec[i])%n == 0)
            return vec[i];
}
};
/////end of the new class to the second part of the problem


int main()
{
    ///////main for queue class
    queuee<int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.push(60);
    cout<< "the size is " << a.getsize()<<endl;
    cout<<"the first element is " << a.front()<<endl;
    a.pop(); ///// delete this element
    cout<< "the first element after pop operation is " << a.front()<<endl;
    cout<<"the size after pop operation is " << a.getsize()<<endl;
    /////// end of main for queue class

/////////// main for the new class
    ZerosAndNines z1;
    z1.findNumbers();
    cout << "the smallest multiple of the number is   " << z1.findSmallestMultiple(7);
    return 0;
}
