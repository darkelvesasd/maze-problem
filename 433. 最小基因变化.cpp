class Solution {
public:
    char s[4] = {'A','C','G','T'};
int minMutation(string startGene, string endGene, vector<string>& bank) {
	int len = startGene.length();
	unordered_set<string> hash;
	unordered_set<string> hash1;
	int count = -1;
	queue<string>q;
	for (auto a : bank)
	{
		hash.emplace(a);
	}
	q.emplace(startGene);
	hash1.emplace(startGene);
	while (!q.empty())
	{
		int sz = q.size();
		count++;
		for (int i=0;i<sz;i++)
		{
			string st = q.front();
			q.pop();
			if (st==endGene)
			{
				return count;
			}
			for (int k=0;k<len;k++)
			{
				for (int j = 0; j < 4; j++)
				{
					string stt = st;
					stt[k] = s[j];
					if (hash.count(stt) &&! hash1.count(stt))
					{
						hash1.emplace(stt);
						q.emplace(stt);
					}
				}
			}
		}
	}
	return -1;
}
};
