#include <iostream>
using namespace std;


template <typename T> class BinaryTree {


public:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T _data) : data(_data), left(NULL), right(NULL) {}
    };
    // Khởi tạo một cây rỗng
    BinaryTree() {
        root = NULL;
        size = 0;
    }

    // Bổ sung phần tử x trở thành nút cha của nút P trong cây
    void insertParent(T x, Node* P) {
        // Tạo một nút mới chứa giá trị x
        Node* newNode = new Node(x);
        // Nếu cây rỗng, thì gán newNode làm nút gốc
        if (root == NULL) root = newNode;
        else {
            // Gán newNode làm nút cha của P
            newNode->left = P;
            // Cập nhật lại cha của P
            if (P->left == NULL)
                P->left = newNode;
            else
                P->right = newNode;
        }
        size++;
    }

    // Bổ sung phần tử x trở thành nút con trái của nút P trong cây
    void insertLeftChild(T x, Node* P) {
        // Tạo một nút mới chứa giá trị x
        Node* newNode = new Node(x);
        // Gán newNode làm nút con trái của P
        P->left = newNode;
        size++;
    }

    // Bổ sung phần tử x trở thành nút con phải của nút P trong cây
    void insertRightChild(T x, Node* P) {
        // Tạo một nút mới chứa giá trị x
        Node* newNode = new Node(x);
        // Gán newNode làm nút con phải của P
        P->right = newNode;
        size++;
    }

    // Tìm node 
    Node* findNode(T x) {
        Node* curr = root;
        while (curr != nullptr) {
            if (curr->data == x) return curr;
            else if (curr->data > x) curr = curr->left;
            else curr = curr->right;
        }
        return nullptr;
    }

    // xóa node
    void deleteCurrentNode(Node* P) {
        if (P->left == nullptr && P->right == nullptr) {
            // P là nút lá
            if (P->parent->left == P) P->parent->left = nullptr;
            else P->parent->right = nullptr;
        }
        else if (P->left != nullptr && P->right != nullptr) {
            // P có cả hai nút con
            Node* successor = P->right;
            while (successor->left != nullptr) successor = successor->left;
            P->data = successor->data;
            deleteCurrentNode(successor);
        }
        else {
            // P chỉ có một nút con
            Node* child = (P->left != nullptr) ? P->left : P->right;
            if (P->parent->left == P) P->parent->left = child;
            else P->parent->right = child;
            child->parent = P->parent;
        }
        delete P;
        size--;
    }

    void deleteLeftChild(Node* P) {
        // Kiểm tra xem nút P có tồn tại hay không
        if (P != NULL) {
            // Lưu lại con trái của nút P
            Node* temp = P->leftChild;

            // Xóa con trái của nút P
            P->leftChild = NULL;

            // Xóa nút p
            deleteCurrentNode(temp);
        }
    }

    void deleteRightChild(Node* P) {
        // Kiểm tra xem nút P có tồn tại hay không
        if (P != NULL) {
            // Lưu lại con trái của nút P
            Node* temp = P->rightChild;

            // Xóa con trái của nút P
            P->rightChild = NULL;

            // Xóa nút p
            deleteCurrentNode(temp);
        }
    }

    int GetSize() {
        return size;
    }
private:

    Node* root;
    int size;
};

int main() {
    BinaryTree<int> cnp;
    cout << cnp.GetSize() << endl;

    BinaryTree<int> ::Node* child1;
    cnp.insertParent(1, child1);
    cout << cnp.GetSize() << endl;


}