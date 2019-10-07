#include <stdio.h>

struct ListNode {
    int value;
    ListNode* next;
    ListNode(int v) {value = v; next = NULL;}
};

void insert(ListNode* p, ListNode* node, int val) {
    while(p) {
        if(p->value == val) {
            // insert
            ListNode* tmp = p->next;
            p->next = node;
            node->next = tmp;
            return;
        }
        p = p->next;
    }
}

void erase(ListNode* p, int val) {
    while(p) {
        ListNode* node = p->next;
        if(node && node->value == val) {
            p->next = node->next;
            delete node;
        }
        p = p->next;
    }
}

void print(ListNode* node) {
    while(node) {
        printf("%d ", node->value);
        node = node->next;
    }
    printf("\n");
}

int main() {
    int n, v;
    while(scanf("%d", &n) != EOF) {
        scanf("%d", &v);
        ListNode* null_node = new ListNode(-1); // 空结点
        ListNode* first = new ListNode(v);
        null_node->next = first;
        
        int v1, v2;
        for(int i = 1; i < n; i ++) {
            scanf("%d %d", &v1, &v2);
            ListNode* node = new ListNode(v1);
            insert(first, node, v2);
        }
        //print(first);
        int target;
        scanf("%d", &target);
        erase(null_node, target);
        print(null_node->next);
    }
    return 0;
}
