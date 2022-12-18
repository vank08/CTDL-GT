#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

void inList(struct Node* h)
{
    struct Node* p = h;
    while (p)
    {
        printf("%d -> ", p->data);
        p = p->link;
    }

    printf("NULL\n");
}

void dayvao(struct Node** controdenHead, int data)
{
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->link = *controdenHead;
    *controdenHead = newNode;
}

struct Node* gopList(struct Node* a, struct Node* b)
{
    if (a == NULL) {
        return b;
    }

    else if (b == NULL) {
        return a;
    }

    struct Node* Listgop = NULL;

    if (a->data <= b->data)
    {
        Listgop = a;
        Listgop->link = gopList(a->link, b);
    }
    else {
        Listgop = b;
        Listgop->link = gopList(a, b->link);
    }

    return Listgop;
}

int main(void)
{
    int in[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(in) / sizeof(in[0]);

    struct Node* a = NULL, * b = NULL;

    for (int i = n - 1; i >= 0; i = i - 2) {
        dayvao(&a, in[i]);
    }

    for (int i = n - 2; i >= 0; i = i - 2) {
        dayvao(&b, in[i]);
    }

    printf("List thu nhat: ");
    inList(a);

    printf("List thu hai: ");
    inList(b);

    struct Node* h = gopList(a, b);
    printf("List sau khi gop: ");
    inList(h);

    return 0;
}
