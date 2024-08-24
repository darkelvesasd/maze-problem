class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	int len = beginWord.size();
	unordered_set<string>hash(wordList.begin(),wordList.end());
	unordered_set<string>hash1;
	queue<string>q;
	int count = 0;
	q.emplace(beginWord);
	while (!q.empty())
	{
		int sz = q.size();
		count++;
		for (int i=0;i<sz;i++)
		{
			string t = q.front();
			q.pop();
			for (int j = 0; j < len; j++)
			{
				string st = t;
				for (int k = 0; k < 26; k++)
				{
					st[j] = k + 'a';
					if (hash.count(st) && !hash1.count(st))
					{
						if (endWord == st)
						{
							return ++count;
						}
						hash1.emplace(st);
						q.emplace(st);
					}
				}
			}
		}
	}
	return 0;
}
};
