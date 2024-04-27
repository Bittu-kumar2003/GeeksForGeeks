#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    struct Node *sortDoubly(struct Node *head) {
        if(head == NULL)
           return head;
        Node *temp = head;
        vector<int> arr;
        while(temp != nullptr){
            arr.push_back(temp->data);
            temp = temp->next;        
        }
        sort(arr.begin(), arr.end());
        struct Node *newNode = new Node(arr[0]);
        struct Node *dummyHead = newNode;
        for(int i = 1; i < arr.size(); i++){
            Node *temp_node = new Node(arr[i]);
            dummyHead->next = temp_node;
            temp_node->prev = dummyHead;
            dummyHead = temp_node;
        }
        return newNode;
    }
};
void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}
