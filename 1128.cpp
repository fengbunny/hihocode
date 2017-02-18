#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, K, tmp, count = 1;
	bool flag = false;

	cin >> N >> K;
	while(cin >> tmp)
	{
		if(tmp == K) flag = true;
		else if(tmp < K) count++;
	}

	if(flag) 
	    cout << count << endl;
	else 
	    cout << -1 << endl;
	    
	return 0;
}