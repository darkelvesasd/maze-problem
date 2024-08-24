class Solution {
public:
typedef pair<int,int> PII;
int mx[4] = { 0,0,1,-1 };
int my[4] = { -1,1,0,0 };
int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
	PII tv(entrance[0], entrance[1]);
	int m = maze.size();
	int n = maze[0].size();
	int count = 0;
	vector<vector<bool>>b(m,vector<bool>(n));
	queue<PII>q;
	q.emplace(tv);
	b[tv.first][ tv.second] = true;
	while (!q.empty())
	{
		int sz = q.size();
		count++;
		for(int k=0;k<sz;k++)
		{ 
			PII t = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int x = t.first + mx[i];
				int y = t.second + my[i];
				if (x >= 0 && x < m && y >= 0 && y < n && b[x][y] == false)
				{
					b[x][y] = true;
					if (maze[x][y] == '.')
					{
						if (x != m - 1 && x != 0 && y != n - 1 && y != 0)
						{
							q.emplace(PII(x, y));
						}
						else
						{
							return count;
						}
					}
				}
			}
		}
	}
	return -1;
}
};
