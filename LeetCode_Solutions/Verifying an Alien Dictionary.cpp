#include<bits/stdc++.h>
using namespace std;

bool IsLexoSmall( const string& a, const string& b , const vector<int>&orderArr)
{
    int i = 0, j = 0;
    while( i < a.length() and j < b.length() )
    {
        if( a[i] == b[j] )
        {
            i++; j++;
        }
        else
        {
            if( orderArr[a[i] - 'a'] > orderArr[b[j] - 'a'] )
                return false;
            else
                return true;
        }
    }
    if( a.length() == b.length() )
        return true;
    else if( a.length() > b.length() )
        return false;
    else
        return true;
}
bool isAlienSorted( vector<string>& words, string order )
{
    vector<int>orderArr(26 ,-1);

    for( int i = 0; i < order.size(); i++ )
    {
        orderArr[order[i] - 'a'] = i;
    }

    bool res = false;
    for( int i = 0; i < words.size(); i++ )
    {
        string curStr = words[i];
        for( int j = i + 1; j < words.size(); j++ )
        {
            if( ! IsLexoSmall( curStr, words[j], orderArr ) ) // if curStr is smaller than word[j]
            {
                return false;
            }
        }
    }

    return true;
}
/*
int main()
{
	vector<string>words = { "cb", "ca", "cd", "cz" };
	string order = "cbadefghijklmnopqrstuvwxyz";
    cout << isAlienSorted( words, order ) << endl;
}
*/