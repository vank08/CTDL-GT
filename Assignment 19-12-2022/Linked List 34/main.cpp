#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

void inList(Node* h)
{
    Node* p = h;
    while (p)
    {
        cout << p->data << " -> ";
        p = p->link;
    }

    cout << "nullptr";
}

void dayvao(Node** controdenHead, int data)
{
    Node* newNode = new Node();

    newNode->data = data;
    newNode->link = *controdenHead;
    *controdenHead = newNode;
}

void loc(Node* headCopy)
{
    Node* nutTruoc = nullptr;
    Node* nutHientai = headCopy;

    unordered_set<int> set;

    while (nutHientai != nullptr)
    {      
        if (set.find(nutHientai->data) != set.end()) {
            nutTruoc->link = nutHientai->link;
        }
        else {
            set.insert(nutHientai->data);
            nutTruoc = nutHientai;
        }
        nutHientai = nutTruoc->link;
    }
}

int main()
{
    int mau[] = { 5, 3, 4, 2, 5, 4, 1, 3 };
    int n = sizeof(mau) / sizeof(mau[0]);

    Node* head = nullptr;

    for (int i = n - 1; i >= 0; i--) {
        dayvao(&head, mau[i]);
    }

    loc(head);

    inList(head);

    return 0;
}
