#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data) : data{data}, next{NULL} {}
};

class Queue
{
    Node *front; // Points to the front of the queue
    Node *rear;  // Points to the rear of the queue
    int currentSize; // Keeps track of the size of the queue

public:
    Queue() : front{NULL}, rear{NULL}, currentSize{0} {}

    // Insert at the back of the queue
    void push_back(int data)
    {
        Node *newNode = new Node(data);
        if (!front)
        {
            front = rear = newNode; // If the queue is empty, both front and rear point to the new node
        }
        else
        {
            rear->next = newNode; // Link the new node at the end
            rear = newNode; // Update the rear pointer
        }
        currentSize++; // Increment the size
    }

    // Insert at the front of the queue
    void push_front(int data)
    {
        Node *newNode = new Node(data);
        if (!front)
        {
            front = rear = newNode; // If the queue is empty, both front and rear point to the new node
        }
        else
        {
            newNode->next = front; // Link the new node to the current front
            front = newNode; // Update the front pointer
        }
        currentSize++; // Increment the size
    }

    // Remove from the front of the queue
    int pop_front()
    {
        if (!front) return -1; // If the queue is empty, return -1

        int data = front->data; // Get the data to return
        Node *temp = front; // Temporary pointer to delete the node
        front = front->next; // Move front pointer to the next node
        delete temp; // Delete the old front node
        currentSize--; // Decrement the size

        if (!front) // If the queue becomes empty
            rear = NULL; // Update rear to NULL

        return data; // Return the data of the removed node
    }

    // Remove from the back of the queue
    int pop_back()
    {
        if (!front) return -1; // If the queue is empty, return -1

        if (front == rear) // If there's only one element
        {
            int data = front->data; // Get the data to return
            delete front; // Delete the last node
            front = rear = NULL; // Update both front and rear to NULL
            currentSize--; // Decrement the size
            return data; // Return the data of the removed node
        }

        // More than one element
        Node *temp = front; // Start from the front
        while (temp->next != rear) // Find the second last node
            temp = temp->next;

        int data = rear->data; // Get the data to return
        delete rear; // Delete the rear node
        rear = temp; // Update rear to point to the new last node
        rear->next = NULL; // Set the next of new rear to NULL
        currentSize--; // Decrement the size
        return data; // Return the data of the removed node
    }

    // Get the front element
    int get_front() const
    {
        if (!front) return -1; // If the queue is empty, return -1
        return front->data; // Return the data of the front node
    }

    // Get the back element
    int get_back() const
    {
        if (!rear) return -1; // If the queue is empty, return -1
        return rear->data; // Return the data of the rear node
    }

    // Get the size of the queue
    int size() const
    {
        return currentSize; // Return the current size
    }

    // Check if the queue is empty
    bool isEmpty() const
    {
        return currentSize == 0; // Return true if size is 0
    }

    // Destructor to clean up memory
    ~Queue()
    {
        while (front) // Delete all nodes
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL; // Set rear to NULL
    }
};

int main()
{
    Queue dq;

    dq.push_back(10);  // Insert at the back
    dq.push_front(20); // Insert at the front

    cout << "Front: " << dq.get_front() << endl; // 20
    cout << "Back: " << dq.get_back() << endl;   // 10

    dq.pop_front(); // Remove from the front
    dq.pop_back();  // Remove from the back

    cout << "Is queue empty? " << (dq.isEmpty() ? "Yes" : "No") << endl; // Yes

    return 0;
}
