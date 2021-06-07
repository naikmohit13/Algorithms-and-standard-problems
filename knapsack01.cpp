#include <iostream>

using namespace std;
int knapsack(int,int*,int*,int);
int main()
{
    //cout<<"Hello World";
    int n,capacity;
    cin>>capacity>>n;
    int w[n],amt[n];
    for(int i=0;i<n;i++)
        cin>>w[i];
    for(int i=0;i<n;i++)
        cin>>amt[i];
    
    cout<<knapsack(capacity,w,amt,n);

    return 0;
}
int knapsack(int capacity,int w[],int amt[],int n)
{
    int dp[n+1][capacity+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=capacity;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            
            else if(w[i-1]<=capacity)
                dp[i][j]=max(dp[i-1][j],amt[i-1]+dp[i-1][j-w[i-1]]);
            
            else
                dp[i][j]=dp[i-1][j];
            
        }
    }
        return dp[n][capacity];
}
