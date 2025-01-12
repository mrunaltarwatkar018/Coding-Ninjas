/* =================================================================================================================== */
/* 
    Question  :     Code    : Min and Max of Binary Tree
                
                            For a given a Binary Tree of type integer, find and return 
                            the minimum and the maximum data values.
                            Return the output as an object of Pair class, which is 
                            already created.


                    Note    :
                            All the node data will be unique and hence there will 
                            always exist a minimum and maximum node data.

                    Input format    : 
                            The first and the only line of input will contain the 
                            node data, all separated by a single space. Since -1 
                            is used as an indication whether the left or right 
                            node data exist for root, it will not be a part of 
                            the node data.

                    Output Format : 
                            The only line of output prints two integers denoting 
                            the minimum and the maximum data values respectively. 
                            A single line will separate them both

                    Constraints :   
                                    2 <= N <= 10^4
                                    Where N is the total number of nodes in the binary tree.
                                    Time Limit: 1 sec

                    Sample Input 1 :    
                                    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
                                            
                    Sample Output 1 :   
                                    1 14

                    Sample Input 2 :    
                                    10 20 60 -1 -1 3 50 -1 -1 -1 -1  
                                            
                    Sample Output 2 :   
                                    3 60               
*/

#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/


// one method :

// #include <climits>
// pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
// 	// Write your code here
//     pair<int, int> p = {INT_MAX, INT_MIN};
//     if (root == NULL)
//         return p;
//     pair<int, int> a = {root -> data, root -> data};
//     pair<int, int> b = getMinAndMax(root -> left);
//     pair<int, int> c = getMinAndMax(root -> right);
//     a.first = min(a.first, min(b.first, c.first));
//     a.second = max(a.second, max(b.second, c.second));
//     return a;
// }


// Another Method : 

/*
        Time complexity: O(N)
        Space complexity: O(H)
        where N is the number of nodes in the input tree
        and H is the height of the input tree
*/
#include <climits>
/*
The first value of the pair is the minimum value in the tree and
the second value of the pair is the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    pair<int, int> ret = make_pair(INT_MAX, INT_MIN);
    if (root == NULL) {
        return ret;
    }
    
    pair<int, int> leftPair = getMinAndMax(root->left);
    pair<int, int> rightPair = getMinAndMax(root->right);
    ret.first = min(min(leftPair.first, rightPair.first), root->data);
    ret.second = max(max(leftPair.second, rightPair.second), root->data);
    return ret;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}