#include <iostream>
#include <fstream>
#include <functional> 
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------


void llrecTestpt1(Node *&head)
{
    Node* smaller = nullptr;
    Node* larger = nullptr;
    llpivot(head, smaller, larger, 2);
    print(smaller);
    print(larger);
}

void llrecTestpt2(Node *&head)
{
    // Test out your linked list code
    GreaterThan gt(2);
    print(llfilter(head, gt));
}

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
    Node* head = readList(argv[1]);
    std::cout << "Original list: ";
    print(head);

    std::cout << "Part 1: " << std::endl;
    llrecTestpt1(head);
    std::cout << "Part 2: " << std::endl;
    llrecTestpt2(head);

    
    return 0;

}
