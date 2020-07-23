#include<bits/stdc++.h>
using namespace std;


    // candidate= [2,3,6,7]
    // curList=[2,2,2]
    // curSum = 6
    // target = 7
    // start = 1
    // curVal = 6
    void findCombinationSum( int start, int curSum, int target, vector<int>& candidates, vector<int>& curList, vector<vector<int>>& ans )
    {
        if( curSum > target )
            return;
        if( curSum == target )
        {
            ans.push_back( curList );
            return;
        }
        

        for( int i = start; i < candidates.size(); i++ )
        {
            curList.push_back( candidates[i] );
            curSum += candidates[i];
            findCombinationSum( i, curSum, target, candidates, curList, ans );
            curList.pop_back();
            curSum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum( vector<int>& candidates, int target )
    {

        vector<vector<int>>ans;
        vector<int>curList;
        findCombinationSum( 0, 0, target, candidates, curList, ans );
        return ans;
    }
/*
int main()
{
    vector<int>candidates = { 2,3,6,7 };
    int sum = 19;
    vector<int>uniqueNums;
    map<int, int>mp;
    for( int num : candidates )
    {
        if( mp[num] == 0 )
        {
            uniqueNums.push_back( num );
            mp[num]++;
        }
    }
    //sort( uniqueNums.begin(), uniqueNums.end() );
    vector<vector<int>>sumList = combinationSum( uniqueNums, sum );
    for( int i = 0; i < sumList.size(); i++ )
    {
        for( int j = 0; j < sumList[i].size(); j++ )
        {
            cout << sumList[i][j] << " ";
        }
        cout << endl;
    }

}
*/