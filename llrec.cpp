#include <iostream>
#include <fstream>
#include <functional> 
#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot)
{
    if (head == nullptr) //base case
    {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    if (head -> val <= pivot)
    {
        smaller = head;
        llpivot(head -> next, smaller -> next, larger, pivot);
    }

    else if (head -> val > pivot)//otherwise, it's greater.
    {
        larger = head;
        llpivot(head -> next, smaller, larger -> next, pivot);
    }
}