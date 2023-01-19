#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

class Queue {
public:
    Node* head;
public:
    Queue() {
        head = NULL;
    }

    void enqueue(int data);
    void dequeue();
    int size();
    int front();
    void empty();
    void getMax(Queue queue);
    void printQueueItems();

};

void Queue::enqueue(int data) {
    Node* node = new Node();
    node->data = data;
    if (head == NULL)
        node->next = NULL;
    else
        node->next = head;
    head = node;
}

void Queue::dequeue() {
    Node* node = head;
    if (head == NULL) {
        cout << "ERROR" << endl;
    }
    else if (head->next != NULL) {
        while (node->next->next != NULL) {
            node = node->next;
        }
        node->next = NULL;   
    }
    else {
        head = NULL;
    }
}

int Queue::size() {
    int count = 0;
    if (head == NULL) {
        //cout<<"size:0"<<endl;
        return 0;
    }
    else {
        Node* node = head;
        while (node->next != NULL) {
            node = node->next;
            count++;
        }
        //cout<<"size:"<<count+1<<endl;
        return count + 1;
    }

}

int Queue::front() {
    Node* node = head;
    if (head == NULL) {
        cout << "ERROR" << endl;
        
    }else{
         Node* node = head;
         while (node->next != NULL) {
             node = node->next;
            }
            //cout << node->data << endl;
            return node->data;}
}

void Queue::empty() {
    if (head == NULL)
        cout << "queue is empty" << endl;
    else
        cout << "queue is not empty" << endl;
}

void Queue::printQueueItems() {
    Node* node = head;
    while (node->next != NULL) {
        cout << node->data << " "; 
        node = node->next;
    }
    cout << node->data << endl;
}

void Queue::getMax(Queue queue) {
    int max = 0;
    Node* node = head;
    Queue q = queue;
    if (head = NULL) {
        cout << "ERROR" << endl;
    }
    else {
        while (q.size() != 0) {
        if (q.front() > max) {
            max = q.front();
            q.dequeue();
        }else {
            max = max;
            q.dequeue();
        }
        }
    }
    
    cout << "max:" << max << endl;
}

int main() {
    Queue newQueue;
    Node* head = NULL;
    newQueue.empty();
    newQueue.enqueue(10);
    newQueue.enqueue(20);
    newQueue.enqueue(3);
    newQueue.enqueue(123);
    newQueue.empty();
    newQueue.enqueue(700);
    newQueue.enqueue(15);
    newQueue.enqueue(85);
    newQueue.enqueue(32);
    newQueue.printQueueItems();
    newQueue.dequeue();
    newQueue.printQueueItems();
    newQueue.getMax(newQueue);

    return 0;
}
