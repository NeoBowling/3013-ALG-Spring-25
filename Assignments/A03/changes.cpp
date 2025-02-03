Node* findMin(Node* node) {
    while (node && node->left) node = node->left;
    return node;
}


Node* _Delete(Node* root, int x) {
    if (!root) return root;  // Base case: key not found

    if (x < root->data)
        root->left = _Delete(root->left, x);  // Search in left subtree
    else if (x > root->data)
        root->right = _Delete(root->right, x);  // Search in right subtree
    else {
        // Case 1: Node has no child (leaf)
        if (!root->left && !root->right) {
            delete root;
            return nullptr;
        }

        // Case 2: Node has only one child
        else if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // Case 3: Node has two children
        Node* temp = findMin(root->right);  // In-order successor
        root->data = temp->data;  // Copy successor value
        root->right = _Delete(root->right, temp->data);  // Delete successor
    }
    return root;
}
