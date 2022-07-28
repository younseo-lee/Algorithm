#include <iostream>
using namespace std;

struct node {
    char left; 
    char right;
};
struct node alpha[26];

void preorder(int search);
void inorder(int search);
void postorder(int search);

int main(void) {
    int N;
    cin >> N;

    char node, left, right;
    for(int i = 0; i < N; i++) {
        cin >> node >> left >> right; 
        alpha[node - 'A'].left = left; 
        alpha[node - 'A'].right = right;
    }

    preorder(0);
    cout << endl;
    inorder(0);
    cout << endl;
    postorder(0);
    cout << endl;

    return 0;
}

// 전위 순회
void preorder(int search) {
    cout << (char)(search + 'A');
    if(alpha[search].left != '.') preorder(alpha[search].left - 'A');
    if(alpha[search].right != '.') preorder(alpha[search].right - 'A');
    return;
}

// 중위 순회
void inorder(int search) {
    if(alpha[search].left != '.') inorder(alpha[search].left - 'A');
    cout << (char)(search + 'A');
    if(alpha[search].right != '.') inorder(alpha[search].right - 'A');
    return;
}

// 후위 순회
void postorder(int search) {
    if(alpha[search].left != '.') postorder(alpha[search].left - 'A');
    if(alpha[search].right != '.') postorder(alpha[search].right - 'A');
    cout << (char)(search + 'A');
    return;
}