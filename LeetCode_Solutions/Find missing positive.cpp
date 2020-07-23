#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive( vector<int>& nums )
{

    for( int i = 0; i < nums.size(); i++ )
    {
        if( nums[i] <= 0 )
        {
            nums[i] = INT_MAX;
        }
    }

    for( int i = 0; i < nums.size(); i++ )
    {
        int x = abs( nums[i] );
        if( x > 0 )
        {
            if( x <= nums.size() )
            {
                if(nums[x-1]>=0)
                    nums[ x - 1] = -1 * nums[x-1];
            }
        }
    }

    int i = 0, ans=0;
    for( i = 0; i < nums.size(); i++ )
    {
        if( nums[i] >= 0 )
        {
            ans = i + 1;
            break;
        }
    }
    if( i >= nums.size() )
        ans = i + 1;
    return ans;
}
/*
int main()
{
    vector<int>v = { 0,1,2 };
    cout << firstMissingPositive( v );
}
*/