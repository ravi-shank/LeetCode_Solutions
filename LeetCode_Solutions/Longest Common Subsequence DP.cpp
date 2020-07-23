#include<bits/stdc++.h>
using namespace std;

int LCS( string& text1, string& text2 )
{
    int len1 = text1.length();
    int len2 = text2.length();

    vector<vector<int> >dp( len1 + 1, vector<int>( len2 + 1 ,0) );
    for( int i = 0; i <= len1; i++ )
    {
        for( int j = 0; j <= len2; j++ )
        {
            if( i == 0 || j == 0 )
                dp[i][j] = 0;
            else if( text1[i-1] == text2[j-1] )
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max( dp[i - 1][j], dp[i][j - 1] );
            }
        }
    }

    for( int i = 0; i <= len1; i++ )
    {
        for( int j = 0; j <= len2; j++ )
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[len1][len2];
}

/*
int main()
{

    string text1 = "abcde";
    string text2 = "abcd";
    cout << LCS( text1, text2 )<<endl;

}

*/
