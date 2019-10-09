#include <stdio.h>

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* alloc_node(int val) {
    ListNode* node = new ListNode();
    node->val = val;
    node->next = NULL;
    return node;
}

ListNode* rfind_k(ListNode* first, int k) {
    if(k == 0)
        return NULL;
    ListNode *p1 = first, *p2 = first;
    for(int i = 0; i < k; i ++) {
        if(!p2->next)
            return NULL;
        p2 = p2->next;
    }
    while(p2) {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p1;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        ListNode* null_node = alloc_node(-1);
        ListNode* tmp = null_node;
        int val;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &val);
            ListNode* node = alloc_node(val);
            tmp->next = node;
            tmp = node;
        }
        int last;
        scanf("%d", &last);
        tmp = rfind_k(null_node, last);
        if(tmp)
            printf("%d\n", tmp->val);
        else
            printf("0\n");
    }
    return 0;
}
