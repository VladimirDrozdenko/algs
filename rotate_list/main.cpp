#include <iostream>
using namespace std;

// Given a head of a single-linked list rotate it k times to the left

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 void printList(const ListNode* head) {
     for (const ListNode* p = head; p; p = p->next) {
         if (p != head) {
             cout << " -> ";
         }
         cout << "(" << p->val << ")";
     }
     cout << endl;
 }

 ListNode* reverseList(ListNode* head) {
    ListNode* ehead = 0;
    while (head) {
        ListNode* p = head->next;
        head->next = ehead; 
        ehead = head;
        head = p;
    }
    return ehead;
 }

 int getListLength(ListNode* head) {
    int N = 0;
    for (const ListNode* p = head; p; p = p->next) {
        ++N;
    }
    return N;
 }

int main() {
    ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));

    printList(head);

    int k = 2;
    if (!head || k == 0) return 1;

    int N = getListLength(head);
    
    k %= N;
    if (k > 0) {
        ListNode* e = head;
        for (int i = 0; i < N-k; ++i) {
            if (i + 1 == N-k) {
                ListNode* prev = e;
                e = e->next;
                prev->next = 0;
            } else {
                e = e->next;
            }
        }

        for (ListNode* ehead = reverseList(e); ehead; ) {
            ListNode* p = ehead->next;
            ehead->next = head;
            head = ehead;

            ehead = p;
        }
    }

    printList(head);
}