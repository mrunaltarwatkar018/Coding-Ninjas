/*
        Question  : Return Keypad Code

        Problem statement
            Given an integer n, using phone keypad find out all the 
            possible strings that can be made using digits of input n.

            Return empty string for numbers 0 and 1.

            Note :
            1. The order of strings are not important.
            2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
            
            Detailed explanation ( Input/output format, Notes, Images )
            
                Input Format :
                Integer n
                
                Output Format :
                All possible strings in different lines
                
                Constraints :
                1 <= n <= 10^6

                Sample Input:
                23
                
                Sample Output:
                ad
                ae
                af
                bd
                be
                bf
                cd
                ce
                cf

*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
#include <string>
using namespace std;

string pad(int key)
{
    unordered_map<int, string> dial;
    dial[0] = "";
    dial[1] = "";
    dial[2] = "abc";
    dial[3] = "def";
    dial[4] = "ghi";
    dial[5] = "jkl";
    dial[6] = "mno";
    dial[7] = "pqrs";
    dial[8] = "tuv";
    dial[9] = "wxyz";

    return dial[key];
}

int keypad(int num, string output[])
{
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int smallOutSize = keypad(num / 10, output);

    string pd = pad(num % 10);
    int newsize = pd.size() * smallOutSize;
    // Copy
    string temp[10000];
    for (int i = 0; i < 10000; i++)
        temp[i] = output[i];

    for (int i = 0; i < pd.size(); i++)
    {

        for (int j = 0; j < smallOutSize; j++)
        {
            output[j + i * smallOutSize] = temp[j] + pd[i];
        }
    }
    return newsize;
}



// #include <iostream>
// #include <string>
// using namespace std;
// int keypad(int num, string output[], string options[])
// {
//     if (num == 0)
//     {
//         output[0] = "";
//         return 1;
//     }
//     int lastDigit = num % 10;
//     int smallNumber = num / 10;
//     string smallOutput[500];
//     int smallCount = keypad(smallNumber, smallOutput, options);
//     string op = options[lastDigit];
//     int k = 0;
//     for (int i = 0; i < op.length(); i++)
//     {
//         for (int j = 0; j < smallCount; j++)
//         {
//             output[k] = smallOutput[j] + op[i];
//             k++;
//         }
//     }
//     return k;
// }
// int keypad(int num, string output[])
// {
//     string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
//     return keypad(num, output, options);
// }


int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}