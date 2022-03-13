#include <iostream>
#include <vector>
using namespace std;


// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

// Merge all the linked-lists into one sorted linked-list and return it.

 

// Example:
//
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//   1->4->5,
//   1->3->4,
//   2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    
    int getMinNode(vector<ListNode*>& lists) {
        bool initialized = false;

        ListNode* resultNode = 0;
        int res = -1;
        
        for (int i = 0; i < lists.size(); ++i) {
            ListNode* p = lists[i];
            if (p) {
                if (!resultNode) {
                    resultNode = p;
                    res = i;
                } else if (resultNode->val > p->val) {
                    resultNode = p;
                    res = i;
                } 
            }
        }
        
        return res;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<ListNode*> ptrs;
        for (int i = 0; i < lists.size(); ++i) {
            ptrs.push_back(lists[i]);
        }
        
        ListNode* resultList = 0, *p = 0;
        
        while (ptrs.size() > 0) {
            int minPos = getMinNode(ptrs);
            
            if (minPos < 0) break;
            
            if (!resultList) {
                p = resultList = ptrs[minPos];
            } else {
                p->next = ptrs[minPos];
                p = p->next;
            }
            
            ptrs[minPos] = ptrs[minPos]->next;
            
            if (!ptrs[minPos]) {
                ptrs.erase(ptrs.begin() + minPos);
            }
        }
        
        return resultList;
    }
};


int main() {
    Solution s;

    vector<ListNode*> arrayOfLists;
    arrayOfLists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
    arrayOfLists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    arrayOfLists.push_back(new ListNode(2, new ListNode(6)));
    
    ListNode* res = s.mergeKLists(arrayOfLists);
    while (res) {
        cout << res->val;
        res = res->next;
        if (res) {
            cout << " -> ";
        }
    }

    cout << endl;
}