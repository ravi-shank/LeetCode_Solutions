#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> InsertInterval( vector<vector<int>>& intervals, vector<int>& newInterval )
{
	vector<vector<int>>updatedIntervals;
	if( intervals.size() <= 0 )
	{
		updatedIntervals.push_back( newInterval );
		return updatedIntervals;
	}
	int low = newInterval[0];
	int high = newInterval[1];

	if( high < intervals[0][0])
	{
		updatedIntervals.push_back( newInterval );
		for( auto intv : intervals )
			updatedIntervals.push_back( intv );
		return updatedIntervals;
	}
	if( low > intervals[intervals.size() - 1][1] )
	{
		for( auto intv : intervals )
			updatedIntervals.push_back( intv );
		updatedIntervals.push_back( newInterval );
		return updatedIntervals;
	}
	// find the merging interval
	int lowIdx = -1, highIdx = -1;
	int mergeLow = low , mergeHigh = high;
	bool isMerged = false;
	int intvAppendIdx = -1;
	// { {4,6}, {9,12}, {17,19}, {21,23} }
	// {14,24}
	for( int i = 0; i < intervals.size(); i++ )
	{
		if( intervals[i][1] < low )
		{
			updatedIntervals.push_back( intervals[i] );
		}
		else
		{
			mergeLow = min( intervals[i][0], low );
			int j;
			for( j = i; j < intervals.size(); j++ )
			{
				if( intervals[j][1] < high )
					continue;
				else
				{
					if( high < intervals[j][0] )
					{
						mergeHigh = high;
						intvAppendIdx = j;
					}
					else
					{
						mergeHigh = max( high, intervals[j][1] );
						intvAppendIdx = j + 1;
					}
					isMerged = true;
					break;
				}
			}
			if( isMerged or j >= intervals.size() )
			{
				break;
			}
		}
	}
	updatedIntervals.push_back( vector<int>{mergeLow, mergeHigh} );
	for( int i = intvAppendIdx; i < intervals.size(); i++ )
		updatedIntervals.push_back( intervals[i] );

	return updatedIntervals;
}
/*
int main()
{
	vector<vector<int>>intervals = { {4,6}, {9,12}, {17,19}, {21,23} };
	vector<int>newInterval = { 9,19};
	vector<vector<int>>updatedIntervals = InsertInterval( intervals, newInterval );
	for( int i = 0; i < updatedIntervals.size(); i++ )
	{
		cout << updatedIntervals[i][0] << "," << updatedIntervals[i][1] << endl;
	}
}
*/