#include <iostream>
using namespace std;

const int N=100;
string s1="aabcdefgaa";
string s2="abcdefglll";
int dp[N][N];
int main()
{
    /*
       a a b c d e f g a a _
       _ a b c d e f g l l l
    */

    int n=s1.size(),m=s2.size();//n��m��
    for(int i=0;i<=m;i++){
        dp[0][i]=2*i;
    }
    for(int i=0;i<=n;i++){
        dp[i][0]=2*i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])
                dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]+2),dp[i][j-1]+2);
            else
                dp[i][j]=min(min(dp[i-1][j-1]+3,dp[i-1][j]+2),dp[i][j-1]+2);
        }
    }

    cout<<"min="<<dp[n][m]<<endl;
    return 0;
}
