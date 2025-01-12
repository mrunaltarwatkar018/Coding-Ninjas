/* =================================================================================================================== */
/* 
    Question  : Code : Count leaf nodes
                
                Given a generic tree, count and return the number of leaf 
                nodes present in the given tree.

                Input format : 
                                The first line of input contains data of the nodes of 
                                the tree in level order form. The order is: data for root 
                                node, number of children to root node, data of each of 
                                child nodes and so on and so forth for each node. The 
                                data of the nodes of the tree is separated by space.     

                Output Format : 
                                The first and only line of output prints the count of 
                                leaf nodes present in the given tree.

                Constraints :   
                                Time Limit: 1 sec

                Sample Input 1 :    
                                    10 3 20 30 40 2 40 50 0 0 0 0    
                                        
                Sample Output 1 :   
                                    4
                                
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

template <typename T>
class TreeNode {
    public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

// One Method

// int getLeafNodeCount(TreeNode<int> *root)
// {
//     // Write your code here
//     if (root == NULL)
//         return 0;
//     int count = 0;
//     if (root->children.size() == 0)
//         return 1;
//     for (int i = 0; i < root->children.size(); i++)
//         count = count + getLeafNodeCount(root->children[i]);
//     return count;
// }

// Another Method
/*
    Time complexity: O(N)
    Space complexity: O(H)
    where N is the number of nodes in the tree and
    H is the height/depth of the tree
*/
int getLeafNodeCount(TreeNode<int>* root) {
    
    int count = 0;

    if (root->children.size() == 0) {
        count++;
    }

    for (int i = 0; i < root->children.size(); i++) {
        count += getLeafNodeCount(root->children[i]);
    }
    
    return count;
}


int main() {
    TreeNode<int>* root = takeInputLevelWise();
    cout << getLeafNodeCount(root);
}