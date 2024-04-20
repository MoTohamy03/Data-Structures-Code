#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node() {
        data = 0;
        next = NULL;
    }
};

class Queue {
public:
    Node* rear;
    Node* front;
    Queue() {
        rear = NULL;
        front = NULL;
    }

    // Check if Queue is empty function
    bool IsEmpty() {
        if (front == NULL && rear == NULL)
            return true;
        return false;
    }

    // Add elements to Queue
    void EnQueue(int item) {
        Node* newnode = new Node;
        newnode->data = item;
        
        if (IsEmpty()) {
            rear = newnode;
            front = newnode;
        }
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    // Display Elements from Queue
    void Display() {
        if (IsEmpty())
            cout << "Sorry, Queue is empty!" << endl;
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Dequeue from the queue
    int DeQueue() {
        Node* delptr = front;
        int delvalue = -1;
        if (IsEmpty()) {
            cout << "Sorry, The Queue is empty!" << endl;
        }
        else if(front == rear) {
            delete front;
            front = rear = NULL;
            delvalue = delptr->data;
        }
        else {
            front = front->next;
            delvalue = delptr->data;
            delete delptr;
        }
        return delvalue;
    }

    // Peek last element
    int Peek() {
        Node* delptr = front;
        int delvalue = -1;
        if (IsEmpty()) {
            cout << "Sorry, The Queue is empty!" << endl;
        }
        else if(front == NULL && rear == NULL) {
            front = rear = NULL;
            delvalue = delptr->data;
            delete delptr;
        }
        else {
            front = front->next;
            delvalue = delptr->data;
            delete delptr;
        }
        return delvalue;
    }

    // check is full
    bool IsFull() {
        Node* temp = new Node;
        if (temp == NULL)
            return true;
        return false;
    }

    // clear the queue
    void Clear() {
        while ( (!IsEmpty()) ) {
            DeQueue();
        }
        /*Node* delptr = front;
        while (front != NULL) {
            front = front -> next;
            delptr = front;
            delete delptr;
        }
        front = rear = NULL;*/
    }

    // get the last element
    int getRear() {
        return rear->data;
    }

    // count Queue elements 
    int Count() {
        int counter = 0;
        Node* temp = front;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }
    
    // Search in the Queue
    bool IsFound(int item) {
        Node* temp = front;
        while (temp != NULL) {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }

};

int main()
{
    Queue q;
    int item;

    // check is empty
    /*
    cout << (q.IsEmpty() ? "Empty" : "Not Empty") << endl;
    */
    
    // Push elements into queue
    /*int check =1;
    cout << "Need add elements?!" << endl;
    cin >> check;

    while (check >= 1) {
        cout << "Add item:";
        cin >> item;
        q.EnQueue(item);
        cout << "Need add more: " << endl;
        cin >> check;
    }*/

    // Display elements from dequeue
    /*cout << "Queue elements: ";
    q.Display();
    cout << endl;*/

    // clear Queue 
    /*
    q.Clear();
    */
    

    // Search in Queue
    /*cout << "Enter research element: ";
    cin >> item;
    cout << (q.IsFound(item) ? "Founded" : "Not Found") << endl;*/

    // count queue
    /*
        cout << "Count of Queue = " << q.Count() << endl;
    */

    // Peeking 
    /*
        cout << "Peek for Queue: " << q.Peek() << endl;
    */
    
    // Display elements from dequeue
    /*cout << "Queue elements: ";
    q.Display();
    cout << endl;*/

    // dequeue elements
    /*cout << "You need dequeue?!" << endl;
    cin >> check;

    while (check >= 1) {
        cout << "You still need dequeue?!" << endl;
        cin >> check;
        q.DeQueue();
    }*/

    // Display elements from dequeue
    /*cout << "Queue elements: ";
    q.Display();
    cout << endl;*/

    return 0;
}