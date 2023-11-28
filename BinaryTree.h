//
// Created by henry on 11/27/2023.
//

#ifndef DISCUSSION_9_BINARYTREE_H
#define DISCUSSION_9_BINARYTREE_H

#endif //DISCUSSION_9_BINARYTREE_H

class BinaryTree{
private:
    struct Node{
        int val;
        Node* left;
        Node* right;
        Node(int aVal, Node* left = nullptr, Node* right = nullptr);
    };

    Node* root;
    void insert(Node* &aNodePtr, Node* &aNewNodePtr);
    void deleteNode(int aVal, Node* &aNodePtr);
    void makeDeletion(Node* &aNodePtr);
public:
    BinaryTree();
    void insertNode(int aVal);
    bool searchNode(int aVal);
    void remove(int aVal);
    void displayInOrder(Node* aNodePtr);
    void printTree();
};

BinaryTree::BinaryTree() {
    root = nullptr;
}

void BinaryTree::insert(BinaryTree::Node *&aNodePtr, BinaryTree::Node *&aNewNodePtr) {
    if(aNodePtr == nullptr)
        aNodePtr = aNewNodePtr;
    else if(aNewNodePtr->val < aNodePtr->val)
        insert(aNodePtr->left, aNewNodePtr);
    else
        insert(aNodePtr->right, aNewNodePtr);

}

void BinaryTree::deleteNode(int aVal, BinaryTree::Node *&aNodePtr) {
    if (aVal < aNodePtr->val){
        deleteNode(aVal, aNodePtr->left);
    }
    else if(aVal > aNodePtr->val){
        deleteNode(aVal, aNodePtr->right);
    }
    else{
        makeDeletion(aNodePtr);
    }
}

void BinaryTree::makeDeletion(BinaryTree::Node *&aNodePtr) {
    Node* tempNodePtr = nullptr;
    if(aNodePtr == nullptr)
        std::cout << "Cannot remove empty Node" << std::endl;
    else if(aNodePtr->right == nullptr) {
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else if(aNodePtr->right == nullptr){
        tempNodePtr = aNodePtr;
        aNodePtr = aNodePtr->right;
        delete tempNodePtr;
    }
    else
    {
        tempNodePtr = aNodePtr->right;

        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;

        tempNodePtr->left = aNodePtr->left;
        tempNodePtr = aNodePtr;
        aNodePtr = tempNodePtr->right;
        delete tempNodePtr;
    }
}

void BinaryTree::insertNode(int aVal) {
    Node* newNode = new Node(aVal);
    insert(root, newNode);
}

bool BinaryTree::searchNode(int aVal) {
    Node* currentNode = root;
    while(currentNode){
        if(currentNode-> val ==aVal){
            return true;
        }
        else if(aVal < currentNode->val){
            currentNode = currentNode->left;
        }
        else{
            currentNode = currentNode->right;
        }
    }
    return false;
}

void BinaryTree::remove(int aVal) {
    deleteNode(aVal, root);
}

void BinaryTree::displayInOrder(Node* aNodePtr){
    if (aNodePtr) {
        displayInOrder(aNodePtr->left);
        std::cout << aNodePtr->val << " ";
        displayInOrder(aNodePtr->right);
    }
}

void BinaryTree::printTree(){
    displayInOrder(root);
    std::cout << std::endl;
};