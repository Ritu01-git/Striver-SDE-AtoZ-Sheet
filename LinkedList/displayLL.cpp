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

// inserting at head
void insertAthead(Node *&head, int data)
{
    Node *n = new Node(data);
    n->next = head;
    head = n;
}

// printing the data of all the nodes
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

// main function
int main()
{

    Node *head = NULL;
    insertAthead(head, 20);
    insertAthead(head, 52);
    insertAthead(head, 28);
    insertAthead(head, 96);
    insertAthead(head, 2);

    print(head);
}