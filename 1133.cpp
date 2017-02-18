#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, k, tmp;
	vector<int> nums;

	cin >> N >> k;
	while(cin >> tmp) nums.push_back(tmp);


	int low = 0, high = N - 1, mid = -1;
	while(mid != k - 1)
	{
		mid = (low + high) >> 1;

		int i = low, j = high;

		while(i < j)
		{
			while(i < j && nums[i] <= nums[mid]) i++;
			while(j > i && nums[j] >= nums[mid]) j--;
			if(i < j) swap(nums[i], nums[j]);
		}

		if(mid > i) 
		{
			swap(nums[mid], nums[i]);
			mid = i;
		}
		else if(mid < i) 
		{
			swap(nums[mid], nums[i - 1]);
			mid = i - 1;
		}

		if(mid > k - 1)  high = mid;
		if(mid < k - 1) low = mid;
	}

	cout << nums[mid] << endl;
	return 0;
}