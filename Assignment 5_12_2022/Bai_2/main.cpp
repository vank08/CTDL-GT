#include "stdlib.h"
#include "stdio.h"
#include<time.h>

struct Node {
    int num;
    struct Node* Next;
};

typedef struct Node* PtrToNode;

int main() {
    clock_t start, end;   // Khai báo bi?n th?i gian
    double time_use;
    start = clock();
    int n, m, i;
    PtrToNode head, p, q;

    printf("Please input n, m\n");
    scanf("%d %d", &n, &m);
    printf("Input was n=%d, m=%d\n", n, m);

    head = (PtrToNode)malloc(sizeof(struct Node));
    head->num = 1;

    p = head;
    for (i = 2; i <= n; i++) {
        q = (PtrToNode)malloc(sizeof(struct Node));
        q->num = i;
        p->Next = q;
        p = q;
    }
    p->Next = head;

    while (q->Next != q) {
        for (i = 1; i < m + 1; i++)
            q = q->Next;
        p = q->Next;
        printf("%d, ", p->num);
        q->Next = p->Next;
        free(p);
    }
    printf("%d\n", q->num);
    free(q);
    end = clock();  // l?y th?i gian sau khi th?c hi?n 
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time= ", time_use);
    return 0;
}