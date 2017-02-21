#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool exist_substring(vector<vector<int>>& ilcount, vector<int>& lcount, int len, int K)
{
	for(int i = 0; i + len <= ilcount.size(); i++)
	{
		for(int l = 0; l < 26; l++)
		{
			if(lcount[l] >= len && ilcount[i + len][l] - ilcount[i][l] + K >= len)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int K;
	string str;

	cin >> K >> str;
	
	vector<int> lcount(26, 0);
	vector<vector<int>> ilcount;
	vector<int> tmp(26, 0);
	ilcount.push_back(tmp);

	for(int i = 0; i < str.length(); i++)
	{
		int l = (int)(str[i] -'a');
		lcount[l]++;
		vector<int> tmp = ilcount[i];
		tmp[l]++;
		ilcount.push_back(tmp);
	}

	int low = 1, high = str.length(), mid;
	while(low < high)
	{
		mid = high - low == 1 ? high : (low + high) >> 1;
		if(!exist_substring(ilcount, lcount, mid, K))
			high = mid - 1;
		else low = mid;
	}

	cout << low << endl;
	return low;
}