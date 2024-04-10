#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
    int co, po;
    Node* addr;
};

typedef Node* Polynomial;

Node* createNode(int co, int po) {
    Node* temp = new Node;
    temp->co = co;
    temp->po = po;
    temp->addr = nullptr;
    return temp;
}

Polynomial insertEnd(Polynomial start, int co, int po) {
    Node* temp = createNode(co, po);

    if (start == nullptr) {
        return temp;
    }

    Node* cur = start;
    while (cur->addr != nullptr)
        cur = cur->addr;
    cur->addr = temp;
    return start;
}

void display(Polynomial start) {
    Node* temp = start;
    if (temp == nullptr) {
        cout << "\nPolynomial Empty";
        return;
    }
    while (temp->addr != nullptr) {
        cout << temp->co << "x^" << temp->po << " + ";
        temp = temp->addr;
    }
    cout << temp->co << "x^" << temp->po << endl;
}

Polynomial addTerm(Polynomial res, int co, int po) {

    if (res == nullptr) {
        return createNode(co, po);
    }

    Node* cur = res;
    while (cur != nullptr) {
        if (cur->po == po) {
            cur->co += co;
            return res;
        }
        cur = cur->addr;
    }

    if(cur==NULL)
        res=insertEnd(res,co,po);
    return res;

}

Polynomial multiply(Polynomial poly1, Polynomial poly2) {
    Polynomial res = nullptr;
    for (Node* p1 = poly1; p1 != nullptr; p1 = p1->addr) {
        for (Node* p2 = poly2; p2 != nullptr; p2 = p2->addr) {
            res = addTerm(res, p1->co * p2->co, p1->po + p2->po);
        }
    }
    return res;
}

int main() {
    Polynomial poly1 = nullptr, poly2 = nullptr, poly = nullptr;
    int co, po, n, m;

    cout << "\nRead no of terms of first polynomial:";
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << "\nRead CO and PO of " << i << " term : ";
        cin >> co >> po;
        poly1 = insertEnd(poly1, co, po);
    }
    cout << "\nFirst polynomial is\n";
    display(poly1);

    cout << "\nRead no of terms of second polynomial:";
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cout << "\nRead CO and PO of " << i << " term : ";
        cin >> co >> po;
        poly2 = insertEnd(poly2, co, po);
    }
    cout << "\nSecond polynomial is\n";
    display(poly2);

    poly = multiply(poly1, poly2);
    cout << "\nResultant polynomial is\n";
    display(poly);

    return 0;
}
