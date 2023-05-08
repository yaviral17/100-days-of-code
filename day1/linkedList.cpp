#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        head = new node(val);
        return;
    }

    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = n; 
}


void swapNodes(node *&head, int x, int y)
{
    if (x == y)
        return;

    node *prevX = NULL, *currX = head;
    while (currX && currX->data != x)
    {
        prevX = currX;
        currX = currX->next;
    }

    node *prevY = NULL, *currY = head;
    while (currY && currY->data != y)
    {
        prevY = currY;
        currY = currY->next;
    }

    if (currX == NULL || currY == NULL)
        return;

    if (prevX != NULL)
        prevX->next = currY;
    else
        head = currY;

    if (prevY != NULL)
        prevY->next = currX;
    else
        head = currX;

    node *temp = currY->next;
    currY->next = currX->next;
    currX->next = temp;
}

int listLength(node *&head)
{
    if (head == NULL)
    {
        
        return 0;
    }

    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 5);
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    insertAtTail(head, 8);
    insertAtTail(head, 9);
    display(head);
    return 0;
}