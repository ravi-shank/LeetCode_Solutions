#include<bits/stdc++.h>
using namespace std;              
bool Solve( vector<int>& nums )
{
    int cnt = 0, mx = INT_MIN;
    if( nums.size() <= 0 )
        return true;
    mx = nums[0];
    for( int i = 1; i < nums.size(); i++ )
    {
        if( nums[i] >= mx )
        {
            mx = max( mx, nums[i] );
        }
        else if( nums[i] < mx )
            cnt++;
        else
        {
            mx = max( mx, nums[i] );
        }
    }

    if( cnt >= 2 )
        return false;
    return true;

}
/*
int main()
{
	vector<int>nums = { 4,2,3 };
	auto ans = Solve( nums );
    cout << ans;
}
*/