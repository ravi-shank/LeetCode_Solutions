#include<bits/stdc++.h>
using namespace std;
bool IsSatisfied( map<char, int>& freqS, map<char, int>& freqT )
{
    for( auto mit = freqT.begin(); mit != freqT.end(); mit++ )
    {
        char c = mit->first;
        if( freqS[c] < freqT[c] )
            return false;
    }

    return true;
}

string minWindow( string s, string t )
{

    map<char, int>freqS;
    map<char, int>freqT;
    for( int i = 0; i < t.length(); i++ )
        freqT[t[i]]++;

    int ansLow = 0, ansHigh = 0;
    int low = 0, high = 0, minLen = INT_MAX;

    while( high < s.length() )
    {
        freqS[s[high]]++;
        high++;
        if( high - low < minLen and IsSatisfied( freqS, freqT ) )
        {
            ansLow = low;
            ansHigh = high;
            minLen = high - low;
        }

        while( low < high and low < s.length() )
        {
            char c = s[low];
            if( freqT.find( c ) != freqT.end() )
            {
                if( freqS[c] > freqT[c] )
                {
                    freqS[c]--;
                    low++;
                    if(high - low < minLen and  IsSatisfied( freqS, freqT ) )
                    {
                        ansLow = low;
                        ansHigh = high;
                        minLen = high - low;
                    }
                }
                else
                    break;
            }
            else
            {
                if( IsSatisfied( freqS, freqT ) )
                {
                    freqS[s[low]]--;
                    low++;
                    if( high - low < minLen )
                    {
                        ansLow = low;
                        ansHigh = high;
                        minLen = high - low;
                    }
                }
                else
                    break;
                
            }
            

        }

    }
    string ans = "";
    for( int i = ansLow; i < ansHigh; i++ )
        ans += s[i];
    return ans;

}
/*
int main()
{
    string s = "";
    string t = "ac";
    cout << minWindow( s, t ) << endl;
}
*/