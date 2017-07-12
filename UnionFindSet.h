#include<vector>
using namespace std;

class UnionFindSet
{
public:
	UnionFindSet(size_t size)
	{
		s.resize(size, -1);
	}
	void Union(int x1, int x2)//归并
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		if (root1 != root2)
		{
			s[root1] += s[root2];
			s[root2] = root1;
		}
	}

	int FindRoot(int x1)
	{
		int root = x1;
		while (s[root] >= 0)
		{
			root = s[root];
		}
		return root;
	}

	bool IsSameSet(int x1, int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	size_t Setsize()
	{
		size_t count = 0;
		for (size_t idx = 1; idx < s.size(); ++idx)
		{
			if (s[idx]<0)
				count++;
		}
		return count;
	}

private:
	std::vector<int> s;
};
