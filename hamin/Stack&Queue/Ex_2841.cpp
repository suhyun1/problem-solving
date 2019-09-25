#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;

	stack<int> st[6];
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;

		while (!st[a].empty() && st[a].top() > b)
		{
			st[a].pop();
			cnt++;
		}
		if (st[a].empty())
		{
			st[a].push(b);
			cnt++;
			continue;
		}
		if (st[a].top() < b)
		{
			st[a].push(b);
			cnt++;
		}
	}
	cout << cnt << endl;

    return 0;
}
