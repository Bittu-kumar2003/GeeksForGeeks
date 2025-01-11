//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    // Function to reverse a linked list.
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Function to insert a node at the tail of the linked list.
    void insertAtTail(Node*& head, Node*& tail, int value) {
        Node* temp = new Node(value);
        // Empty case
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    // Function to add two linked lists.

        // Add corresponding digits of both lists.
        while (first != NULL && second != NULL) {
            int sum = carry + first->data + second->data;
            int digit = sum % 10;

            // Insert the digit at the tail of the result list.
            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            first = first->next;
            second = second->next;
        }

        // Add remaining digits of the first list.
        while (first != NULL) {
            int sum = carry + first->data;
            int digit = sum % 10;

            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            first = first->next;
        }

        // Add remaining digits of the second list.
        while (second != NULL) {
            int sum = carry + second->data;
            int digit = sum % 10;

            insertAtTail(anshead, anstail, digit);

            carry = sum / 10;
            second = second->next;
        }

        // If there is a carry remaining, add it as a new node.
        while (carry > 0) {
            int digit = carry % 10;

            insertAtTail(anshead, anstail, digit);

            carry = carry / 10;
        }

        return anshead;
    }
    // Function to add two numbers represented by linked lists.
    Node* addTwoLists(Node* num1, Node* num2) {
        // Step 1: Reverse both linked lists.
        num1 = reverse(num1);
        num2 = reverse(num2);

        // Step 2: Add the two reversed linked lists.
        Node* ans = add(num1, num2);

        // Step 3: Reverse the result linked list.
        ans = reverse(ans);

        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends