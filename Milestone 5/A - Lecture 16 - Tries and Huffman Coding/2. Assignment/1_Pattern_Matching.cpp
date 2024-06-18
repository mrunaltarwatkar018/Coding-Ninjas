/* =================================================================================================================== */
/* 
    Question  : Pattern Matching
                
                Given a list of n words and a pattern p that we want to 
                search. Check if the pattern p is present the given words 
                or not. Return true if the pattern is present and false 
                otherwise.

                Input format : 
                        The first line of input contains an integer, that denotes 
                        the value of n.
                        The following line contains n space-separated words.
                        The following line contains a string, that denotes the 
                        value of the pattern p.

                Output Format : 
                        The first and only line of output contains true 
                        if the pattern is present and false otherwise.

                Constraints :  
                        Time Limit: 1 sec


                Sample Input 1 :    
                        4
                        abc def ghi cba
                        de
                                          
                Sample Output 1 :   
                        true

                Sample Input 2 :    
                        4
                        abc def ghi hg
                        hi
                                          
                Sample Output 2 :   
                        true

                Sample Input 3 :    
                        4
                        abc def ghi hg
                        hif
                                          
                Sample Output 3 :   
                        false
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// // One Method
#include <string>
#include <vector>

// One method

// class TrieNode
// {
// public:
//     char data;
//     TrieNode **children;
//     bool isTerminal;

//     TrieNode(char data)
//     {
//         this->data = data;
//         children = new TrieNode *[26];
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//     }
// };

// class Trie
// {
//     TrieNode *root;

// public:
//     int count;

//     Trie()
//     {
//         this->count = 0;
//         root = new TrieNode('\0');
//     }

//     bool insertWord(TrieNode *root, string word)
//     {
//         // Base case
//         if (word.size() == 0)
//         {
//             if (!root->isTerminal)
//             {
//                 root->isTerminal = true;
//                 return true;
//             }
//             else
//             {
//                 return false;
//             }
//         }

//         // Small calculation
//         int index = word[0] - 'a';
//         TrieNode *child;
//         if (root->children[index] != NULL)
//         {
//             child = root->children[index];
//         }
//         else
//         {
//             child = new TrieNode(word[0]);
//             root->children[index] = child;
//         }

//         // Recursive call
//         return insertWord(child, word.substr(1));
//     }

//     void insertWord(string word)
//     {
//         if (insertWord(root, word))
//         {
//             this->count++;
//         }
//     }

//     bool search(TrieNode *parent, string word)
//     {
//         if (word.size() == 0)
//             return true;
//         if (parent->children[word[0] - 'a'] != NULL)
//             return search(parent->children[word[0] - 'a'], word.substr(1));
//         else
//             return false;
//     }

//     bool search(string word)
//     {
//         // Write your code here
//         if (word.size() == 0)
//             return false;
//         return search(root, word);
//     }

//     bool patternMatching(vector<string> vect, string pattern)
//     {
//         // Write your code here
//         for (int i = 0; i < vect.size(); i++)
//         {
//             while (vect[i] != "")
//             {
//                 insertWord(vect[i]);
//                 vect[i] = vect[i].substr(1);
//             }
//         }
//         return search(pattern);
//     }
// };


// Another Method

/*
    Time complexity: O(N * M)
    Space complexity: O(N * M)

    where N is the number of words in the Trie and M is the average word length
*/
class TrieNode {
    public:
        char data;
        TrieNode **children;
        bool isTerminal;

        TrieNode(char data) {
            this->data = data;
            children = new TrieNode *[26];
            for (int i = 0; i < 26; i++) {
                children[i] = NULL;
            }
            isTerminal = false;
        }
};

class Trie {
    TrieNode *root;

    public:
        int count;

        Trie() {
            this->count = 0;
            root = new TrieNode('\0');
        }

        bool insertWord(TrieNode *root, string word) {
            // Base case
            if (word.size() == 0) {
                if (!root->isTerminal) {
                root->isTerminal = true;
                    return true;
                } else {
                    return false;
                }
            }

            // Small calculation
            int index = word[0] - 'a';
            TrieNode *child;
            if (root->children[index] != NULL) {
                child = root->children[index];
            } else {
                child = new TrieNode(word[0]);
                root->children[index] = child;
            }

            // Recursive call
            return insertWord(child, word.substr(1));
        }

        // For user
        void insertWord(string word) {
            if (insertWord(root, word)) {
                this->count++;
            }
        }

        bool search(TrieNode *root, string word) {
            if (word.size() == 0) {
                return true;
            }

            // Small calculation
            int index = word[0] - 'a';
            TrieNode *child;

            if (root->children[index] != NULL) {
                child = root->children[index];
            } else {
                return false;
            }

            // Recursive call
            return search(child, word.substr(1));
        }

        bool search(string word) {
            return search(root, word);
        }

        bool patternMatching(vector<string> vect, string pattern) {
            for (int i = 0; i < vect.size(); i++) {
                string word = vect[i];
                for (int j = 0; j < word.length(); j++) {
                    insertWord(word.substr(j));
                }
            }

            return search(pattern); 
        }
};


int main() {
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}





