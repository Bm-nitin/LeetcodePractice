// leetcode 191. Number of 1 Bits
// Write a function that takes the binary representation of a positive integer and returns the number of set bits it has (also known as the Hamming weight).
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public: 
    string toBinary(int n){
        string ans;
        while(n){
            ans+=(n&1)+'0';
            n>>=1;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
   int hammingWeight(int n) {
        int ans=0;
        while(n){
            // n&1 gives the least significant bit of n, which is 1 if n is odd and 0 if n is even.
            // we can use this to count the number of set bits in n by adding n&1 to ans and then right shifting n by 1 to check the next bit.
            ans+=n&1;
            n>>=1;
        }
        return ans;
    }
    void seeThecountingbits(int n){
        while(n){
            cout<<"n: "<<n<<" n&1: "<<(n&1)<<endl;
            cout<<"Binary representation of n and one and work of & operator: "<<toBinary(n)<<" & "<<toBinary(1)<<" = "<<toBinary(n&1)<<endl;
            n>>=1;

        }
    }
};
int main(){
    Solution sol;
    int n;

    cout<<"Enter a positive integer: ";
    cin>>n;
    cout<<"Binary representation of "<<n<<" is: "<<sol.toBinary(n)<<endl;
    sol.seeThecountingbits(n);
    cout<<"Number of set bits in "<<n<<" is: "<<sol.hammingWeight(n)<<endl;
    return 0;
}