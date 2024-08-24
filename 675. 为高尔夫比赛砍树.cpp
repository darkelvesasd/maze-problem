class Solution {
public:
   typedef pair<int, int>PII;
int mx[4] = { -1,1,0,0 };
int my[4] = { 0,0,-1,1 };
pair<int,PII> bfs(int end,pair<int,int> pt, vector<vector<int>>& forest)
{
	int m = forest.size();
	int n = forest[0].size();
	if (forest[pt.first][pt.second] == end)
	{
		return { 0,{0,0} };
	}
	int ret = 0;
	queue<PII>q;
	q.emplace(pt);
	vector<vector<bool>>vb(m, vector<bool>(n));
	vb[pt.first][pt.second] = true;
	while (!q.empty())
	{
		int sz = q.size();
		ret++;
		for (int j = 0; j < sz; j++)
		{
			PII t = q.front();
			q.pop();
			for (int k = 0; k < 4; k++)
			{
				int x = mx[k] + t.first;
				int y = my[k] + t.second;
				if (x >= 0 && x < m && y >= 0 && y < n && vb[x][y] == false && forest[x][y])
				{
					if (forest[x][y] == end)
					{
						return { ret, {x,y} };
					}
					vb[x][y] = true;
					q.emplace(PII(x,y));
				}
			}
		}
	}
	return { -1,{-1,-1} };
}
int cutOffTree(vector<vector<int>>& forest) {
	int m = forest.size();
	int n = forest[0].size();
	vector<int>v;
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j=0;j<n;j++)
		{
			if (forest[i][j])
			{
				v.emplace_back(forest[i][j]);
			}
		}
	}
	sort(v.begin(),v.end());
	PII pt(0, 0);
	int i = 0;
	if (v[i] == 1)
	{
		i++;
	}
	int ret = 0;
	for (; i < v.size(); i++)
	{
		pair<int,PII>ppt=	bfs(v[i],pt,forest);
		pt = ppt.second;
		ret = ppt.first;
		if (ret == -1)
		{
			return -1;
		}
		sum += ret;
	}
	return sum==0?-1:sum;
}
};
