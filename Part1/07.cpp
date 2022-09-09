#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        return sortList(head, nullptr); // 注意这个tail，我在Prodrafts推导了[-1 5 3 4 0]的过程，可以得到正确答案
    }

    ListNode* sortList(ListNode* head, ListNode* tail) {
        if (head == nullptr) {
            return head;
        }
        if (head->next == tail) {
            head->next = nullptr;
            return head;
        }
        ListNode* slow = head, *fast = head;
        while (fast != tail) {
            slow = slow->next;
            fast = fast->next;
            if (fast != tail) {
                fast = fast->next;
            }
        }
        ListNode* mid = slow;
        return merge(sortList(head, mid), sortList(mid, tail));
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0); // 这个dummyHead使用后没有手动回收
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};

ListNode* TailInsert(ListNode* &L){
    int x;
    L = (ListNode*)malloc(sizeof(ListNode));
    ListNode *s, *r = L;
    while(cin >> x){
        s = (ListNode*)malloc(sizeof(ListNode));
        s->val = x;
        r->next = s; //在r结点后插入新元素
        r=s; // 永远保持r指向最后一个结点
    }
    r->next = NULL;
    
    return L->next; // 不要头结点
}

void print(ListNode* L){
    ListNode* tmp=L;
    while(tmp){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
int main(){
    ListNode* L;
    L = TailInsert(L);
    //print(L);

    Solution solution = Solution();
    L = solution.sortList(L);
    print(L);
    return 0;
}