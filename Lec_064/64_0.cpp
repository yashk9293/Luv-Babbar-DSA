// Question Link :- https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1
// ZigZag Tree Traversal

// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    vector<int> zigZagTraversal(Node *root) {
        vector<int> result;
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);          // here it is necessary to initialize the size, otherwise it will give SIGSEGV error

            // Level Process
            for (int i = 0; i < size; i++) {
                Node *frontNode = q.front();
                q.pop();

                // normal insert or reverse insert
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // direction change karni h
            leftToRight = !leftToRight;

            for (auto i : ans) {
                result.push_back(i);
            }
        }
        return result;
    }
};