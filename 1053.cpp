#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef pair<int, int> point;
vector<point> points(100010);
int T, N, R, X, Y;

int main()
{
	cin >> T;
	while(T--)
	{
		int low, high = 0, mid;
		long maxP = 0;

		cin >> N >> R;
		for(int i = 0; i < N; i++) 
		{
			cin >> X >> Y;
			if(Y > high) high = Y;
			maxP += Y;
			points[i].first = X;
			points[i].second = Y;
		}
		sort(points.begin(), points.begin() + N);

		low = maxP / N;
		while(low < high)
		{
			mid =(low + high) >> 1;
			deque<point> less, greater;
			bool flag = true;

			for(int i = 0; i < N && flag; i++)
			{
				point p = points[i];
				int count = 0;

				deque<point>::iterator lit = less.begin();
				// cout << "less : ";
				// for(lit; lit != less.end(); lit++)
				// 	cout << lit -> first << "," << lit -> second << " ";
				// cout << endl;
				while((lit = less.begin()) != less.end())
				{
					if(lit -> first + R < p.first) less.pop_front();
					else if(lit -> second <= p.second)
					{
						p.second -= lit -> second;
						less.pop_front();
					}
					else
					{
						lit -> second -= p.second;
						p.second = 0;
						break;
					}
				}

				deque<point>::iterator git = greater.begin();
				// cout << "greater : ";
				// for(git; git != greater.end(); git++)
				// 	cout << git -> first << "," << git -> second << " ";
				// cout << endl;
				while((git = greater.begin())!= greater.end())
				{
					if(git -> first + R < p.first)
					{
						flag = false;
						break;					
					}
					else if(git -> second + count <= mid)
					{
						count += git -> second;
						greater.pop_front();
					}
					else
					{
						git -> second -= mid - count;
						count = mid;
						break;
					}
				}

				if(p.second + count > mid) greater.push_back(point(p.first, p.second + count - mid));
				if(p.second + count < mid) less.push_back(point(p.first, mid - (p.second + count)));


			}

			if(flag && greater.empty())
				high = mid;
			else 
				low = mid + 1;
		}

		cout << low << endl;
	}
	return 0;
}