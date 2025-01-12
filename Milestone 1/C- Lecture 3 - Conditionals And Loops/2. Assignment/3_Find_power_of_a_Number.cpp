/* =================================================================================================================== */
/* 
    Question  : Find power of a number
                
                Write a program to find x to the power n (i.e. x^n). 
                Take x and n from the user. You need to print the 
                answer.

                Note : 
                        For this question, you can assume that 0 raised 
                        to the power of 0 is 1

                Input format : 
                                Two integers x and n (separated by space)

                Output Format : 
                                x^n (i.e. x raise to the power n)

                Constraints :   
                                0 <= x <= 8 
                                0 <= n <= 9

                Sample Input 1 :    
                                    3 4 
                                          
                Sample Output 1 :   
                                    81

                Sample Input 2 :    
                                    2 5  
                                          
                Sample Output 2 :   
                                    32
*/


#include<iostream>
using namespace std;


// First Method
// int main() {
// 	// Write your code here
// 	int x;
// 	int n;
// 	cin >> x;
// 	cin >> n;

// 	int ans  = 1;
// 	int i = 0;

// 	while ( i < n ) {
// 		ans = ans * x;
// 		i++;
// 	}

// 	cout << ans << endl;

// 	return 0;
// }



// Second Method
#include<iostream>
using namespace std;
int main() {
    int x,n;
    cin>>x>>n;
    int ans=1;
    while(n>0){
        ans *=x;
        n--;
    }
    cout<<ans;
}
