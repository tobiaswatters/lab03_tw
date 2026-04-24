#include "intbst.h"

#include <iostream>
using namespace std;


int main() {

    IntBST bst1;

    bst1.insert(5);
    bst1.insert(3);
    bst1.insert(-4);
    bst1.insert(-12);
    bst1.insert(7);
    bst1.insert(13);
    bst1.insert(9);
    bst1.insert(18);
    bst1.insert(0);
    bst1.insert(-7);
    bst1.insert(-11);

    cout << "testing printing in order" << endl;
    cout << "Expected output: -94 -54 0 20 31 35 54 60 61 94" << endl;
    cout << "Actual output:   ";
    bst1.printPreOrder();
    
    cout << "\nremoving 3.\n";
    bool removed = bst1.remove(3);
    if (removed) {
        cout << "Print preorder:   ";
        bst1.printPreOrder();
    } else cout << "Removal unsuccessful." << endl;

    cout << "\nremoving 13.\n";
    removed = bst1.remove(13);
    if (removed) {
        cout << "Print pre order:   ";
        bst1.printPreOrder();
    } else cout << "Removal unsuccessful." << endl;


    return 0;
}