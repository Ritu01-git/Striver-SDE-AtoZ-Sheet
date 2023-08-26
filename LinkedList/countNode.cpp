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
    if(head != NULL){
        sum = head->data + sumOfallData(head->next);
    }else{
        return sum;
    }
}
//maximum
int maximumData(Node*head){
    int maxi = INT_MIN;
    if(head == NULL) return maxi;
    
    maxi = max(maxi, head->data);
    maximumData(head->next);
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
    insertAtHead(head, 15);

    int len = recursiveCount(head);
    cout << len << endl;

    int s = sumOfallData(head);
    cout << s << endl;

    int maxi = maximumData(head);
    cout << "Maximum data is " << maxi << endl;

}