#include <bits/stdc++.h>
using namespace std;

// creating Node
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

// inserting at the first and making it head
void insertAtHead(Node *&head, int data)
{
    Node *N = new Node(data);
    N->next = head;
    head = N;
}

// inserting at tail
void insertAtTail(Node *&head, int data)
{
    Node *N = new Node(data);
    Node *P = head;
    while (P->next != NULL)
    {
        P = P->next;
    }
    P->next = N;
    N->next = NULL;
}

// using recursion to display the data of all the nodes
void recursiveDisplay(Node *head)
{
    if (head != NULL)
    {
        cout << head->data << " ";
        recursiveDisplay(head->next);
    }
}

// using recursion to display the data in reverse order
void recursiveReverse(Node *head)
{
    if (head != NULL)
    {
        recursiveReverse(head->next);
        cout << head->data << " ";
    }
}

// main function
int main()
{
    Node *head = NULL;
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtHead(head, 10);
    insertAtHead(head, 15);

    recursiveDisplay(head);
    cout << endl;
    recursiveReverse(head);
}