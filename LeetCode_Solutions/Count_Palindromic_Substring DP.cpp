#include<bits/stdc++.h>
using namespace std;
int countSubstrings( string s )
{

    int len = s.length();
    vector<vector<bool> >dp(len+1, vector<bool>( len + 1 , false) );
    int totalCnt = 0;

    // mark substring of len 1 as palindromic
    for( int i = 0; i < len; i++ )
    {
        totalCnt++;
        dp[i][i] = true;
    }

    // mark substring of len 2 as palindromic
    for( int i = 1; i < len; i++ )
    {
        if( s[i - 1] == s[i] )
        {
            dp[i - 1][i] = true;
            totalCnt++;
        }
    }

    // mark substring of len>= 3 as palindromic
    for( int l = 3; l <= len; l++ )
    {
        for( int i = 0; i <= len - l; i++ )
        {
            int j = i + l-1;
            if( s[i] == s[j]  and dp[i+1][j-1]== true)
            {
                dp[i][j] = true;
                totalCnt++;
            }
        }
    }

    return totalCnt;
}
/*
int main()
{
    string s = "abaabcdbabcbababaaaabbbaaa";
    cout << countSubstrings( s );
}
*/