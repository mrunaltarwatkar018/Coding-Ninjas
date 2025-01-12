/*
        Question  : Print All Substrings

        Problem statement
            For a given input string(str), write a function to print all the possible substrings.

            Substring
            A substring is a contiguous sequence of characters within a string. 
            
            Example: "cod" is a substring of "coding". Whereas, "cdng" is not as the characters taken are not contiguous
            
            Detailed explanation ( Input/output format, Notes, Images )
            Input Format:
            The first and only line of input contains a string without any leading and trailing spaces. All the characters in the string would be in lower case.
            
            Output Format:
            Print the total number of substrings possible, where every substring is printed on a single line and hence the total number of output lines will be equal to the total number of substrings.
            
            Note:
            The order in which the substrings are printed, does not matter.
            
            Constraints:
            0 <= N <= 10^6
            Where N is the length of the input string.

            Time Limit: 1 second
            
            Sample Input 1:
            abc
            
            Sample Output 1:
            a 
            ab 
            abc 
            b 
            bc 
            c 
            
            Sample Input 2:
            co
            
            Sample Output 2:
            c 
            co 
            o
*/

#include <iostream>
#include <cstring>
using namespace std;

// void printSubstrings(char input[]) {
//   // Write your code here
//   for (int start = 0; input[start] != '\0'; start++) {
//     for (int end = start; input[end] != '\0'; end++) {
//       for (int i = start; i <= end; i++) {
//         cout << input[i];
//       }
//       cout << endl;
//     }
//   }
// }


/*
Time complexity: O(N^3)
Space complexity: O(1)
where N is the length of the input string
*/
void printSubstrings(char input[]) {
int k = 1;
while (k <= strlen(input)) {
for (int i = 0; i <= strlen(input) - k; i++) {
for (int j = i; j < i + k; j++) {
cout << input[j];
}
cout << endl;
}
k++;
}
}


int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
}