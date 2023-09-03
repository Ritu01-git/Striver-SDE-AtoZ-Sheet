#include <bits/stdc++.h>
using namespace std;

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
// this is the normal counting using loops
int countNode(Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}
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

// inserting at anygiven position
void insertPOS(Node *&head, int position, int data)
{
    Node *temp = new Node(data);
    Node *p = head;
    if (position == 0)
    {
        insertAtHead(head, data);
    }else if(position > countNode(head))
    {
        return;
    }
    else if (position > 0)
    {
        for (int i = 1; i < position-1; i++)
        {
            p = p->next;
        }
        
        temp->next = p->next;
        p->next = temp;
    }
}

// counting the number of nodes in recursive way where Time complexity = O(N) and Space = O(N)
int recursiveCount(Node *head)
{
    if (head == NULL)
        return 0;
    else
    {
        return recursiveCount(head->next) + 1;
    }
}

// sum of all the elements of the LL
int sumOfallData(Node *head)
{
    int sum = 0;
    if (head != NULL)
    {
        sum = head->data + sumOfallData(head->next);
    }
    else
    {
        return sum;
    }
}
// maximum
int maximumData(Node *head)
{
    int x = 0;
    if (head == NULL)
        return INT_MIN;
    x = maximumData(head->next);
    return x > head->data ? x : head->data;
}
// recursive function to search in LL
bool searchRecursive(Node *head, int target)
{
    if (head == NULL)
        return false;
    if (head->data == target)
        return true;
    return searchRecursive(head->next, target);
}
// search in LL
bool searchInLL(Node *head, int target)
{
    if (head == NULL)
        return NULL;
    if (head->data == target)
        return true;
    searchInLL(head->next, target);
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

//inserting in a sorted LL
void insertInSortedLL(Node*&head, int data)
{
    Node *temp = new Node(data);
    Node *P = head;
    Node *q = NULL;
    while(P->data < data){
        q = P;
        P = P->next;
    }
    q->next = temp;
    temp->next = P;
}

int main()
{
    Node *head = NULL;
    insertAtHead(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtHead(head, 10);
    insertAtHead(head, 5);

    int len = recursiveCount(head);
    cout << len << endl;

    int s = sumOfallData(head);
    cout << s << endl;

    int maxi = maximumData(head);
    cout << "Maximum data is " << maxi << endl;

    int target = 0;
    bool ans = searchRecursive(head, target);
    cout << ans << endl;

    insertPOS(head, 5, 33);
    print(head);

    cout << "After inserting in sorted LL: " << endl;
    insertInSortedLL(head, 35);
    print(head);
}