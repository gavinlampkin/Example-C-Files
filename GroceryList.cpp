// File Name: GroceryList.cpp
//
// Author: Gavin Lampkin
// Collaborators: None
// Date: 11/4/2022
// Assignment Number: 7
// CS 2308 Spring 2022
//
// Grocery list class that the member functions can access directly
// inside of the class. It has multiple functions that can change
// the order, print, add, and delete nodes from the class linked list.

#include <iostream>
#include <fstream>
#include <iomanip>
#include "GroceryList.h"

using namespace std;
//***********************************************************
// GroceryList: Constructor for the class.
//
// returns: no return type.
//**********************************************************

GroceryList::GroceryList()
{
    head = nullptr;
    tail = nullptr;
}
//***********************************************************
// ~GroceryList: Destructor for the class.
//
// returns: no return type.
//***********************************************************
GroceryList::~GroceryList()
{
    GroceryNode *p;
    while (head!=nullptr) {
        p = head;
        head = head->next;
        delete p;
    }
}
//***********************************************************
// count: returns the number of nodes in the linked list
//
// returns: integer
//***********************************************************
int GroceryList::count()
{
    int count = 0;
    GroceryNode *p = head;
    while(p!=nullptr)
    {
        p = p->next;
        count++;
    }
    return count;
}
//***********************************************************
// PushLast: adds a new node to the end of the list.
//
// string x - the data that needs to be stored in the last node.
// returns: void
//***********************************************************
void GroceryList::pushLast(string x)
{
    GroceryNode *p = new GroceryNode;
    p->data = x;
    p->next = nullptr;

    if(head==nullptr)
    {
        head=p;
        return;
    }
    else if(head->next==nullptr)
    {
        head->next=p;
        tail=head->next;
    }
    else
    {
        tail->next=p;
        tail=tail->next;
    }
}
//***********************************************************
// popFront - Removes the front node.
//
// returns: void
//***********************************************************
void GroceryList::popFront()
{
    if(head!=nullptr)
        head = head->next;
}
//***********************************************************
// Last - Returns the last node in the list.
//
// returns: string
//***********************************************************
string GroceryList::last()
{
    if(count() == 0)
        return "";
    else
        return tail->data;
}
//***********************************************************
// display - displays the list to the screen.
//
// ostream - A reference to cout in the driver file.
// returns: void
//***********************************************************
void GroceryList::display(ostream& out)
{
    GroceryNode *p = head;
    while(p!=nullptr)
    {
        out << p->data << endl;
        p = p->next;
    }
}
//***********************************************************
// toStringWithDelimiter - Returns the string with the selected
// delimiter in between each data value.
//
// string d - The chosen delimiter.
// returns: String
//***********************************************************
string GroceryList::toStringWithDelimiter(string d)
{
    string completeString = "";
    GroceryNode *p = head;
    while(p!=nullptr)
    {
        if(p->next==nullptr)
            completeString = completeString + p->data;
        else
            completeString = completeString + p->data + d;
        p = p->next;
    }
    return completeString;
}
//***********************************************************
// moveToLast(not working) - removes the selected node from the
// list and moves it to the end.
//
// string x - the selected string variable you would like to move.
// returns: void
//***********************************************************
void GroceryList::moveToLast(string x){
    GroceryNode *p = new GroceryNode;
    GroceryNode *n = nullptr;
    p = head;
    if(head==nullptr)
        head = p;
    else if(x==tail->data)
        return;
    else{
        while(p && p->data!=x){
            n = p;
            p = p->next;
        }
        if(p){
            if(n==nullptr){
                head = p;
                delete p;
            }
            else{
                n->next = p->next;
                p->next=nullptr;
                tail->next=p; // I have no idea why this keeps giving me seg. faults :/
                delete p;
            }
        }
    }
}
//***********************************************************
// minimumUpTo - Gives you the minimum string value in the
// list given the end index the user would like to check.
//
// int x - the number of elements in the linked list you would
// like to find the min. of.
// (remaining params, if any)
// returns: description of what function returns (if not void)
//***********************************************************
string GroceryList::minimumUpTo(int x){
    GroceryNode *p = head;
    string temp;
    if(x<=1)
        return head->data;
    else if(p==nullptr)
        return "";
    for(int i=0;i<x-1;i++)
    {
        if(p->data > p->next->data)
            temp = p->data;
        else
            temp = p->next->data;
        p = p->next;
    }
    return temp;
}
//***********************************************************
// selectionSort - completes a selection sort on the linked list.
//
// returns: void
//***********************************************************
void GroceryList::selectionSort()
{
    string minimum;
    for(int i=1;i<count()-1;i++)
    {
        minimum = minimumUpTo(i);
        moveToLast(minimum);
    }
}
