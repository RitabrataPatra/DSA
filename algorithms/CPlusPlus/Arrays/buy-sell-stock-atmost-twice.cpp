//Question : Buy and Sell Stock atmost twice(advanced version of the question "best time to buy and sell stock" )

//Link : https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/0
//Time Complexity : O(n)
//Space Complexity : O(n)


//Approach : ⏬

//For each price in the list, update "min1" if the current price is lower, as it would be the best price to buy for the first transaction.

// Calculate the potential profit (curr1) from the first transaction by subtracting min1 from the current price. If this profit is higher than profit1, update profit1.


// For the second transaction, update "min2" by considering the cost of buying again after gaining the first profit. Calculate the potential profit (curr2) for the second transaction and update "profit2" if this profit is higher.

//Code Starts from below //👇

#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //varibles to store the two profits
           int profit1 = INT_MIN;
           int profit2 = INT_MIN;
           //variables to store the two minimum prices
           int min1 = INT_MAX;
           int min2 = INT_MAX;
           
           for(int i =0 ; i<price.size();i++){
               //for buying and selling the first time .i.e first transaction
               if(price[i] < min1){
                    min1 = price[i];      //basically updating the minimum-most price everytime we move through each element in array            
               }
               int curr1 = price[i] - min1; //finding the current profit
               if(curr1 > profit1){
                   profit1 = curr1;  //updating the maximum profit(i.e. highest profit till the current element that has been encountered)
               }
               //for second transaction
               min2 = min(min2 , price[i] - profit1);
               int curr2 = price[i] - min2;
               if(curr2 > profit2){
                   profit2 = curr2;
               }
               
           }
           return profit2;
        }
};

// Driver Code Starts.

int main(){
    int t;
    cout << "How many times you want to test : ";
    cin>>t;
    while(t--){
        
        int n;
        cout<<"Enter number of elements : ";
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<"Max profit after both transaction is : "<<obj.maxProfit(price)<<endl;
    }

}

//  Driver Code Ends