#include<bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  struct Node* left;
  struct Node* right;
};

Node* newNode(int a) {
  Node* temp = new Node;
  temp -> val = a;
  temp -> left = temp -> right = NULL;
  return temp;
}

int main() {
  Node* root = newNode(1);
  root -> left = newNode(2);
  root -> right = newNode(3);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(5);
  root -> right -> left = newNode(6);
  root -> right -> right = newNode(7);

  return 0;
}
