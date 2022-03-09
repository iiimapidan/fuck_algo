#include <stdio.h>

struct ListNode {
    int value;
    ListNode* next;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* dummyNode = new ListNode;

    ListNode* p = dummyNode;
    ListNode* p1 = l1;
    ListNode* p2 = l2;

    while (p1 != nullptr && p2 != nullptr) {
        if (p1->value > p2->value) {
            p->next = p2;
            p2 = p2->next;
        } else {
            p->next = p1;
            p1 = p1->next;
        }
        p = p->next;
    }

    if (p1 != nullptr) {
        p->next = p1;
    }

    if (p2 != nullptr) {
        p->next = p2;
    }

    return dummyNode->next;
}

int main() {
    // 链表1
    ListNode* node_1_1 = new ListNode;
    node_1_1->value = 1;

    ListNode* node_1_2 = new ListNode;
    node_1_2->value = 2;

    ListNode* node_1_3 = new ListNode;
    node_1_3->value = 4;

    ListNode* node_1_4 = new ListNode;
    node_1_4->value = 8;

    node_1_1->next = node_1_2;
    node_1_2->next = node_1_3;
    node_1_3->next = node_1_4;

    // 链表2
    ListNode* node_2_1 = new ListNode;
    node_2_1->value = 1;

    ListNode* node_2_2 = new ListNode;
    node_2_2->value = 3;

    ListNode* node_2_3 = new ListNode;
    node_2_3->value = 4;

    node_2_1->next = node_2_2;
    node_2_2->next = node_2_3;

    ListNode* result = mergeTwoLists(node_1_1, node_2_1);
    while (result != nullptr) {
        printf("%d\r\n", result->value);
        result = result->next;
    }

    return 0;
}