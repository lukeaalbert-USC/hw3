#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot)
{
    if (head == nullptr) //base case
    {
      smaller = nullptr;
      larger = nullptr;
      return;
    }

    Node* tmpHead = head -> next;
    if (head -> val <= pivot)
    {
      smaller = head;
      smaller -> next = nullptr;
      llpivot(tmpHead, smaller -> next, larger, pivot);
    }

    else if (head -> val > pivot)//otherwise, it's greater.
    {
      larger = head;
      larger -> next = nullptr;
      llpivot(tmpHead, smaller, larger -> next, pivot);
    }

    head = nullptr;
}