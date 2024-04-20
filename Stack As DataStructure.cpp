#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node() {
        data = 0;
        next = NULL;
    }
};

class Stack {
    Node* top;
public:
    // Create the Stack by this constructor...
    Stack() {
        top = NULL;
    }
    
    // Adding new item
    void Push(int item) {
        // Node* temp = top;
        Node* newnode = new Node;
        newnode->data = item;
        newnode->next = top;
        top = newnode;
    }

    // Check if stack is empty (Null)?
    bool IsEmpty() {
        return (top == NULL);
    }

    // Poping the Last item
    int Pop() {
        if (IsEmpty()) {
            cout << "Your Stack is Empty!\n";
        }
        else {
            int returnvalue;
            Node* delptr = top;
            returnvalue = top->data;
            top = top->next;
            delete delptr; // delete old node from the heap memory
            return returnvalue;
        } 
    }

    // peeking the Last item
    int Peek() {
        if (IsEmpty()) {
            cout << "Your Stack is Empty!\n";
        }
        else {
            return top->data;
        }   
    }

    // Displaying items
    void Display() {
        Node* temp = top;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // count items in the stack
    int Count() {
        int counter=0;
        Node* temp = top;
        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    // Sreach in Stack
    bool IsFound(int item) {
        Node* temp = top;
        while (temp != NULL) {
            if (temp->data == item)
                return true;
            temp = temp->next;
        }
        return false;
    }

    // Check if the stack is Full or correctly if the Heap is full
    bool IsFull() {
        Node* ptr = new Node();
        if (ptr == NULL)
            return true;
        else
            return false;
    }

};

int main()
{
   
    // Searching in Stack
    /*cout << "Stack Search item: ";
    cin >> item;
    cout << (stack1.IsFound(item) ? "Founded" : "Not Found");*/

    // Popoing
    /*bool check;
    cout << "You want pop?\n";
    cin >> check;
    if (check >= 1)
        cout << stack1.Pop() << endl;
    else
        cout << "Okay!\n";*/

    // Peeking
    /*cout << "You want Peek?\n";
    cin >> check;
    if (check >= 1)
        cout << stack1.Peek();
    else
        cout << "Okay!\n";

    cout << "Stack Display: ";
    stack1.Display();*/

}

