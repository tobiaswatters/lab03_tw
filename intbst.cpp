// intbst.cpp
// Implements class IntBST
// TOBIAS WATTERS   APRIL 16

#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if (!n) return;
    return clear(n->left);
    return clear(n->right);
    delete n;
    return;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) { // Public
    if (!root){
        root = new Node(value);
    }
    return insert(value, root);
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) { // private
    if (n->info == value) {return false;} 
    else if (value < n->info) {
        if (!n->left) {
            n->left = new Node(value);
            n->left->parent = n;
            return true;
        }
        return insert(value, n->left);
    } else {
        if (!n->right) {
            n->right = new Node(value);
            n->right->parent = n;
            return true;
        }
        return insert(value, n->right);
    }
}

// print tree data pre-order PUBLIC
void IntBST::printPreOrder() const {
    printPreOrder(root);
}

// recursive helper for printPreOrder() PRIVATE
void IntBST::printPreOrder(Node *n) const {
    if (!n) return;
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper PUBLIC
void IntBST::printInOrder() const {
    printInOrder(root);
}

void IntBST::printInOrder(Node *n) const { // PRIVATE
    if (!n) return;
    printInOrder(n->left);
    cout << n->info<< " ";
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const { // PUBLIC
    printPostOrder(root);
}

void IntBST::printPostOrder(Node *n) const { // PRIVATE
    if (!n) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info << " ";
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root);
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if (!n) return 0;
    return sum(n->left) + sum(n->right) + n->info;
}

// return count of values
int IntBST::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if (!n) return 0;
    return count(n->left) + count(n->right) + 1;
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const {
    if (!n) return nullptr;
    if (n->info == value) {return n;}
    else if (value < n->info) return getNodeFor(value, n->left);
    return getNodeFor(value, n->right);
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if (getNodeFor(value, root) == nullptr) return false;
    return true;
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    Node* predecessor(0);
    if (n->left) {
        predecessor = n->left;
        while (predecessor->right)
            predecessor = predecessor->right;
        return predecessor;
    } else if (n->parent) {
        predecessor = n->parent;
        while (predecessor->parent) {
            if (predecessor->info < n->info) return predecessor;
            predecessor = predecessor->parent;
        }
    }
    return 0;
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if (!getPredecessorNode(value)) return 0;
    return getPredecessorNode(value)->info;
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* n = getNodeFor(value, root);
    Node* successor(0);
    if (n->right) {
        successor = n->right;
        while (successor->left) 
            successor = successor->left;
        return successor;
    } else if (n->parent) { // traverse back up tree to find successor
        successor = n->parent;
        while (successor->parent) {
            if (successor->info > n->info) return successor;
            successor = successor->parent;
        }
    }
    return 0;
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if (!getSuccessorNode(value)) return 0;
    return getSuccessorNode(value)->info;
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if (!n) return false;

    if (!n->left && !n->right) {
        if (n == root) {
            root = 0;
        } else if (n->parent->left == n) {
            n->parent->left = 0;
        } else {
            n->parent->right = 0;
        }
        delete n;
        return true;
    } 
    else if (n->left && !n->right) {
        if (n == root) {
            root = n->left;
            n->left->parent = 0;
        } else if (n->parent->left == n) {
            n->parent->left = n->left;
            n->left->parent = n->parent;
        } else {
            n->parent->right = n->left;
            n->left->parent = n->parent;
        }
        delete n;
        return true;
    } 
    else if (n->right && !n->left) {
        if (n == root) {
            root = n->right;
            n->right->parent = 0;
        } else if (n->parent->left == n) {
            n->parent->left = n->right;
            n->right->parent = n->parent;
        } else {
            n->parent->right = n->right;
            n->right->parent = n->parent;
        }
        delete n;
        return true;
    } else { // two children
        Node* successor = getSuccessorNode(n->info);

        int temp = successor->info;

        remove(successor->info);

        n->info = temp;

        return true;
/*
        if (successor == n->right) {
            n->right = child;
        } else {
            successor->parent->left = child;
        }
        if (child) {
            child->parent = successor->parent;
        }
        delete successor;
        return true;
    */
    }

    return false;
}
