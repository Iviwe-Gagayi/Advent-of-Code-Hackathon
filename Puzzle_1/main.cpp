#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) : data(val), prev(nullptr), next(nullptr) {}
};

class CircularDoublyLinkedList {


public:
    Node* head;
    CircularDoublyLinkedList() : head(nullptr) {}


    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }


    void displayForward() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }


    void displayBackward() {
        if (!head) return;
        Node* temp = head->prev;
        do {
            cout << temp->data << " ";
            temp = temp->prev;
        } while (temp != head->prev);
        cout << endl;
    }
};

int main() {
    CircularDoublyLinkedList temp;
    for (int i = 0; i<100; i++) {
        temp.append(i);
    }

    Node* curr = temp.head;
    for (int i = 0; i<50; i++) {
        curr = curr->next;
    }


    string x = "";
    int counter = 0;
    string holder;
    int iholder;
    int password = 0;
    while (cin >> x) {

        cout << "x is: " << x << endl;
        if (x == "end")break;
        if (x[0] == 'L') {
            holder = x;
            holder.erase(holder.begin());
            iholder = stoi(holder);
            for (int i = 0; i<iholder; i++) {
               // cout << "left" << curr->data << endl;
                curr = curr->prev;
                if (curr->data == 0) {
                    password++;
                }
            }
        }else if (x[0] == 'R') {
            holder = x;
            holder.erase(holder.begin());
            iholder = stoi(holder);
            for (int i = 0; i<iholder; i++) {
               // cout << "right" << curr->data << endl;
                curr = curr->next;
                if (curr->data == 0) {
                    password++;
                }
            }
        }



    }


    cout << "Password is: "<< password << endl;
    return 0;
}
