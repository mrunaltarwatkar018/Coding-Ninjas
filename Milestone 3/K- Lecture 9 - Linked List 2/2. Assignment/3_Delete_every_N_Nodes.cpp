/* =================================================================================================================== */
/* 
    Question  : Delete every N nodes
                
                You have been given a singly linked list of integers along 
                with two integers, 'M,' and 'N.' Traverse the linked list such 
                that you retain the 'M' nodes, then delete the next 'N' nodes. 
                Continue the same until the end of the linked list.

                To put it in other words, in the given linked list, you need to 
                delete N nodes after every M nodes.

                Note :  
                        No need to print the list, it has already been taken 
                        care. Only return the new head to the list.

                Input format : 
                                The first line contains an Integer 't' which denotes the 
                                number of test cases or queries to be run. Then the test 
                                cases follow.

                                The first line of each test case or query contains the 
                                elements of the singly linked list separated by a single 
                                space.

                                The second line of input contains two integer values 
                                'M,' and 'N,' respectively. A single space will 
                                separate them.

                Remember/Consider :
                                While specifying the list elements for input, -1 
                                indicates the end of the singly linked list and 
                                hence, would never be a list element

                Output Format : 
                                For each test case/query, print the elements of the 
                                updated singly linked list.

                                Output for every test case will be printed in a 
                                separate line.

                Constraints :   1 <= t <= 10^2
                                0 <= P <= 10^5
                                Where P is the size of the singly linked list.
                                0 <= M <= 10^5
                                0 <= N <= 10^5
                                
                                Time Limit: 1 sec

                Sample Input 1 :    1
                                    1 2 3 4 5 6 7 8 -1    
                                    2 2
                                          
                Sample Output 1 :   1 2 5 6

                Sample Input 2 :    2
                                    10 20 30 40 50 60 -1
                                    0 1
                                    1 2 3 4 5 6 7 8 -1
                                    2 3
                                          
                Sample Output 2 :   1 2 6 7

                Explanation of Sample Input 2 : 
                                    For the first query, we delete one node after every 
                                    zero elements hence removing all the items of the list. 
                                    Therefore, nothing got printed.

                                    For the second query, we delete three nodes after 
                                    every two nodes, resulting in the final list, 
                                    1 -> 2 -> 6 -> 7.
                                                
*/


#include <iostream>

class Node {
public:
	int data;
	Node *next;
	Node(int data) {
		this->data = data;
		this->next = NULL;
	}
};

/*
    Time Complexity : O(n)
    Space Complexity : O(1)
    where n is the size of singly linked list
*/

/*
Node *skipMdeleteN( Node *head, int M, int N ) {
    if ( M == 0 || head == NULL ) {
        return NULL;
    }

    if ( N == 0 ) {
        return head;
    }

    Node *currentNode = head;
    Node *temp = NULL;          // temp will keep a copy of currentNode as we modify the list

    while ( currentNode != NULL ) {
        int take = 0;
        int skip = 0;

        while ( currentNode != NULL && take < M ) {
            if ( temp == NULL ) {
                temp = currentNode;
            } else {
                temp -> next = currentNode;
                temp = currentNode;
            }

            currentNode = currentNode -> next;
            take++;
        }

        while ( currentNode != NULL && skip < N ) {
            Node *newNode = currentNode;
            delete currentNode;         // excliptely delete the last node 
            currentNode = newNode -> next;
            skip++;
        }
    }

    if ( temp != NULL ) {
        temp -> next = NULL;
    }

    return head;
}
*/


int length(Node *head)
{
    // Write your code here
    int len = 0;
    Node *current = head;
    while (current != NULL)
    {
        len++;
        current = current->next;
    }
    return len;
}

Node *skipMdeleteN(Node *head, int M, int N)
{
    // Write your code here
    if (head == NULL)
        return head;
    int len = length(head);
    int m = M, n = N;
    Node *current = head;
    Node *prev = NULL;
    while (current != NULL)
    {
        if (m != 0)
        {
            prev = current;
            current = current->next;
            m--;
        }
        if (m == 0 && n != 0)
        {
            if (M != 0)
            {
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
            else
            {
                prev = current->next;
                delete current;
                current = prev;
                head = current;
            }
            n--;
        }
        if (m == 0 && n == 0)
        {
            m = M;
            n = N;
        }
    }
    return head;
}


using namespace std;

Node *takeinput() {
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1) {
		Node *newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print( Node *head ) {
    Node *temp = head;
    while ( temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main()
{
	int t;
    cout << "Enter the Number of testCases : ";
	cin >> t;
	while (t--)
	{
        cout << "Enter the Input Linked List : ";
		Node *head = takeinput();
        int m, n;
        cout << "Enter the value of M and N : ";
        cin >> m >> n;
        cout << "Updated Linked List : ";
		head = skipMdeleteN( head, m, n );
        print(head);
	}
    return 0;
}