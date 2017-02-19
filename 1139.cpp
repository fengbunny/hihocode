#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	return a.second < b.second;
}

bool bfs(vector<vector<pair<int, int> > >& edges, int w_bound, int k_bound, int s, int t)
{
	queue<int> q;
	vector<int> visited(edges.size(), -1);
   
	q.push(s);
	visited[s] = 0;

	while(!q.empty())
	{
		// cout << "yes " << endl;
		int u = q.front();
		q.pop();

		if(u == t)
			return visited[u] <= k_bound;

		// for(auto p : edges[u])
		// {
		// 	cout << p.first << p.second << " ";
		// }

		for(auto p : edges[u])
		{
			if(p.second <= w_bound && visited[p.first] == -1)
			{
				visited[p.first] = visited[u] + 1;
				q.push(p.first);
				// cout << p.first << visited[p.first] << endl;
			}
		}
	}

	return false;
}

int main()
{
	int N, M, K, T;
	cin >> N >> M >> K >> T;

	vector<vector<pair<int, int> > > edges(N+1);
	// set<int> weights;

	int u, v, w;
	while(cin >> u && cin >> v && cin >> w)
	{
		edges[u].push_back(make_pair(v, w));
		edges[v].push_back(make_pair(u, w));
		// weights.push_back(w);
	}

	int low = 1, high = 1000000;
	bool flag =false;
	while(low < high)
	{
		// cout << low << " " << high << endl;
 		int mid = (low + high) >> 1;
		if(bfs(edges, mid, K, 1, T))
		{
			flag = true；
			high = mid;
		}
		else
			low = mid + 1;
	}

	if(flag) cout << low << endl;
	else cout << -1 << endl;

	return 0;
}