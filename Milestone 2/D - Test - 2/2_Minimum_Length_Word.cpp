/* =================================================================================================================== */
/* 
    Question  : Minimum Length Word
                
                Given a string S (that can contain multiple words), you 
                need to find the word which has minimum length.

                Note :  If multiple words are of same length, then 
                        answer will be first minimum length word in the string.
                        Words are seperated by single space only.

                Input format : 
                                String S

                Output Format : 
                                Minimum length word

                Constraints :   
                                1 <= Length of String S <= 10^5

                Sample Input 1 :    
                                    this is test string 
                                          
                Sample Output 1 :   
                                    is

                Sample Input 2 :    
                                    abc de ghihjk a uvw h j 
                                          
                Sample Output 2 :   
                                    a
                                   
*/

#include<iostream>
using namespace std;

// One Method
int strlen(char input[]) {
    int count = 0;
    for (int i = 0; input[i] != '\0'; i++) {
        count++;
    }
    return count;
}

void saveOutput(char input[], char output[], int start, int end) {
    int j = 0;
    while (start <= end) {
        output[j] = input[start];
        j++;
        start++;
    }
    output[j] = '\0';
}

void minLengthWord(char input[], char output[]) {

    // Write your code here
    int min = 100000;
    int count = 0;
    int start = 0;

    for (int i = 0; input[i] != '\0'; i++) {

        if (i == (strlen(input) - 1)) {
            count++;
            if (min > count) {
                min = count;
                saveOutput(input, output, start, i);
            }
        } else if (input[i] != ' ') {
            count++;
        } else {
            if (min > count) {
                min = count;
                saveOutput(input, output, start, i - 1);
            }
            count = 0;
            start = i + 1;
        }
    }
}


// Another Approach
#include <climits>
#include <cstring>
void minLengthWord(char input[], char output[]){
    int minStart = -1;
    int minLength = INT_MAX;
    int currentStart = 0;
    int i = 0;
    int len = strlen(input);
    for(; i < len; i++){
        if(input[i] == ' '){
            int currentWordLength = i - currentStart;
            if(currentWordLength < minLength){
                minStart = currentStart;
                minLength = currentWordLength;
            }
            currentStart = i + 1;
        }
    }
    if(minStart == -1){
        for(int i = 0; i <= len; i++) {
            output[i] = input[i];
        }
    } else {
        int currentWordLength = i - currentStart;
        if(currentWordLength < minLength){
            minStart = currentStart;
            minLength = currentWordLength;
        }
        int j = 0;
        for(int i = minStart; i < minStart + minLength; i++) {
            output[j++] = input[i];
        }
        output[j] = '\0';
    }
}

int main(){
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
