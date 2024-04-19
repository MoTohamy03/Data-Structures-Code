#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    // Create Linked List
    LinkedList() {
        head = NULL;
    }

    // Check Linked list Empty?
    bool IsEmpty() {
        return (head==NULL);
    }

    // Insert new node in first
    void InsertFirst(int newdata) {
        Node *newnode = new Node;
        newnode->data = newdata;

        if (IsEmpty()) {
            newnode->next = NULL;
        }
        else {
            newnode->next = head;
        }

        head = newnode;
    }

    // Display LinkedList items
    void Display() {
        Node *temp = head;

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    // Count LinkedList items
    int Count() {
        Node *temp = head;
        int counter=0;

        while (temp != NULL) {
            counter++;
            temp = temp->next;
        }
        return counter;
    }

    // Check if items found or not
    bool IsFound(int key) {
        Node* temp = head;
        bool check = false;
        while (temp != NULL) {
            if (temp->data == key) {
                check = true;
                return true;
            }
            temp = temp->next;
        }
        if (check == false)
            return false;
    }

    // Insert Before items
    void InsertBefore(int databefore, int newdata) {
        if (IsEmpty()) {
            InsertFirst(newdata);
        }
        if(IsFound(databefore)){
        Node* newnode = new Node;
        newnode->data = newdata;
        Node* temp = head;

        while (temp != NULL && temp->next->data != databefore) { 
            temp = temp->next;
        }      
        newnode->next = temp->next;
        temp->next = newnode;
        }
        else {
            cout << "Sorry, Item Not Found!\n";
        }
    }

    // Append item to the linkedlist
    void Append(int item) {
        if (IsEmpty()) {
            InsertFirst(item);
        }
        else {
            Node* temp = head;
            Node* newnode = new Node;
            newnode->data = item;
            while ((temp->next) != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = NULL;
        }        
    }

    // Delete items from Linkedlist
    void Delete(int item) {
        if (IsEmpty())
            cout << "Sorry, List is Empty and no items to delete\n";
        Node* delptr = head;
        if (head->data == item) {
            head = head->next;
            delete delptr;
        }
        else {
            delptr = head;
            Node* previos = NULL;
            while (delptr->data != item) {
                previos = delptr;
                delptr = delptr->next;
            }
            previos->next = delptr->next;
            delete delptr;
        }
        if (IsFound(item)) {
            cout << "Your item Not Found in the Linked list!\n";
        }
    }

    // Delete and copying items from Linkedlist
    int CopyDelete(int item) {
        int backitem;
        if (IsEmpty())
            cout << "Sorry, List is Empty and no items to delete\n";
        Node* delptr = head;
        if (head->data == item) {
            head = head->next;
            backitem = delptr->data;
            delete delptr;
        }
        else {
            delptr = head;
            Node* previos = NULL;
            while (delptr->data != item) {
                previos = delptr;
                delptr = delptr->next;
            }
            previos->next = delptr->next;
            delete delptr;
        }
        return backitem;
    }
};

int main()
{
    LinkedList list;
    

    return 0;
}
