/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

#include <cmath>
#include <iostream>

using namespace std;


struct node
{
    int val;
    node* next;
    node(int v, node* pn = 0) : val(v), next(pn) {}
};

int list2Number(const node* p, int pos = 0)
{
    if (!p)
        return 0;
    return p->val * pow(10, pos) + list2Number(p->next, pos + 1);
}

const node* add(const node* a, const node* b)
{
    const node* pa = a, *pb = b;
    node* pres = 0, *ptail = 0;

    int carry = 0;
    while (pa && pb)
    {
        int val = pa->val + pb->val + carry;
        carry = val / 10;

        if (!pres)
            pres = ptail = new node(val % 10);
        else 
            ptail = ptail->next = new node(val % 10);

        pa = pa->next;
        pb = pb->next;
    }

    for (const node* p = pa ? pa : pb; p; p = p->next)
    {
        int val = p->val + carry;
        ptail = ptail->next = new node(val % 10);
        carry = val / 10;
    }

    if (carry > 0)
    {
        ptail->next = new node(carry);
    }

    return pres;
}


int main()
{
    const node* a = new node(2, new node(4, new node(3)));
    //const node* b = new node(5, new node(6, new node(9)));
    const node* b = new node(5, new node(6, new node(0)));

    cout << list2Number(a) << endl;
    cout << list2Number(b) << endl;

    const node* sum = add(a, b);
    cout << list2Number(sum) << endl;
}