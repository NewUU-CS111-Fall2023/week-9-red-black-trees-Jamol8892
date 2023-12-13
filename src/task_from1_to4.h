class Node {
public:
  int data;
  Node* left;
  Node* right;
  Node* parent;
  bool color;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
    this->parent = nullptr;
      bool RED = false;
      this->color = RED;
  }
};

class RedBlackTree {
private:
  Node* root;

  Node* insert(Node* node, int data) {
    if (node == nullptr) {
      return new Node(data);
    }

    if (data < node->data) {
      node->left = insert(node->left, data);
      node->left->parent = node;
    } else {
      node->right = insert(node->right, data);
      node->right->parent = node;
    }

    if (isRed(node->left) && isBlack(node->right)) {
      leftRotate(node);
    } else if (isRed(node->right) && isBlack(node->right->left)) {
      rightRotate(node->right);
      leftRotate(node);
    } else if (isRed(node->right) && isRed(node->right->right)) {
      flipColors(node);
    }

    return node;
  }

  void leftRotate(Node* node) {
    Node* y = node->right;
    node->right = y->left;

    if (y->left != nullptr) {
      y->left->parent = node;
    }

    y->parent = node->parent;

    if (node->parent == nullptr) {
      root = y;
    } else if (node == node->parent->left) {
      node->parent->left = y;
    } else {
      node->parent->right = y;
    }

    y->left = node;
    node->parent = y;
  }

  void rightRotate(Node* node) {
    Node* x = node->left;
    node->left = x->right;

    if (x->right != nullptr) {
      x->right->parent = node;
    }

    x->parent = node->parent;

    if (node->parent == nullptr) {
      root = x;
    } else if (node == node->parent->right) {
      node->parent->right = x;
    } else {
      node->parent->left = x;
    }

    x->right = node;
    node->parent = x;
  }

  void flipColors(Node* node) {
    node->color = !node->color;
    node->left->color = !node->left->color;
    node->right->color = !node->right->color;
  }

  bool isRed(Node* node) {
      bool RED;
      return node != nullptr && node->color == RED;
  }

  bool isBlack(Node* node) {
      bool BLACK;
      return node == nullptr || node->color == BLACK;
  }

public:
  RedBlackTree() {
    root = nullptr;
  }

  void insert(int data) {
    root = insert(root, data);
  }

  void printTree() {
    printTree(root);
  }

private:
  void printTree(Node* node) {
    if (node == nullptr) {
      return;
    }

    printTree(node->left);
    std::cout << node->data << " ";
    printTree(node->right);
  }
};