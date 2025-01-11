//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
class Solution {
public:
    // Function to find the middle node of the list.
    Node* getMid(Node* head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to reverse a linked list.
    Node* reverseList(Node* head) {
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

    // Function to check if a linked list is a palindrome.
    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true; // A list with 0 or 1 nodes is always a palindrome.
        }

        // Step 1: Find the middle of the linked list.
        Node* middle = getMid(head);

        // Step 2: Reverse the second half of the list.
        // Node* secondhalf=middle->next;
        // middle->next=reverseList(head)
        Node* secondhalf = reverseList(middle);

        // Step 3: Compare the first half and the reversed second half.
        Node* firsthalf = head;
         Node* temp = secondhalf; // To restore the list later.
        bool isPalin = true;

        while (temp != NULL) {
            if (firsthalf->data != temp->data) {
               return false;
            }
            firsthalf= firsthalf->next;
            temp = temp->next;
        }

        // Step 4: Restore the list to its original state.
        reverseList(temp);

        return true;
    }
};



//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends