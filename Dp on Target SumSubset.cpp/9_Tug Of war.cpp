// https://nados.io/question/tug-of-war

#include<bits/stdc++.h>
using namespace std;


int mindiff = INT_MAX ;
string s1Ans = "", s2Ans = "";
void helper(vector<int> arr, int idx, string s1, int s1Sum, int s1Len, string s2, 
    int s2Sum, int s2Len) {
        if (idx == arr.size()) {
            int diff = abs(s1Sum - s2Sum);

            if (arr.size() % 2 == 1 && (s1Len == s2Len + 1 || s2Len == s1Len + 1) && diff < mindiff) {
                s1Ans = s1.substr(2);
                s2Ans = s2.substr(2);
                mindiff = diff;
            }

            else if (arr.size() % 2 == 0 && s1Len == s2Len && diff < mindiff) {
                s1Ans = s1.substr(2);
                s2Ans = s2.substr(2);
                mindiff = diff;
            }

            return;
        }

        // Element is inserted in S1
        helper(arr, idx + 1, s1 + ", " + to_string(arr[idx]), s1Sum + arr[idx], s1Len + 1, s2, s2Sum, s2Len);

        // Element in inserted in S2
        helper(arr, idx + 1, s1, s1Sum, s1Len, s2 + ", " + to_string(arr[idx]), s2Sum + arr[idx], s2Len + 1);
    }


int main(){
    int n ;
    cin >> n ;
    vector<int > arr (n );
    for(auto &x : arr){
        cin >> x;
    }

    // you have to partition array into two equal subset with size n/2 , n/ 2 if n is even 
    //otherwise n / 2 - 1 or n / 2 + 1 ;

    // you can done using recursion if question ask to print ;
    // if want number of subset then you have to store in dp 
    // dp[sizeOfSubset][sum][idx] => 3D DP -> Dp on bitmasking question

    helper(arr, 0, "", 0, 0, "", 0, 0);
    cout<< ("[" + s1Ans + "] [" + s2Ans + "]") << endl;
    return 0;
}

