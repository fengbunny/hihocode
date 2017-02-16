#include <iostream>
#include <vector>
using namespace std;

long merge(vector<int>& nums, int low, int mid, int high)
{
	cout << low << " " << high << endl;
	vector<int> tmp;
	int i = low, j = mid + 1;
	long count = 0;

	while(i <= mid && j <= high)
	{
		if(nums[j] < nums[i])
		{
			count += j - i;
			tmp.push_back(nums[j++]);
		}
		else
		{
			tmp.push_back(nums[i++]);
		}
	}
	while(i <= mid)
	{
		tmp.push_back(nums[i++]);
	}
	while(j <= high)
		tmp.push_back(nums[j++]);

	for(i = low; i <=high; i++)
		nums[i] = tmp[i - low];

	cout << count << endl;
	return count;
}
long merge_sort(vector<int>& nums, int low, int high)
{
	if(high - low < 1) return 0;

	int mid = (low + high) >> 1;
	return (merge_sort(nums, low, mid) 
		+ merge_sort(nums, mid + 1, high) 
		+ merge(nums, low, mid, high));

}

int main()
{
	long N;
	vector<int> nums;

	cin >> N;
	for(int i = 0, tmp; i < N; i++)
	{
		cin >> tmp;
		nums.push_back(tmp);
	}

	long count = merge_sort(nums, 0, N-1);

	cout << count << endl;
	return 0;
}