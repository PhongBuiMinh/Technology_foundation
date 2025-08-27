#include <iostream>
using std::cin;
using std::cout;

class binaryTree {
    public:
        int countLeaf();
    private:
        struct treeNode {
            int data;
            treeNode * leftNode;
            treeNode * rightNode;
        };
        typedef treeNode * treePtr;
        treePtr _root;
        int countLeaf(treePtr _root) {
            if (_root == NULL) return 0;
            if (_root->leftNode == NULL && _root->rightNode == NULL) return 1;
            int leftRoot = countLeaf(_root->leftNode);
            int rightRoot = countLeaf(_root->rightNode);
            return leftRoot + rightRoot;
        }
};

int binaryTree::countLeaf() {
    return countLeaf(_root);
}

struct listNode {
    int data;
    listNode * next;
};
typedef listNode * listPtr;

void displayForwardsNode(listPtr head) {
    if (head != 0) {
        cout << head->data << "\n";   
        displayForwardsNode(head->next);
    }
}

void displayBackwardsNode(listPtr head) {
    if (head != 0) {
        cout << head->data << "\n";   
        displayForwardsNode(head->next);
    }
}

int main() {
    binaryTree bt;
    int leaf = bt.countLeaf();
    
}