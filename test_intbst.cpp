#include "intbst.h"

#include <iostream>
using namespace std;


int main() {

    IntBST bst1;

    bst1.insert(0);
    bst1.insert(54);
    bst1.insert(20);
    bst1.insert(61);
    bst1.insert(35);
    bst1.insert(94);
    bst1.insert(31);
    bst1.insert(60);
    bst1.insert(-54);
    bst1.insert(-94);

    cout << "testing printing in order" << endl;
    cout << "Expected output: -94 -54 0 20 31 35 54 60 61 94" << endl;
    cout << "Actual output:   ";
    bst1.printPreOrder();
    
    cout << "\nremoving 94.\n";
    bool removed = bst1.remove(94);
    if (removed) {
        cout << "Print preorder:   ";
        bst1.printPreOrder();
    } else cout << "Removal unsuccessful." << endl;

    cout << "\nremoving 20.\n";
    removed = bst1.remove(20);
    if (removed) {
        cout << "Print pre order:   ";
        bst1.printPreOrder();
    } else cout << "Removal unsuccessful." << endl;

    cout << "\nremoving 54.\n";
    removed = bst1.remove(54);
    if (removed) {
        cout << "Print pre order:   ";
        bst1.printPreOrder();
    } else cout << "Removal unsuccessful." << endl;




    return 0;
}